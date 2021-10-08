#include <Audio.h>
#include <Wire.h>

#include "led.h"

#define ADD_AN32183 0x5C
#define LED_EN 35

static uint32_t previous_millis;

void AN32183_write_cmd(uint8_t reg, uint8_t length, uint8_t* data)
{
    uint8_t i, error;


    Wire.beginTransmission(ADD_AN32183 & 0xFE);
    Wire.write(reg);
    for( i=0; i<length; i++)
        Wire.write(data[i]); 
    error = Wire.endTransmission(true);    // stop transmitting
    if (error)
        Serial.printf("Error i2c %d \r\n", error);
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

void all_led(uint8_t bright){
    uint8_t cmd[9];
    
    memset(cmd,bright,9); 
    AN32183_write_cmd(DTA1,5,cmd);
    AN32183_write_cmd(DTB1,5,cmd);
    AN32183_write_cmd(DTC1,5,cmd);
   
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

    memset(cmd,0xFF,9);
    AN32183_write_cmd(PWMEN1,9,cmd);
    AN32183_write_cmd(PWMEN10,2,cmd);

//    cmd[0] = 0x00;
//    AN32183_write_cmd(SCANSET,1,cmd);
    
    //memset(cmd,0xA7,9); //10mA ans 0.888 x T
    memset(cmd,0x21,9); //4mA ans 0.333 x T
    //memset(cmd,0x10,9); //4mA ans 0.333 x T
    AN32183_write_cmd(A1_PWM,9,cmd);
    AN32183_write_cmd(B1_PWM,9,cmd);
    AN32183_write_cmd(C1_PWM,9,cmd);
    AN32183_write_cmd(D1_PWM,9,cmd);
    //all_led(0x50);
    //delay(2000);
    clear_led();
}

void led_button(uint8_t x, uint8_t y, uint8_t bright, uint16_t timeout)
{
    uint8_t reg;

    //all_led(10);
    reg = DTA1 + x + (y*9);
    AN32183_write_cmd(reg, 1, &bright);
    //Serial.println(reg);
    previous_millis = millis() + timeout;    
}

void led_rgb(rgb_t color, uint8_t bright)
{
    uint8_t r,g,b;
    if(bright > 8)
        bright = 0;

    r = color.red >> bright;
    g = color.blue >> bright;
    b = color.green >> bright;
    AN32183_write_cmd(DTB1 + 5, 1, &r);    
    AN32183_write_cmd(DTC1 + 5, 1, &g);
    AN32183_write_cmd(DTD1 + 5, 1, &b);
}

//uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};
uint8_t sweep[5][5] = {{255,100,50,20,10},
                        {100,255,100,50,20},
                        {50,100,255,100,50},
                        {20,50,100,255,100},
                        {10,20,50,100,255}};

void update_animation(void)
{
    static uint8_t inc;

    if (millis() < (previous_millis) + 250)
        return;

    

    switch(inc)
    {
        case 0 ... 2 :
        //case 1 :
        //case 2 :
            AN32183_write_cmd(DTA1, 5, sweep[inc]);
            AN32183_write_cmd(DTB1, 5, sweep[inc+1]);
            //AN32183_write_cmd(DTC1, 5, sweep[inc+2]);
            inc ++;
        break;
        case 3 :
            AN32183_write_cmd(DTA1, 5, sweep[inc]);
            AN32183_write_cmd(DTB1, 5, sweep[inc+1]);
            //AN32183_write_cmd(DTC1, 5, sweep[0]);
            inc ++;
        break;
        case 4 :
            AN32183_write_cmd(DTA1, 5, sweep[inc]);
            AN32183_write_cmd(DTB1, 5, sweep[0]);
            //AN32183_write_cmd(DTC1, 5, sweep[1]);
            inc = 0;
        break;         
        default:
            inc = 0;
        break;

    }

    previous_millis = millis();
}

void led_state(led_state_t new_state)
{
    static uint8_t previous_state;

    if (new_state == previous_state)
    return;

    if (new_state == CHARGE_LED)
    led_rgb(RED, 3);
    else if (new_state == VEILLE_LED)
    led_rgb(YELLOW, 3);
    else if (new_state == EMPTY_BATT_LED)
    led_rgb(ORANGE, 2);
    else if (new_state == PSU_EXT_LED)
    led_rgb(GREEN, 3);
    else if (new_state == PSU_BATT_LED)
    led_rgb(CYAN, 3);
    
    previous_state = new_state;
}
