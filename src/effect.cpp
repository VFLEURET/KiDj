#include "audio_system.h"

void update_effect(void)
{
    static float previous_delay, previous_reverb;

    int knob = analogRead(A17);
    if (knob < 10) knob = 0;
    float feedback = (float)knob / 1050.0;
    feedback = 0.01;
    if(feedback != previous_delay) {
        mixer9.gain(3, feedback);
        Serial.printf("Delay %d\r\n", feedback);
        previous_delay = feedback;
    }

    knob = analogRead(A16);
    if (knob < 10) knob = 0;
    feedback = (float)knob / 1050.0;
    feedback = 0.01;
    if(feedback != previous_reverb) {
        reverb.reverbTime(feedback);
        Serial.printf("reverb %d\r\n", feedback);
        previous_reverb = feedback;
    }
}