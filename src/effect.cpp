#include "audio_system.h"

void update_effect(void)
{
    int knob = analogRead(A17);
    if (knob < 10) knob = 0;
    float feedback = (float)knob / 1050.0;
    feedback = 0.5;
    mixer9.gain(3, feedback);
    //Serial.printf("Delay %d\r\n", feedback);

    knob = analogRead(A16);
    if (knob < 10) knob = 0;
    feedback = (float)knob / 1050.0;
    reverb.reverbTime(feedback);
    //Serial.printf("reverb %d\r\n", feedback);
}