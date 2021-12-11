// Kidj V1.0
#include <Audio.h>

#include "audio_system.h"
#include "battery.h"
#include "button.h"
#include "led.h"
#include "low_power.h"
#include "debug.h"

#define DEBUG_PIN 39
#define DEFAULT_TIMEOUT 10000
#define TIMEOUT_SLEEP_TIME 20000

void setup() {
    digitalWrite(38, false);
    pinMode(38, OUTPUT_OPENDRAIN);
    #ifdef DEBUG
    Serial.begin(115200);
    #endif
    DEBUG_PRINTLN("Bonjour KiDj");
    pinMode(DEBUG_PIN, OUTPUT);
    init_audio();
    init_led();
    init_volume(0.8);
    init_button();
    init_mixer();
    init_drum();
    DEBUG_PRINTLN("go to loop");
}

float value;
uint32_t time_start, time_function;
uint8_t state_amplifier;
elapsedMillis timeout_printf, timeout_amp;
float rms_out_f; 


void loop() 
{

    //teensy seul : 80mA a 600MHz
    //teensy seul : 47mA a 60MHz
    //teensy + ampli 90mA
    //test low power

       
    update_button();
    //update_vumetre(); 
    update_effect();
    update_animation();
    
    if (timeout_sleep > TIMEOUT_SLEEP_TIME)
    {
        goto_sleep();
        timeout_sleep = 0;
    }

    
    time_function = micros() - time_start;

    if (timeout_printf > 1000) 
    {
        timeout_printf = 0;
        DEBUG_PRINT("timeout to sleep :");
        DEBUG_PRINT(timeout_sleep);
        if (rms_out.available())
        {
            DEBUG_PRINT(" RMS_OUT : ");
            DEBUG_PRINT(rms_out.read());
        }
        DEBUG_PRINT(" Memory usage :");
        DEBUG_PRINT(AudioMemoryUsageMax());
        DEBUG_PRINT(" Time function :");
        DEBUG_PRINT(time_function);
        DEBUG_PRINTLN("us");
    } 

    time_start = micros();
}
