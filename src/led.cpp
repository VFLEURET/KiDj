#include <Audio.h>
#include <Wire.h>
#include <led.h>

#define ADD_AN32183 0xB8
#define LED_EN 35

void AN32183_write_cmd(uint8_t reg, uint8_t length, uint8_t* data)
{
    uint8_t i;

    Wire.beginTransmission(ADD_AN32183 & 0xFE);
    Wire.write(reg);
    for( i=0; i<length; i++)
        Wire.write(data[i]); 
    Wire.endTransmission();    // stop transmitting
}

void clear_led(void){
    uint8_t cmd[9];
    
    memset(cmd,0x00,9); 
    AN32183_write_cmd(DTA1,9,cmd);
    AN32183_write_cmd(DTB1,9,cmd);
    AN32183_write_cmd(DTC1,9,cmd);
    AN32183_write_cmd(DTD1,9,cmd);
    AN32183_write_cmd(DTE1,9,cmd);
    AN32183_write_cmd(DTF1,9,cmd);
    AN32183_write_cmd(DTG1,9,cmd);
    AN32183_write_cmd(DTH1,9,cmd);
    AN32183_write_cmd(DTI1,9,cmd);    
}

void init_led(void)
{
    uint8_t cmd[9];
    Wire.begin();
    pinMode(LED_EN, OUTPUT);
    digitalWrite(LED_EN, true);

    delay(100);
    
    cmd[0] = 0x01;
    AN32183_write_cmd(POWERCNT,1,cmd);
    cmd[0] = _15_mA + 0x01;
    AN32183_write_cmd(MTXON,1,cmd);

    memset(cmd,0xFF,4);
    AN32183_write_cmd(PWMEN1,4,cmd);

//    cmd[0] = 0x00;
//    AN32183_write_cmd(SCANSET,1,cmd);
    
    memset(cmd,0xA7,9); //10mA ans 0.888 x T
    //memset(cmd,0x22,9); //4mA ans 0.333 x T
    //memset(cmd,0x10,9); //4mA ans 0.333 x T
    AN32183_write_cmd(A1_PWM,9,cmd);
    AN32183_write_cmd(B1_PWM,9,cmd);
    AN32183_write_cmd(C1_PWM,9,cmd);
    AN32183_write_cmd(D1_PWM,9,cmd);
    clear_led();
}

void led_button(uint8_t x, uint8_t y, uint8_t bright)
{
    AN32183_write_cmd(DTA1 + x + y, 1, &bright);    
}


uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

void update_animation(void)
{
    static uint32_t previous_millis;

    if (millis() < (previous_millis + 20))
        return;

    for (uint8_t incr = 0; incr < 24; incr++)
        for (uint8_t x = 0; x < 5; x++)
            for (uint8_t y = 0; y < 3; y++)
                led_button(x, y, sweep[(x+y+incr)%24]);
    previous_millis = millis();
}