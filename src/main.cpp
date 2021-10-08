// Kidj V1.0

#include <Audio.h>

#include "audio_system.h"
#include "battery.h"
#include "button.h"
#include "led.h"

#define DEBUG_PIN 39

void setup() {
  Serial.begin(115200);
  Serial.println("Bonjour KiDj");

  pinMode(DEBUG_PIN, OUTPUT);
  //init_charger();
  //init_fuel();
  init_led();
  init_volume(0.5);
  init_button();
  init_mixer();
  init_audio();
  //init_scratch();
}

uint32_t current_millis, previous_millis;
float value;

uint32_t time_start, time_function;
uint32_t timeout_amp;

uint8_t state_amplifier;

#define DEFAULT_TIMEOUT 10000

void loop() {
    digitalToggle(DEBUG_PIN);

    time_start = micros();
    update_button();
    update_vumetre(); 
    update_effect();
    update_animation();
    
    time_function = micros() - time_start;

    current_millis = millis();
    if (current_millis > (previous_millis + 1000)) {
        Serial.print("Memory usage :");
        Serial.print(AudioMemoryUsageMax());
        Serial.print(" Time function :");
        Serial.print(time_function);
        Serial.println("us");
        //update_fuel(0);

        previous_millis = current_millis;
    } 
    
    if (rms2.available() && (millis() > timeout_amp)) {
        value = rms2.read();
        if(value > 0.0) {
            timeout_amp = DEFAULT_TIMEOUT + millis();
            if (!state_amplifier)
            {
                digitalWrite(33, 1); //enable amplifier
                Serial.println("RMS >0, start amplifier");
                state_amplifier = true;
            }
        }
        else {
            if (state_amplifier)
            {
                digitalWrite(33, 0); //disable amplifier
                Serial.println("RMS low, shutdown amplifier");
                state_amplifier = false;
            }
        }
        //Serial.println(value);
    }
  
}
