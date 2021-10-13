#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "audio_system.h"

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=170,20
AudioPlayMemory          playMem7; //xy=170,244
AudioPlayMemory          playMem2; //xy=171,58
AudioPlayMemory          playMem3; //xy=171,97
AudioPlayMemory          playMem4; //xy=171,133
AudioPlayMemory          playMem5; //xy=171,170
AudioPlayMemory          playMem12; //xy=170,431
AudioPlayMemory          playMem10; //xy=171,357
AudioPlayMemory          playMem14; //xy=171,505
AudioPlayMemory          playMem9; //xy=172,321
AudioPlayMemory          playMem6; //xy=173,208
AudioPlayMemory          playMemDrum3; //xy=171,724
AudioPlayMemory          playMemDrum1; //xy=172,651
AudioPlayMemory          playMemDrum2; //xy=172,689
AudioPlayMemory          playMem8; //xy=174,282
AudioPlayMemory          playMem15; //xy=174,542
AudioPlayMemory          playMem11; //xy=177,395
AudioPlayMemory          playMem13; //xy=178,469
AudioMixer4              mixer6; //xy=432,686
AudioMixer4              mixer5; //xy=437,504
AudioMixer4              mixer4; //xy=438,376
AudioMixer4              mixer3; //xy=441,217
AudioMixer4              mixer2;         //xy=443,56
AudioInputAnalog         adc_Micro;           //xy=487.9999694824219,1022
AudioAmplifier           amp_Micro;           //xy=630,1023
AudioMixer4              mixer7; //xy=653,284
AudioFilterBiquad        biquad_Micro;        //xy=784,1023
AudioMixer4              mixer8; //xy=861,416
AudioMixer4              mixer1;         //xy=1116.333251953125,687.3333435058594
AudioEffectReverb        reverb;        //xy=1277.36669921875,606.3667297363281
AudioAnalyzeRMS          rms1;           //xy=1277.333251953125,941.3333740234375
AudioEffectDelay         delay1;         //xy=1490.36669921875,779.36669921875
AudioMixer4              mixer9; //xy=1491.36669921875,614.36669921875
AudioFilterBiquad        biquad_out;        //xy=1640.0999755859375,766.0999450683594
AudioAmplifier           Volume;           //xy=1770.36669921875,764.3666687011719
AudioOutputI2S           i2s_out;           //xy=1936.333251953125,739.3333435058594
AudioAnalyzeRMS          rms_out; //xy=1939.36669921875,775.3666381835938
AudioConnection          patchCord1(playMem1, 0, mixer2, 0);
AudioConnection          patchCord2(playMem7, 0, mixer3, 2);
AudioConnection          patchCord3(playMem2, 0, mixer2, 1);
AudioConnection          patchCord4(playMem3, 0, mixer2, 2);
AudioConnection          patchCord5(playMem4, 0, mixer2, 3);
AudioConnection          patchCord6(playMem5, 0, mixer3, 0);
AudioConnection          patchCord7(playMem12, 0, mixer4, 3);
AudioConnection          patchCord8(playMem10, 0, mixer4, 1);
AudioConnection          patchCord9(playMem14, 0, mixer5, 1);
AudioConnection          patchCord10(playMem9, 0, mixer4, 0);
AudioConnection          patchCord11(playMem6, 0, mixer3, 1);
AudioConnection          patchCord12(playMemDrum3, 0, mixer6, 2);
AudioConnection          patchCord13(playMemDrum1, 0, mixer6, 0);
AudioConnection          patchCord14(playMemDrum2, 0, mixer6, 1);
AudioConnection          patchCord15(playMem8, 0, mixer3, 3);
AudioConnection          patchCord16(playMem15, 0, mixer5, 2);
AudioConnection          patchCord17(playMem11, 0, mixer4, 2);
AudioConnection          patchCord18(playMem13, 0, mixer5, 0);
AudioConnection          patchCord19(mixer6, 0, mixer8, 1);
AudioConnection          patchCord20(mixer5, 0, mixer7, 3);
AudioConnection          patchCord21(mixer4, 0, mixer7, 2);
AudioConnection          patchCord22(mixer3, 0, mixer7, 1);
AudioConnection          patchCord23(mixer2, 0, mixer7, 0);
AudioConnection          patchCord24(adc_Micro, amp_Micro);
AudioConnection          patchCord25(amp_Micro, biquad_Micro);
AudioConnection          patchCord26(mixer7, 0, mixer8, 0);
AudioConnection          patchCord27(biquad_Micro, 0, mixer1, 3);
AudioConnection          patchCord28(mixer8, 0, mixer1, 0);
AudioConnection          patchCord29(mixer1, rms1);
AudioConnection          patchCord30(mixer1, reverb);
AudioConnection          patchCord31(mixer1, 0, mixer9, 1);
AudioConnection          patchCord32(reverb, 0, mixer9, 0);
AudioConnection          patchCord33(delay1, 0, mixer9, 3);
AudioConnection          patchCord34(delay1, 0, biquad_out, 0);
AudioConnection          patchCord35(mixer9, delay1);
AudioConnection          patchCord36(biquad_out, Volume);
AudioConnection          patchCord37(Volume, 0, i2s_out, 0);
AudioConnection          patchCord38(Volume, 0, i2s_out, 1);
AudioConnection          patchCord39(Volume, rms_out);
// GUItool: end automatically generated code



void init_mixer(void)
{
    mixer1.gain(0, 0.8);
    mixer1.gain(1, 0.8);
    mixer1.gain(2, 0.8);
    mixer1.gain(3, 0.8);

    mixer2.gain(0, 0.8);
    mixer2.gain(1, 0.8);
    mixer2.gain(2, 0.8);
    mixer2.gain(3, 0.8);

    mixer3.gain(0, 0.8);
    mixer3.gain(1, 0.8);
    mixer3.gain(2, 0.8);
    mixer3.gain(3, 0.8);

    mixer4.gain(0, 0.8);
    mixer4.gain(1, 0.8);
    mixer4.gain(2, 0.8);
    mixer4.gain(3, 0.8);

    mixer5.gain(0, 0.8);
    mixer5.gain(1, 0.8);
    mixer5.gain(2, 0.8);
    mixer5.gain(3, 0.8);

    mixer6.gain(0, 0.8);
    mixer6.gain(1, 0.8);
    mixer6.gain(2, 0.8);
    mixer6.gain(3, 0.8);

    mixer7.gain(0, 0.8);
    mixer7.gain(1, 0.8);
    mixer7.gain(2, 0.8);
    mixer7.gain(3, 0.8);

    mixer8.gain(0, 0.8);
    mixer8.gain(1, 0.8);
    mixer8.gain(2, 0.8);
    mixer8.gain(3, 0.8);    

    mixer9.gain(0, 1);
    mixer9.gain(3, 0);
    delay1.delay(0, 400);

    biquad_out.setLowShelf(0, 300, 10, 0.5);

}

void init_audio(void) 
{
    AudioMemory(1000);
    pinMode(23, OUTPUT); //vumetre
    pinMode(33, OUTPUT); //sd ampli
    reverb.reverbTime(0);

    //enable amplifier
    digitalWrite(33, 1);
}

#define ENCA 16
#define ENCB 15
static bool encoder_inc(void);
static void encoderA(void);
static void encoderB(void);

float Vol_f;

void init_volume(float Vol_ext)
{
    Vol_f = Vol_ext;
    Volume.gain(Vol_f);
    pinMode(ENCA, INPUT_PULLUP);
    pinMode(ENCB, INPUT_PULLUP);
    attachInterrupt(ENCA, encoderA, CHANGE);
    attachInterrupt(ENCB, encoderB, CHANGE);
    Serial.print("Vol : ");
    Serial.println(Vol_f);
}

#define DEBOUNCE_ENC 3

elapsedMillis Timeout_encA, Timeout_encB;

static void encoderA(void) {
    bool change_value = false;;

    detachInterrupt(ENCA);
    detachInterrupt(ENCB);

    if (Timeout_encA > DEBOUNCE_ENC)
    {
        change_value = encoder_inc();
        Timeout_encA = 0;
    }

    attachInterrupt(ENCA, encoderA, CHANGE);
    attachInterrupt(ENCB, encoderB, CHANGE);

    if (change_value)
    {
        Volume.gain(Vol_f);
        Serial.print("New vol : ");
        Serial.println(Vol_f);
    }

}

static void encoderB(void) {
    bool change_value = false;

    detachInterrupt(ENCA);
    detachInterrupt(ENCB);

    if (Timeout_encB > DEBOUNCE_ENC)
    {
        change_value = encoder_inc();
        Timeout_encB = 0;
    }

    attachInterrupt(ENCA, encoderA, CHANGE);
    attachInterrupt(ENCB, encoderB, CHANGE);

    if (change_value)
    {
        Volume.gain(Vol_f);
        Serial.print("New vol : ");
        Serial.println(Vol_f);
    }
}

static bool encoder_inc(void) 
{
    static uint8_t current_encoder_logic_status, previous_encoder_logic_status;
    static int8_t inc_volume = 0;

    uint8_t A = digitalRead(ENCA);
    uint8_t B = digitalRead(ENCB);

    current_encoder_logic_status = A + (B << 1);
    switch(	(current_encoder_logic_status<<2) + previous_encoder_logic_status )	// décodage du code de gray
    {
        // ne rien faire
        default:
        case 0x00 :
        case 0x03 :
        case 0x05 :
        case 0x06 :
        case 0x09 :
        case 0x0A :
        case 0x0C :
        case 0x0F :
            break;

        // CW
        case 0x02 :
        case 0x04 :
        case 0x0B :
        case 0x0D :
                inc_volume --;
                break;

        // CCW
        case 0x01 :
        case 0x07 :
        case 0x08 :
        case 0x0E :
                inc_volume ++;
                break;

    }

    //Serial.printf("0x%02X 0x%02X 0x%02X\r\n", current_encoder_logic_status, previous_encoder_logic_status, (current_encoder_logic_status<<2) + previous_encoder_logic_status );

    previous_encoder_logic_status = current_encoder_logic_status;

    if ((inc_volume == 2) || (inc_volume == -2)) {
        Vol_f = Vol_f + (0.05 * inc_volume);
        if(Vol_f < 0)
            Vol_f = 0;
        if(Vol_f > 1.5)
            Vol_f = 1.5;   
        inc_volume = 0;
        return true;
    }
    return false;
}