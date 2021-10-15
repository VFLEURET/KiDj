
#include <Audio.h>
#include <Wire.h>

#include "audio_system.h"

#define PIX_INT     0
#define PIX_ADDR    0x75

#define MOTION  0x02
#define D_X_Lo  0x03
#define RES_X   0x0D
#define RES_Y   0x0E
#define D_X_Hi  0x12

void update_scratch(void);

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
        Serial.printf("Error i2c %d \r\n", error);
        return 0;
    }
    Wire.requestFrom(PIX_ADDR, 1);
    if(Wire.available() == 1);
        c = Wire.read(); 
    error = Wire.endTransmission(true);    // stop transmitting
    if (error){ 
        Serial.printf("Error i2c %d \r\n", error);
        return 0;
    }
    return c;
}


void init_scratch(void)
{
    pinMode(PIX_INT, INPUT_PULLUP);
    Serial.printf("PIX_ID 0x%02X 0x%02X \r\n ", pix_read(0x00), pix_read(0x01));
    pix_write(RES_X, 0x09);
    pix_write(RES_Y, 0x00);
    attachInterrupt(PIX_INT, update_scratch, FALLING);
}

void update_scratch(void)
{
    static int16_t mov = 0;
    int16_t rotl, roth;

    detachInterrupt(PIX_INT);
    if ((pix_read(MOTION) & 0x80) == 0x80)
    {
        rotl = pix_read(D_X_Lo);
        roth = (pix_read(D_X_Hi) & 0xF0) << 4;
        if (roth & 0x0800){
            roth |= 0xf000;
        }
        rotl = rotl | roth;
        mov = mov + rotl;
        Serial.printf(" Rot : %i %i\r\n", rotl, mov);
        if ((rotl > 10) || (rotl < -10))
            playMem16.play(AudioSampleScratch);
    }
    attachInterrupt(PIX_INT, update_scratch, FALLING);
}