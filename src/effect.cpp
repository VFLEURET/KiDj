#include "audio_system.h"

void update_effect(void)
{
    int knob = analogRead(A17);
    if (knob < 10) knob = 0;
    float feedback = (float)knob / 1050.0;
    mixer9.gain(3, feedback);

    knob = analogRead(A16);
    if (knob < 10) knob = 0;
    feedback = (float)knob / 1050.0;
    reverb.reverbTime(feedback);
}