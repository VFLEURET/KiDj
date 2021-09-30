#include "audio_system.h"

void update_vumetre(void) 
{
    float value;

    if (rms1.available()) {
        value = rms1.read();
        //Serial.println(value);
        analogWrite(23, value * 255);
    }
}
