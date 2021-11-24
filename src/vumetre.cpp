#include "audio_system.h"
#include "debug.h"

elapsedMillis timeout_Vu;

void update_vumetre(void) 
{
    float value;

    if (timeout_Vu > 100)
    {
        if (rms1.available()) {
            value = rms1.read() * 250;
            if (value > 0xFF)
                value = 0xFF;
            if (value < 1)
                value = 0;
            //DEBUG_PRINT("RMS1 : ");
            //DEBUG_PRINTLN(value);
            analogWrite(23, uint8_t(value));
        }
        timeout_Vu = 0;
    }
}
