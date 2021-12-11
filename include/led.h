#ifndef _LED_H
#define _LED_H

typedef struct{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}rgb_t;

typedef enum {
  NO_LED,
  CHARGE_LED,
  EMPTY_BATT_LED,
  PSU_EXT_LED,
  PSU_BATT_LED,
  MICRO_LED,
  PLAYING_LED,
  PAUSE_LED,
  VEILLE_LED,
} led_state_t;

void init_led(void);
void update_animation(void);
void led_rgb(rgb_t color, uint8_t bright);
void led_button(uint8_t x, uint8_t y, uint8_t bright, uint16_t timeout);
void stop_animation(void);
void start_animation(void);

#define RED				((rgb_t){255,0,0})
#define GREEN			((rgb_t){0,255,0})
#define BLUE			((rgb_t){0,0,255})
#define BLUE_AZUR	((rgb_t){37,172,220})
#define YELLOW		((rgb_t){255,255,0})
#define MAGENTA		((rgb_t){255,0,255})
#define CYAN			((rgb_t){0,255,255})
#define ORANGE		((rgb_t){255,127,0})
#define BLACK			((rgb_t){0,0,0})
#define PINK      ((rgb_t){155,0,128})

//addr
#define POWERCNT        0x02

#define MTXON           0x05
#define PWMEN1          0x06 
#define PWMEN2          0x07 
#define PWMEN3          0x08 
#define PWMEN4          0x09 
#define PWMEN5          0x0A 
#define PWMEN6          0x0B 
#define PWMEN7          0x0C 
#define PWMEN8          0x0D 
#define PWMEN9          0x0E 
#define PWMEN10         0x0F 
#define PWMEN11         0x10 

#define SCANSET         0x36

#define DTA1            0x40
#define DTB1            0x49
#define DTC1            0x52
#define DTD1            0x5B
#define DTE1            0x64
#define DTF1            0x6D
#define DTF5            0x71
#define DTG1            0x76
#define DTH1            0x7F
#define DTI1            0x88


#define A1_PWM          0x91
#define B1_PWM          0x9A
#define C1_PWM          0xA3
#define D1_PWM          0xAC
#define E1_PWM          0xB5
#define F1_PWM          0xBE




//MTXON
#define _7_5_mA      0x0
#define _15_mA       0x2
#define _22_5_mA     0x4
#define _30_mA       0x6
#define _37_5_mA     0x8
#define _45_mA       0xA
#define _52_5_mA     0xC
#define _60_mA       0xE 


#endif