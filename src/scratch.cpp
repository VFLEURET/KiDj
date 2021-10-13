
#include <Audio.h>
#include <Wire.h>

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
    delay(1);
    Wire.requestFrom(PIX_ADDR, 1);
    while(Wire.available())
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
    static int16_t mov;
    uint8_t Mot;
    int16_t rotl, roth;

    detachInterrupt(PIX_INT);
    //Serial.println("IRQ Pix ");
    //Mot = pix_read(MOTION);
    //Serial.println(Mot);
    if ((pix_read(MOTION) & 0x80) == 0x80)
    {
        rotl = pix_read(D_X_Lo);
        Serial.printf("Rotl : %d", rotl);
        roth = (pix_read(D_X_Hi) & 0xF0) << 4;
        if (roth & 0x0800){
            roth |= 0xf000;
            Serial.println("coucou");
        }
        Serial.printf(" Roth : %i", roth);
        rotl = rotl | roth;
        mov = mov + rotl;
        //rot = pix_read(D_X_Lo) + ((pix_read(D_X_Hi) & 0xF0) << 8);
        Serial.printf(" Rot : %i %i\r\n", rotl, mov);
    }
    attachInterrupt(PIX_INT, update_scratch, FALLING);
}