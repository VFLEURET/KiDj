#include "audio_system.h"

elapsedMillis timeout_effect;

#define DRUM1 3
#define DRUM2 2
#define DRUM3 1 

void update_effect(void)
{
    static float previous_delay, previous_reverb;

    if(timeout_effect > 200)
    {
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
        timeout_effect = 0;
    }
}

void DRUM1_irq(void)
{
    detachInterrupt(DRUM1);
    playMemDrum1.play(AudioSampleSnare);
    attachInterrupt(DRUM1, DRUM1_irq, RISING);
    timeout_sleep = 0;
}

void DRUM2_irq(void)
{
    detachInterrupt(DRUM2);
    playMemDrum2.play(AudioSampleTomtom);
    attachInterrupt(DRUM2, DRUM2_irq, RISING);
    timeout_sleep = 0;
}

void DRUM3_irq(void)
{
    detachInterrupt(DRUM3);
    playMemDrum3.play(AudioSampleHihat);   
    attachInterrupt(DRUM3, DRUM3_irq, RISING);
    timeout_sleep = 0;
}

void init_drum(void)
{
    pinMode(DRUM1, INPUT);
    pinMode(DRUM2, INPUT);
    pinMode(DRUM3, INPUT);
    attachInterrupt(DRUM1, DRUM1_irq, RISING);
    attachInterrupt(DRUM2, DRUM2_irq, RISING);
    attachInterrupt(DRUM3, DRUM3_irq, RISING);
}
