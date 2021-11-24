#include "audio_system.h"
#include "led.h"

static byte buffer[5000];
static uint8_t ptr, ptr_read;
static uint8_t mode = 0;

void start_recorder(void)
{
    DEBUG_PRINTLN("Start record");
    led_button(0, 3, 0xFF, 0);
 //   ptr = 0;
 //   memset(buffer, 0, sizeof(buffer));
 //   record.begin();
 //   mode = 1;
}

void stop_recorder(void)
{
    DEBUG_PRINTLN("Stop record");      
    led_button(0, 3, 0x10, 0);
//    while(record.available())
//    {
//        memcpy(buffer + ptr * 256, record.readBuffer(), 256);
//        ptr++;
//        record.freeBuffer();
//    }
//    record.clear();
//    record.end();
    mode  = 0;
}

void update_recorder(void)
{  
    if (mode == 1)
    {
//        if (record.available() > 0)
//        {
//            memcpy(buffer + ptr * 256, record.readBuffer(), 256);
//            record.freeBuffer();
//            ptr++;
//        }
//        DEBUG_PRINTLN(ptr);
//    } else if((mode == 2) && ptr_read < ptr) {
//        int16_t *p = Play_record.getBuffer();
//        memcpy(p, buffer + ptr_read * 256, 256);
    }
    
}

void play_buffer(void)
{
    DEBUG_PRINTLN("Play record");
    led_button(1, 3, 0xFF, 0);
//    int16_t *p = Play_record.getBuffer();
//    memcpy(p, buffer, 256);
//    Play_record.playBuffer();
//    ptr_read = 1;
    mode = 2;
}

void stop_buffer(void)
{
    DEBUG_PRINTLN("Play stop record");
    led_button(1, 3, 0x10, 0);
 //   int16_t *p = Play_record.getBuffer();
 //   memset(p, 0, 256);
    mode = 0;
}
