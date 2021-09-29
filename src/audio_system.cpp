#include "audio_system.h"


void init_mixer(void)
{
    mixer1.gain(0, 0.4);
    mixer1.gain(1, 0.4);
    mixer1.gain(2, 0.4);
    mixer1.gain(3, 0.4);

    mixer2.gain(0, 0.4);
    mixer2.gain(1, 0.4);
    mixer2.gain(2, 0.4);
    mixer2.gain(3, 0.4);

    mixer3.gain(0, 0.4);
    mixer3.gain(1, 0.4);
    mixer3.gain(2, 0.4);
    mixer3.gain(3, 0.4);

    mixer4.gain(0, 0.4);
    mixer4.gain(1, 0.4);
    mixer4.gain(2, 0.4);
    mixer4.gain(3, 0.4);

    mixer5.gain(0, 0.4);
    mixer5.gain(1, 0.4);
    mixer5.gain(2, 0.4);
    mixer5.gain(3, 0.4);

    mixer6.gain(0, 0.4);
    mixer6.gain(1, 0.4);
    mixer6.gain(2, 0.4);
    mixer6.gain(3, 0.4);

    mixer7.gain(0, 0.4);
    mixer7.gain(1, 0.4);
    mixer7.gain(2, 0.4);
    mixer7.gain(3, 0.4);

    mixer8.gain(0, 0.4);
    mixer8.gain(1, 0.4);
    mixer8.gain(2, 0.4);
    mixer8.gain(3, 0.4);    

    mixer9.gain(0, 0.5);
    mixer9.gain(3, 0);
    delay1.delay(0, 400);
}

void init_audio(void) 
{
    AudioMemory(10);
    Volume.gain(0.5);
    pinMode(23, OUTPUT); //vumetre
    pinMode(33, OUTPUT); //sd ampli
    //enable amplifier
    digitalWrite(33, 1);
}