
#include <Audio.h>
#include <Wire.h>

#include "audio_system.h"
#include "debug.h"

#define PIX_INT     0
#define PIX_ADDR    0x75

#define MOTION  0x02
#define D_X_Lo  0x03
#define OP_MODE 0x05
#define RES_X   0x0D
#define RES_Y   0x0E
#define D_X_Hi  0x12

void encode_scratch(void);
bool pix_flag = false;

void pix_write(uint8_t reg, uint8_t data)
{
    Wire.beginTransmission(PIX_ADDR);
    Wire.write(reg);
    Wire.write(data); 
    Wire.endTransmission();    // stop transmitting
}

uint8_t pix_read(uint8_t reg)
{
    uint8_t c = 0xFF, error;

    Wire.beginTransmission(PIX_ADDR);
    Wire.write(reg);
    error = Wire.endTransmission(true);    // stop transmitting
    if (error){ 
        DEBUG_PRINTF("Error i2c pix R %d \r\n", error);
        pix_flag = false;
        return 0;
    }
    Wire.requestFrom(PIX_ADDR, 1);
    if(Wire.available() == 1);
        c = Wire.read(); 
    error = Wire.endTransmission(true);    // stop transmitting
    if (error){ 
        DEBUG_PRINTF("Error i2c %d pix R\r\n", error);
        return 0;
    }
    pix_flag = true;
    return c;
}


void init_scratch(void)
{
    pinMode(PIX_INT, INPUT_PULLUP);
    DEBUG_PRINTF("PIX_ID 0x%02X 0x%02X \r\n ", pix_read(0x00), pix_read(0x01));
    if (pix_flag == false)
        return;
    pix_write(RES_X, 0x3F);
    pix_write(RES_Y, 0x00);
    pix_write(OP_MODE, 0x01);
    attachInterrupt(PIX_INT, encode_scratch, FALLING);
}

void off_scratch(void)
{
    pix_write(OP_MODE, 0x01);
}

static uint32_t timeout_scratch;

void encode_scratch(void)
{
    int16_t rotl, roth;
    uint32_t position;
    static uint8_t direction = 0;
    //static int16_t cumul;

    if (pix_flag == false)
        return;

    detachInterrupt(PIX_INT);
    if ((pix_read(MOTION) & 0x80) == 0x80)
    {
        rotl = pix_read(D_X_Lo);
        roth = (pix_read(D_X_Hi) & 0xF0) << 4;
        if (roth & 0x0800){
            roth |= 0xf000;
        }
        rotl = rotl | roth;
        //cumul += rotl;
        //DEBUG_PRINTLN(cumul);
        rotl = -rotl;
        //DEBUG_PRINTF(" Rot : %i\r\n", rotl);
        if (rotl > 5)
        {
            if ((playMem16.isPlaying() && direction == 1) ||
               (!playMem16.isPlaying()))
            {
                position = playMem16.positionMillis();
                //DEBUG_PRINTF("Play norm to %d%d \r\n", position, direction);
                playMem16.stop();
                playMem16.play(AudioSampleScratch_norm + position);
                direction = 0;
                wakeup();
            }
            timeout_scratch = rotl * 50 + millis();;
        }
        else if(rotl < -5)
        {
            if ((playMem16.isPlaying() && direction == 0) ||
               (!playMem16.isPlaying()))
            {
                playMem16.stop();
                playMem16.play(AudioSampleDj);
                direction = 1;
                wakeup();
            }
            timeout_scratch = -rotl * 30 + millis();
        }
    }

    attachInterrupt(PIX_INT, encode_scratch, FALLING);
}

void update_scratch(void)
{
    if ((millis() > timeout_scratch) && playMem16.isPlaying())
        playMem16.stop();
}