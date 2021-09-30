// Kidj V1.0


#include <Audio.h>
#include "button.h"
#include "led.h"
#include "audio_system.h"
#include <battery.h>

#define DEBUG_PIN 39

void setup() {
  Serial.begin(115200);
  Serial.println("Bonjour KiDj");

  pinMode(DEBUG_PIN, OUTPUT);
  //init_charger();
  //init_fuel();
  //init_led();
  init_volume(0.5);
  init_button();
  init_mixer();
  init_audio();
}

uint32_t current_millis, previous_millis;
float value;

uint32_t time_start, time_function;

void loop() {
    digitalToggle(DEBUG_PIN);

    time_start = micros();
    update_button();
    update_vumetre(); 
    update_effect();
    //update_animation();
    
    time_function = micros() - time_start;

    current_millis = millis();
    if (current_millis > (previous_millis + 1000)) {
        Serial.print("Memory usage :");
        Serial.print(AudioMemoryUsageMax());
        Serial.print(" Time function :");
        Serial.print(time_function);
        Serial.println("us");
        update_fuel(0);
        //playMemDrum1.play(AudioSampleTomtom);
        //delay(300);
        //playMemDrum2.play(AudioSampleHihat);
        previous_millis = current_millis;
    } 
    if (rms2.available()) {
        value = rms2.read();
        if(value > 0.8)
          Serial.println(value);
    }
  
}
