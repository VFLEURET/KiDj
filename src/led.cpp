#include <Audio.h>
#include <Wire.h>

#include "audio_system.h"
#include "led.h"
#include "debug.h"

#define ADD_AN32183 0x5C
#define LED_EN 35

static uint32_t next_timeout;
static bool led_enable_flag = false;
static bool stop_animation_flag = 0;

uint8_t AN32183_write_cmd(uint8_t reg, uint8_t length, uint8_t* data)
{
    uint8_t i, error;

    cli();
    Wire.beginTransmission(ADD_AN32183 & 0xFE);
    Wire.write(reg);
    for( i=0; i<length; i++)
        Wire.write(data[i]); 
    error = Wire.endTransmission(true);    // stop transmitting
    if (error) {
        DEBUG_PRINTF("Error i2c led %d \r\n", error);
        init_led();
    }
    sei();
    return error;
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
    digitalWrite(LED_EN, false);
    delay(10);
    digitalWrite(LED_EN, true);
    delay(10);
    
    cmd[0] = 0x01;
    if(AN32183_write_cmd(POWERCNT,1,cmd))
    {
        DEBUG_PRINTLN("No led driver");
        return;
    }

    cmd[0] = _22_5_mA + 0x01;
    AN32183_write_cmd(MTXON,1,cmd);

    memset(cmd,0xFF,9);
    AN32183_write_cmd(PWMEN1,9,cmd);
    AN32183_write_cmd(PWMEN10,2,cmd);

  //  cmd[0] = 0x04;
  //  AN32183_write_cmd(SCANSET,1,cmd);
    
    //memset(cmd,0xA7,9); //20mA and 0.888 x T
    memset(cmd,0xA2,9); //20mA and 0.333 x T
    //memset(cmd,0x10,9); //4mA and 0.333 x T
    AN32183_write_cmd(A1_PWM,9,cmd);
    AN32183_write_cmd(B1_PWM,9,cmd);
    AN32183_write_cmd(C1_PWM,9,cmd);
    AN32183_write_cmd(D1_PWM,9,cmd);
    AN32183_write_cmd(E1_PWM,9,cmd);
    //retroeclairage vumetre
    memset(cmd,0xF2,5);
    AN32183_write_cmd(D1_PWM + 3, 2, cmd);
    AN32183_write_cmd(E1_PWM + 3, 3, cmd);

    clear_led();
    led_enable_flag = true;

    stop_animation_flag = 1;
    start_animation();
    //vumetre
    memset(cmd,0xFF,5);
    AN32183_write_cmd(DTD1 + 3, 2, cmd);
    AN32183_write_cmd(DTE1 + 3, 3, cmd);
    
}

void led_button(uint8_t x, uint8_t y, uint8_t bright, uint16_t timeout)
{
    uint8_t reg;

    if(!led_enable_flag)
        return;

    if(x > 5)
        return;
    if(y > 3)
        return;
    //DEBUG_PRINTF("led x %d y %d PWM %d \r\n",x, y, bright);
    reg = DTA1 + x + (y*9);
    AN32183_write_cmd(reg, 1, &bright);
    next_timeout = millis() + timeout;    
}

void led_rgb(rgb_t color, uint8_t bright)
{
    uint8_t r,g,b;

    if(!led_enable_flag)
        return;

    if(bright > 8)
        bright = 8;

    r = color.red >> bright;
    g = color.blue >> bright;
    b = color.green >> bright;
    AN32183_write_cmd(DTB1 + 5, 1, &r);    
    AN32183_write_cmd(DTC1 + 5, 1, &g);
    AN32183_write_cmd(DTD1 + 5, 1, &b);
}

//uint8_t sweep[6][5] =  {{255,100,50,20,10},
//                        {100,255,100,50,20},
//                        {50,100,255,100,50},
//                        {20,50,100,255,100},
//                        {10,20,50,100,255},
//                        {10,10,20,50,100},
//                        };

uint8_t sweep[7][5] =  {{255,20,20,20,20},
                        {100,255,20,20,20},
                        {50,100,255,20,20},
                        {30,50,100,255,20},
                        {20,30,50,100,255},
                        {20,20,30,50,100},
                        {20,20,20,30,50},
                        };



void update_animation(void)
{
    static uint8_t inc;

    if(!led_enable_flag)
        return;

    if(stop_animation_flag)
        return;

    if (millis() < (next_timeout) + 250)
        return;

    AN32183_write_cmd(DTA1, 5, sweep[inc]);
    AN32183_write_cmd(DTB1, 5, sweep[inc]);
    inc ++;

    if (inc > 6)
        inc = 0;

    if (!playMem11.isPlaying())
    {
        if (inc%2)
            led_button(0, 2, 0x20, 0);
        else
            led_button(0, 2, 0x30, 0);
    }
    if (!playMem12.isPlaying())
    {
        if (inc%2)
            led_button(1, 2, 0x20, 0);
        else
            led_button(1, 2, 0x30, 0);
    }
    if (!playMem13.isPlaying())
    {
        if (inc%2)
            led_button(2, 2, 0x20, 0);
        else
            led_button(2, 2, 0x30, 0);
    }
    if (!playMem14.isPlaying())
    {
        if (inc%2)
            led_button(3, 2, 0x20, 0);
        else
            led_button(3, 2, 0x30, 0);
    }
    if (!playMem15.isPlaying())
    {
        if (inc%2)
            led_button(4, 2, 0x20, 0);
        else
            led_button(4, 2, 0x30, 0);
    }
    next_timeout = millis();
}

void stop_animation(void)
{
    if(stop_animation_flag)
        return;
    DEBUG_PRINTLN("stop led");
    uint8_t cmd[5];
    memset(cmd, 0, sizeof(cmd));

    AN32183_write_cmd(DTA1, 5, cmd);
    AN32183_write_cmd(DTB1, 5, cmd);
    AN32183_write_cmd(DTC1, 5, cmd);
    led_button(0, 3, 0, 0);
    led_button(1, 3, 0, 0);
    stop_animation_flag = 1;
}

void start_animation(void)
{
    uint8_t cmd[5];

    if (stop_animation_flag)
    {
        DEBUG_PRINTLN("start led");
        stop_animation_flag = 0;
        memset(cmd, 0x20, sizeof(cmd));
        AN32183_write_cmd(DTC1, 5, cmd);
        led_button(0, 3, 0x20, 0);
        led_button(1, 3, 0x20, 0);
        update_animation();
    }
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
