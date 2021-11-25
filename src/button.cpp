#include <Bounce.h>
#include <Audio.h>

#include "button.h"
#include "audio_system.h"
#include "led.h"

#define DEBOUNCE_TIME   15

Bounce button1 = Bounce(30, DEBOUNCE_TIME);  
Bounce button2 = Bounce(29, DEBOUNCE_TIME);  
Bounce button3 = Bounce(28, DEBOUNCE_TIME);  
Bounce button4 = Bounce(27, DEBOUNCE_TIME);  
Bounce button5 = Bounce(26, DEBOUNCE_TIME);  
Bounce button6 = Bounce(31, DEBOUNCE_TIME);  
Bounce button7 = Bounce(24, DEBOUNCE_TIME);  
Bounce button8 = Bounce(12, DEBOUNCE_TIME);  
Bounce button9 = Bounce(11, DEBOUNCE_TIME);  
Bounce button10 = Bounce(10, DEBOUNCE_TIME);  
Bounce button11 = Bounce(32, DEBOUNCE_TIME); 
Bounce button12 = Bounce(8, DEBOUNCE_TIME); 
Bounce button13 = Bounce(6, DEBOUNCE_TIME); 
Bounce button14 = Bounce(5, DEBOUNCE_TIME); 
Bounce button15 = Bounce(4, DEBOUNCE_TIME);  

Bounce bt_Play = Bounce(9, DEBOUNCE_TIME); 
Bounce bt_Rec = Bounce(25, DEBOUNCE_TIME);

bool loop_bt11, loop_bt12, loop_bt13, loop_bt14, loop_bt15;


void init_button(void)
{
    pinMode(30, INPUT_PULLUP);
    pinMode(29, INPUT_PULLUP);
    pinMode(28, INPUT_PULLUP);
    pinMode(27, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    pinMode(31, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(32, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);

    pinMode(9, INPUT_PULLUP);
    pinMode(25, INPUT_PULLUP);
}

void update_button(void)
{
    static bool record_flag, play_flag;

    button1.update(); 
    button2.update(); 
    button3.update(); 
    button4.update(); 
    button5.update(); 
    button6.update(); 
    button7.update(); 
    button8.update(); 
    button9.update(); 
    button10.update();
    button11.update();
    button12.update();
    button13.update();
    button14.update();
    button15.update();

    bt_Play.update();
    bt_Rec.update();

    if(button1.fallingEdge())
    {
        playMem1.play(AudioSampleVache);
        led_button(0, 0, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button2.fallingEdge())
    {
        playMem2.play(AudioSampleChien);
        led_button(1, 0, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button3.fallingEdge())
    {
        playMem3.play(AudioSampleChat);
        led_button(2, 0, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button4.fallingEdge())
    {
        playMem4.play(AudioSampleApplau);
        led_button(3, 0, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button5.fallingEdge())
    {
        playMem5.play(AudioSampleHakuna);
        led_button(4, 0, 0xFF, 5000);
        timeout_sleep = 0;
    }
    if(button6.fallingEdge())
    {
        playMem6.play(AudioSampleMixedbrasshitwa);
        led_button(0, 1, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button7.fallingEdge())
    {
        playMem7.play(AudioSamplePiano);
        led_button(1, 1, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if(button8.fallingEdge())
    {
        playMem8.play(AudioSampleGong);
        led_button(2, 1, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button9.fallingEdge())
    {
        playMem9.play(AudioSampleNoelie);
        led_button(3, 1, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button10.fallingEdge())
    {
        playMem10.play(AudioSampleAnna);
        led_button(4, 1, 0xFF, 2000);
        timeout_sleep = 0;
    }
    if(button11.fallingEdge())
    {
        loop_bt11 = !loop_bt11;
    }
    if(button12.fallingEdge())
    {
        loop_bt12 = !loop_bt12;
    }
    if(button13.fallingEdge())
    {
        loop_bt13 = !loop_bt13;
    }
    if(button14.fallingEdge())
    {
        loop_bt14 = !loop_bt14;
    }
    if(button15.fallingEdge())
    {
        loop_bt15 = !loop_bt15;
    }           

    if (loop_bt11 && !(playMem11.isPlaying()))
    {
        playMem11.play(AudioSampleSly);
        led_button(0, 2, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if (!loop_bt11 && (playMem11.isPlaying()))
    {
        playMem11.stop();
        led_button(0, 2, 0x10, 1000);
    }

    if (loop_bt12 && !(playMem12.isPlaying()))
    {
        playMem12.play(AudioSampleXylo);
        led_button(1, 2, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if (!loop_bt12 && (playMem12.isPlaying()))
    {
        playMem12.stop();
        led_button(1, 2, 0x10, 1000);
        timeout_sleep = 0;
    }

    if (loop_bt13 && !(playMem13.isPlaying()))
    {
        playMem13.play(AudioSampleHacienda);
        led_button(2, 2, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if (!loop_bt13 && (playMem13.isPlaying()))
    {
        playMem13.stop();
        led_button(2, 2, 0x10, 1000);
    }

    if (loop_bt14 && !(playMem14.isPlaying()))
    {
        playMem14.play(AudioSampleSka);
        led_button(3, 2, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if (!loop_bt14 && (playMem14.isPlaying()))
    {
        playMem14.stop();
        led_button(3, 2, 0x10, 1000);
        timeout_sleep = 0;
    }

    if (loop_bt15 && !(playMem15.isPlaying()))
    {
        playMem15.play(AudioSampleScratch_norm);
        led_button(4, 2, 0xFF, 1000);
        timeout_sleep = 0;
    }
    if (!loop_bt15 && (playMem15.isPlaying()))
    {
        playMem15.stop();
        led_button(4, 2, 0x10, 1000);
    }

    if(bt_Rec.fallingEdge())
    {
        if (record_flag)
        {
            stop_recorder();
            record_flag = 0;
        } else {
            if (play_flag)
            {
                stop_buffer();  
                play_flag = 0;
            }
            start_recorder();
            record_flag = 1;
        }
        timeout_sleep = 0;
    }

    if(bt_Play.fallingEdge())
    {
        if (play_flag)
        {
            stop_buffer();             
            play_flag = 0;
        } else {
            if(record_flag)
            {
                stop_recorder();            
                record_flag = 0;
            }
            play_buffer();
            play_flag = 1;
        }
        timeout_sleep = 0;
    }
}