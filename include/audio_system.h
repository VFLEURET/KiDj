#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>
#include "recorder.h"
#include "debug.h"
#include "low_power.h"

#include "audio/AudioSampleSnare.h"        // http://www.freesound.org/people/KEVOY/sounds/82583/
#include "audio/AudioSampleTomtom.h"       // http://www.freesound.org/people/zgump/sounds/86334/
#include "audio/AudioSampleHihat.h"        // http://www.freesound.org/people/mhc/sounds/102790/
#include "audio/AudioSampleKick.h"         // http://www.freesound.org/people/DWSD/sounds/171104/
#include "audio/AudioSampleGong.h"         // http://www.freesound.org/people/juskiddink/sounds/86773/
#include "audio/AudioSampleCashregister.h" // http://www.freesound.org/people/kiddpark/sounds/201159/

#include "audio/AudioSampleVache.h"
#include "audio/AudioSampleApplau.h"
#include "audio/AudioSampleChat.h"
#include "audio/AudioSampleChien.h"
#include "audio/AudioSampleSly.h"
#include "audio/AudioSampleXylo.h"
#include "audio/AudioSampleHacienda.h"
#include "audio/AudioSampleSka.h"
#include "audio/AudioSampleScratch.h"
#include "audio/AudioSampleHakuna.h"
#include "audio/AudioSampleScratch_inv.h"
#include "audio/AudioSampleScratch_norm.h"
#include "audio/AudioSampleMixedbrasshitwa.h"
#include "audio/AudioSampleNoelie.h"
#include "audio/AudioSampleDj.h"
#include "audio/AudioSampleAnna.h"
#include "audio/AudioSamplePiano.h"

void init_mixer(void);
void init_audio(void);
void update_vumetre(void);
void update_effect(void);
void init_drum(void);
void update_micro(void);
void init_volume(float Vol_ext);

void init_scratch(void);
void update_scratch(void);
bool sample_play(void);
extern elapsedMillis timeout_sleep; 

extern AudioPlayMemory          playMem1;       //xy=170,20
extern AudioPlayMemory          playMem7; //xy=170,244
extern AudioPlayMemory          playMem2; //xy=171,58
extern AudioPlayMemory          playMem3; //xy=171,97
extern AudioPlayMemory          playMem4; //xy=171,133
extern AudioPlayMemory          playMem5; //xy=171,170
extern AudioPlayMemory          playMem12; //xy=170,431
extern AudioPlayMemory          playMem10; //xy=171,357
extern AudioPlayMemory          playMem14; //xy=171,505
extern AudioPlayMemory          playMem9; //xy=172,321
extern AudioPlayMemory          playMem6; //xy=173,208
extern AudioPlayMemory          playMemDrum3; //xy=171,724
extern AudioPlayMemory          playMemDrum1; //xy=172,651
extern AudioPlayMemory          playMemDrum2; //xy=172,689
extern AudioPlayMemory          playMem8; //xy=174,282
extern AudioPlayMemory          playMem15; //xy=174,542
extern AudioPlayMemory          playMem11; //xy=177,395
extern AudioPlayMemory          playMem13; //xy=178,469
extern AudioPlayMemory          playMem16; 
extern AudioRecordQueue         record;
extern AudioMixer4              mixer6; //xy=432,686
extern AudioMixer4              mixer5; //xy=437,504
extern AudioMixer4              mixer4; //xy=438,376
extern AudioMixer4              mixer3; //xy=441,217
extern AudioMixer4              mixer2;         //xy=443,56
extern AudioInputAnalog         adc_Micro;           //xy=487.9999694824219,1022
extern AudioAmplifier           amp_Micro;           //xy=630,1023
extern AudioMixer4              mixer7; //xy=653,284
extern AudioFilterBiquad        biquad_Micro;        //xy=784,1023
extern AudioMixer4              mixer8; //xy=861,416
extern AudioMixer4              mixer1;         //xy=1116.333251953125,687.3333435058594
//extern AudioEffectReverb        reverb;        //xy=1277.36669921875,606.3667297363281
extern AudioAnalyzeRMS          rms1;           //xy=1277.333251953125,941.3333740234375
extern AudioEffectDelay         delay1;         //xy=1490.36669921875,779.36669921875
extern AudioMixer4              mixer9; //xy=1491.36669921875,614.36669921875
extern AudioAmplifier           Volume;           //xy=1660.36669921875,815.36669921875
extern AudioOutputI2S           i2s_out;           //xy=1826.333251953125,790.3333740234375
extern AudioAnalyzeRMS          rms_out; //xy=1827.36669921875,857.36669921875
extern AudioFilterBiquad        biquad_out;        //xy=1640.0999755859375,766.0999450683594
extern AudioEffectBitcrusher    bitcrusher1;
extern AudioPlaySdRaw           playSdRawRecord;     //xy=434,744
#endif
