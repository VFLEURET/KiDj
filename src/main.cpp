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
  init_volume(0.8);
  init_button();
  init_mixer();
  init_audio();
  init_scratch();
}

float value;

uint32_t time_start, time_function;
uint8_t state_amplifier;

elapsedMillis timeout_printf, timeout_amp;

#define DEFAULT_TIMEOUT 10000


float rms_out_f; 
float rms1_f;
float peak_out_f;

void loop() {
    digitalToggle(DEBUG_PIN);

    time_start = micros();
    update_button();
    update_vumetre(); 
    update_effect();
    update_animation();
    
    time_function = micros() - time_start;

    if (timeout_printf > 1000) {
        timeout_printf = 0;
        Serial.print("Memory usage :");
        Serial.print(AudioMemoryUsageMax());
        Serial.print(" Time function :");
        Serial.print(time_function);
        Serial.println("us");
        //update_fuel(0);
    } 
    
//    if(rms_out.available() && rms1.available()&& timeout_amp > DEFAULT_TIMEOUT )
//    {
//        timeout_amp = 0;
//        rms_out_f = rms_out.read() * 10.0;
//        rms1_f = rms1.read() * 10.0;
//        Serial.print("rms out : ");
//        Serial.print(rms_out_f);
//        Serial.print("rms 1 : ");
//        Serial.println(rms1_f);
//    }

    if (rms_out.available() && (timeout_amp > DEFAULT_TIMEOUT)) {
        value = rms_out.read() * 10.0;
        if(value > 0.0) {
            timeout_amp = 0;
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
        Serial.printf("rms2 :");
        Serial.println(value);
    }
  
}
