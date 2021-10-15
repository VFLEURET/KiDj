#include "audio_system.h"

elapsedMillis timeout_Vu;

void update_vumetre(void) 
{
    float value;

    if (timeout_Vu > 200)
    {
        if (rms1.available()) {
            value = rms1.read() * 2500;
            if (value > 0xFF)
                value = 0xFF;
            if (value < 10)
                value = 0;
            //Serial.print("RMS1 : ");
            //Serial.println(value);
            analogWrite(23, uint8_t(value));
        }
        timeout_Vu = 0;
    }
}
