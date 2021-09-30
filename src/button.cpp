// Bounce objects to read pushbuttons 

#include <Bounce.h>
#include <Audio.h>
#include "button.h"
#include "audio_system.h"

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

Bounce DRUM1 = Bounce(3, DEBOUNCE_TIME); 
Bounce DRUM2 = Bounce(2, DEBOUNCE_TIME); 
Bounce DRUM3 = Bounce(1, DEBOUNCE_TIME);  

Bounce bt_Play = Bounce(9, DEBOUNCE_TIME); 
Bounce bt_Rec = Bounce(25, DEBOUNCE_TIME);

void init_button(void)
{
    pinMode(1, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);

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

    DRUM1.update();
    DRUM2.update();
    DRUM3.update();

    if(button1.fallingEdge())
        playMem1.play(AudioSampleGong);
    if(button2.fallingEdge())
        playMem2.play(AudioSampleGong);
    if(button3.fallingEdge())
        playMem3.play(AudioSampleGong);
    if(button4.fallingEdge())
        playMem4.play(AudioSampleGong);
    if(button5.fallingEdge())
        playMem5.play(AudioSampleGong);
    if(button6.fallingEdge())
        playMem6.play(AudioSampleGong);
    if(button7.fallingEdge())
        playMem7.play(AudioSampleGong);
    if(button8.fallingEdge())
        playMem8.play(AudioSampleGong);
    if(button9.fallingEdge())
        playMem9.play(AudioSampleGong);
    if(button10.fallingEdge())
        playMem10.play(AudioSampleGong);
    if(button11.fallingEdge())
        playMem11.play(AudioSampleGong);
    if(button12.fallingEdge())
        playMem12.play(AudioSampleGong);
    if(button13.fallingEdge())
        playMem13.play(AudioSampleGong);
    if(button14.fallingEdge())
        playMem14.play(AudioSampleGong);
    if(button15.fallingEdge())
        playMem15.play(AudioSampleGong);
    
    if(DRUM1.fallingEdge())
        playMemDrum1.play(AudioSampleSnare);
    if(DRUM2.fallingEdge())
        playMemDrum1.play(AudioSampleTomtom);
    if(DRUM3.fallingEdge())
        playMemDrum1.play(AudioSampleHihat);                
}