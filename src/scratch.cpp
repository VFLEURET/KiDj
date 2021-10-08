
#include <Audio.h>
#include <Wire.h>

#define PIX_INT     0
#define PIX_ADDR    0x73

#define MOTION  0x02
#define D_X_Lo  0x03
#define RES_X   0x0D
#define RES_Y   0x0E
#define D_X_Hi  0x12

void update_scratch(void);

void pix_write(uint8_t reg, uint8_t data)
{
    Wire.beginTransmission(PIX_ADDR & 0xFE);
    Wire.write(reg);
    Wire.write(data); 
    Wire.endTransmission();    // stop transmitting
}

uint8_t pix_read(uint8_t reg)
{
    uint8_t c;

    Wire.beginTransmission(PIX_ADDR & 0xFE);
    Wire.write(reg);
    c = Wire.read(); 
    Wire.endTransmission();    // stop transmitting
    return c;
}


void init_scratch(void)
{
    pinMode(PIX_INT, INPUT_PULLUP);
    attachInterrupt(PIX_INT, update_scratch, FALLING);
    pix_write(RES_X, 0x80);
    pix_write(RES_Y, 0x00);
}

void update_scratch(void)
{
    uint16_t rot;

    detachInterrupt(PIX_INT);
    Serial.println("IRQ Pix");
    if ((pix_read(MOTION) & 0x80) == 0x80)
    {
        rot = pix_read(D_X_Lo) + ((pix_read(D_X_Hi) & 0xF0) << 8);
        Serial.printf("Rot : %d\r\n", rot);
    }
    attachInterrupt(PIX_INT, update_scratch, FALLING);
}