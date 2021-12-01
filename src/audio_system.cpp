#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "debug.h"

#include "audio_system.h"

elapsedMillis timeout_sleep; 

// GUItool: begin automatically generated code
AudioInputAnalog         adc_Micro(8);           //xy=156.99996948242188,793
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
AudioPlayMemory          playMem16; //xy=174.10000610351562,577.0999755859375
AudioPlayMemory          playMem11; //xy=177,395
AudioPlayMemory          playMem13; //xy=178,469
AudioAmplifier           amp_Micro;           //xy=299,794
AudioMixer4              mixer6; //xy=432,686
AudioPlaySdRaw           playSdRawRecord;     //xy=434,744
AudioMixer4              mixer5; //xy=437,504
AudioMixer4              mixer4; //xy=438,376
AudioMixer4              mixer3; //xy=441,217
AudioMixer4              mixer2;         //xy=443,56
AudioFilterBiquad        biquad_Micro;        //xy=453,794
AudioMixer4              mixer7; //xy=653,284
AudioAnalyzeRMS          rms_micro; //xy=706.5999755859375,863.0999755859375
AudioAnalyzePeak         peak_micro;          //xy=721,816
AudioMixer4              mixer1;         //xy=779.333251953125,564.3333740234375
AudioRecordQueue         record;         //xy=927,433
AudioAnalyzeRMS          rms1;           //xy=938.333251953125,628.3333740234375
AudioEffectBitcrusher    bitcrusher1;    //xy=953,493
AudioEffectDelay         delay1;         //xy=1086.36669921875,737.36669921875
AudioMixer4              mixer9; //xy=1087.36669921875,572.36669921875
AudioFilterBiquad        biquad_out;        //xy=1258.0999755859375,571.0999755859375
AudioAmplifier           Volume;           //xy=1388.36669921875,569.36669921875
AudioOutputI2S           i2s_out;           //xy=1554.333251953125,544.3333740234375
AudioAnalyzeRMS          rms_out; //xy=1557.36669921875,580.3666687011719
AudioConnection          patchCord1(adc_Micro, amp_Micro);
AudioConnection          patchCord2(playMem1, 0, mixer2, 0);
AudioConnection          patchCord3(playMem7, 0, mixer3, 2);
AudioConnection          patchCord4(playMem2, 0, mixer2, 1);
AudioConnection          patchCord5(playMem3, 0, mixer2, 2);
AudioConnection          patchCord6(playMem4, 0, mixer2, 3);
AudioConnection          patchCord7(playMem5, 0, mixer3, 0);
AudioConnection          patchCord8(playMem12, 0, mixer4, 3);
AudioConnection          patchCord9(playMem10, 0, mixer4, 1);
AudioConnection          patchCord10(playMem14, 0, mixer5, 1);
AudioConnection          patchCord11(playMem9, 0, mixer4, 0);
AudioConnection          patchCord12(playMem6, 0, mixer3, 1);
AudioConnection          patchCord13(playMemDrum3, 0, mixer6, 2);
AudioConnection          patchCord14(playMemDrum1, 0, mixer6, 0);
AudioConnection          patchCord15(playMemDrum2, 0, mixer6, 1);
AudioConnection          patchCord16(playMem8, 0, mixer3, 3);
AudioConnection          patchCord17(playMem15, 0, mixer5, 2);
AudioConnection          patchCord18(playMem16, 0, mixer5, 3);
AudioConnection          patchCord19(playMem11, 0, mixer4, 2);
AudioConnection          patchCord20(playMem13, 0, mixer5, 0);
AudioConnection          patchCord21(amp_Micro, biquad_Micro);
AudioConnection          patchCord22(mixer6, 0, mixer1, 1);
AudioConnection          patchCord23(playSdRawRecord, 0, mixer1, 2);
AudioConnection          patchCord24(mixer5, 0, mixer7, 3);
AudioConnection          patchCord25(mixer4, 0, mixer7, 2);
AudioConnection          patchCord26(mixer3, 0, mixer7, 1);
AudioConnection          patchCord27(mixer2, 0, mixer7, 0);
AudioConnection          patchCord28(biquad_Micro, 0, mixer1, 3);
AudioConnection          patchCord29(biquad_Micro, rms_micro);
AudioConnection          patchCord30(biquad_Micro, peak_micro);
AudioConnection          patchCord31(mixer7, 0, mixer1, 0);
AudioConnection          patchCord32(mixer1, rms1);
AudioConnection          patchCord33(mixer1, 0, mixer9, 1);
AudioConnection          patchCord34(mixer1, record);
AudioConnection          patchCord35(mixer1, bitcrusher1);
AudioConnection          patchCord36(bitcrusher1, 0, mixer9, 0);
AudioConnection          patchCord37(delay1, 0, mixer9, 3);
AudioConnection          patchCord38(mixer9, delay1);
AudioConnection          patchCord39(mixer9, biquad_out);
AudioConnection          patchCord40(biquad_out, Volume);
AudioConnection          patchCord41(Volume, 0, i2s_out, 0);
AudioConnection          patchCord42(Volume, 0, i2s_out, 1);
AudioConnection          patchCord43(Volume, rms_out);
// GUItool: end automatically generated code




void init_mixer(void)
{
    mixer1.gain(0, 0.8);
    mixer1.gain(1, 0.8);
    mixer1.gain(2, 0.8);

    mixer2.gain(0, 0.8);
    mixer2.gain(1, 2);
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
    mixer6.gain(3, 0);

    mixer7.gain(0, 0.8);
    mixer7.gain(1, 0.8);
    mixer7.gain(2, 0.8);
    mixer7.gain(3, 0.8); 

    mixer9.gain(0, 1);
    mixer9.gain(1, 0);
    mixer9.gain(2, 0);
    mixer9.gain(3, 0);
    delay1.delay(0, 400);

    biquad_out.setLowShelf(0, 300, 2, 0.5);

}

void init_audio(void) 
{
    AudioMemory(1000);
    pinMode(23, OUTPUT); //vumetre
    analogWrite(23, 0);
    pinMode(33, OUTPUT); //sd ampli
    digitalWrite(33, true);
    //reverb.reverbTime(0);
    bitcrusher1.sampleRate(44100);
    bitcrusher1.bits(16);
    pinMode(37, INPUT_PULLUP);
    amp_Micro.gain(0.0);
    mixer1.gain(3, 2);
    biquad_Micro.setHighpass(0, 200, 0.7);
    biquad_Micro.setHighpass(1, 200, 0.7);
    biquad_Micro.setHighpass(2, 200, 0.7);
    biquad_Micro.setLowpass(2, 8000, 0.7);
    biquad_Micro.setLowpass(3, 8000, 0.7);
}

elapsedMillis timeout_Micro;

void update_micro(void)
{
    static uint8_t previous_state = 4;
    uint8_t new_state;

    if(timeout_Micro < 100)
        return;

    new_state = digitalRead(37);

    if (new_state != previous_state)
    {

        if (new_state)
            amp_Micro.gain(0.0);
         else
            amp_Micro.gain(10.0);
        DEBUG_PRINTF("Micro : %d\r\n", new_state);
        previous_state = new_state;
    }
    if(!new_state && peak_micro.available())
        DEBUG_PRINTLN(peak_micro.read());
    //if (rms_micro.available())
    //    DEBUG_PRINTLN(rms_micro.read());
    timeout_Micro = 0;
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
    DEBUG_PRINT("Vol : ");
    DEBUG_PRINTLN(Vol_f);
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
        DEBUG_PRINT("New vol : ");
        DEBUG_PRINTLN(Vol_f);
        wakeup();
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
        DEBUG_PRINT("New vol : ");
        DEBUG_PRINTLN(Vol_f);
        timeout_sleep = 0;
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

    //DEBUG_PRINTF("0x%02X 0x%02X 0x%02X\r\n", current_encoder_logic_status, previous_encoder_logic_status, (current_encoder_logic_status<<2) + previous_encoder_logic_status );

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