#include "audio_system.h"
#include "debug.h"

elapsedMillis timeout_effect;

#define DRUM1 3
#define DRUM2 2
#define DRUM3 1 

void update_effect(void)
{
    static uint16_t previous_knob1 = 0xFFFF, previous_knob2 = 0xFFFF;
    static uint16_t lpf_knob1 = 0, lpf_knob2 = 0;
    uint16_t knob;
    float feedback;
    //BitCrusher
    int current_CrushBits = 16; //this defaults to passthrough.
    int current_SampleRate = 44100; // this defaults to passthrough.

    if(timeout_effect > 100)
    {
        knob = analogRead(A17);

        lpf_knob1 = lpf_knob1 + ((knob - lpf_knob1) >> 2); //filter 
        
        if (lpf_knob1 < 10) lpf_knob1 = 0;

        if(lpf_knob1 != previous_knob1) {
            feedback = lpf_knob1 / 1050.0;
            DEBUG_PRINTF("Delay %d\r\n", lpf_knob1);
            mixer9.gain(3, feedback);
            previous_knob1 = lpf_knob1;
        }

        knob = analogRead(A16);
        lpf_knob2 = lpf_knob2 + ((knob - lpf_knob2) >> 2); //filter
           
        if(lpf_knob2 != previous_knob2) {
            if (lpf_knob2 < 10)
                current_SampleRate = 44100;
            else {
                current_SampleRate = (uint16_t)(-1.65 * lpf_knob2 + 3600);
            }
            
            DEBUG_PRINTF("reverd %d %d\r\n", lpf_knob2, current_SampleRate);
            bitcrusher1.sampleRate(current_SampleRate);
            previous_knob2 = lpf_knob2;
        }
        timeout_effect = 0;
    }
}

void DRUM1_irq(void)
{
    detachInterrupt(DRUM1);
    digitalWrite(39, 1);
    playMemDrum1.play(AudioSampleSnare);
    attachInterrupt(DRUM1, DRUM1_irq, RISING);
    timeout_sleep = 0;
}

void DRUM2_irq(void)
{
    detachInterrupt(DRUM2);
    digitalWrite(39, 1);
    playMemDrum2.play(AudioSampleHihat);
    attachInterrupt(DRUM2, DRUM2_irq, RISING);
    timeout_sleep = 0;
}

void DRUM3_irq(void)
{
    detachInterrupt(DRUM3);
    digitalWrite(39, 1);
    playMemDrum3.play(AudioSampleTomtom);   
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
