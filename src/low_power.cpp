#include <Audio.h>
#include "debug.h"

void goto_sleep(void)
{
    DEBUG_PRINTLN("Go to sleep \r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    Serial.flush();
    Serial.end();
    pinMode(38, OUTPUT);
    digitalWrite(33, false); //disable amplifier
    digitalWrite(35, false);
    digitalWrite(38, true);
    delay(5000);

}