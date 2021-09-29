#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

#include "../audio/AudioSampleSnare.h"        // http://www.freesound.org/people/KEVOY/sounds/82583/
#include "../audio/AudioSampleTomtom.h"       // http://www.freesound.org/people/zgump/sounds/86334/
#include "../audio/AudioSampleHihat.h"        // http://www.freesound.org/people/mhc/sounds/102790/
#include "../audio/AudioSampleKick.h"         // http://www.freesound.org/people/DWSD/sounds/171104/
#include "../audio/AudioSampleGong.h"         // http://www.freesound.org/people/juskiddink/sounds/86773/
#include "../audio/AudioSampleCashregister.h" // http://www.freesound.org/people/kiddpark/sounds/201159/

void init_mixer(void);
void init_audio(void);
void update_vumetre(void);
void update_effect(void);




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
AudioAmplifier           Volume;           //xy=1712.36669921875,618.3667297363281
AudioOutputI2S           i2s1;           //xy=1837.333251953125,617.3333435058594
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
AudioConnection          patchCord31(reverb, 0, mixer9, 0);
AudioConnection          patchCord32(delay1, 0, mixer9, 3);
AudioConnection          patchCord33(delay1, 0, Volume, 0);
AudioConnection          patchCord34(mixer9, delay1);
AudioConnection          patchCord35(Volume, 0, i2s1, 0);
AudioConnection          patchCord36(Volume, 0, i2s1, 1);
// GUItool: end automatically generated code


#endif