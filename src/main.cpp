// Kidj V1.0

#include <Audio.h>

#include "audio_system.h"
#include "battery.h"
#include "button.h"
#include "led.h"
#include "low_power.h"

#define DEBUG_PIN 39

void setup() {
  Serial.begin(115200);
  Serial.println("Bonjour KiDj");
  pinMode(DEBUG_PIN, OUTPUT);
  init_charger();
  init_fuel();
  init_led();
  init_volume(0.8);
  init_button();
  init_mixer();
  init_audio();
  init_scratch();
  init_drum();
  Serial.println("go to loop");
}

float value;
uint32_t time_start, time_function;
uint8_t state_amplifier;
elapsedMillis timeout_printf, timeout_amp;
#define DEFAULT_TIMEOUT 10000
#define TIMEOUT_SLEEP_TIME 20000

float rms_out_f; 

void loop() {


    //teensy seul : 80mA a 600MHz
    //teensy seul : 47mA a 60MHz
    //teensy + ampli 90mA
    //test low power
    //delay(2000);
    

    digitalToggle(DEBUG_PIN);

    
    update_button();
    update_vumetre(); 
    update_effect();
    update_animation();
    update_scratch();
    
    if (timeout_sleep > TIMEOUT_SLEEP_TIME)
      goto_sleep();
    
    time_function = micros() - time_start;
    if (timeout_printf > 1000) {
        timeout_printf = 0;
        Serial.print("Memory usage :");
        Serial.print(AudioMemoryUsageMax());
        Serial.print(" Time function :");
        Serial.print(time_function);
        Serial.println("us");
        update_fuel(1);
    } 

    if (rms_out.available() && (timeout_amp > DEFAULT_TIMEOUT)) {
        value = rms_out.read() * 10.0;
        if(value > 0.0) {
            timeout_amp = 0;
            if (!state_amplifier)
            {
                digitalWrite(33, 1); //enable amplifier
                Serial.println("RMS >0, start amplifier : ");
                Serial.printf("rms2 :");
                Serial.println(value);
                state_amplifier = true;
            }
        }
        else {
            if (state_amplifier)
            {
                digitalWrite(33, 0); //disable amplifier
                Serial.println("RMS low, shutdown amplifier : ");
                Serial.printf("rms2 :");
                Serial.println(value);
                state_amplifier = false;
            }
        }
    }
    time_start = micros();
}
