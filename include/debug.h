#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 

#ifdef DEBUG
    #define DEBUG_PRINTLN(x)  Serial.println (x)
    #define DEBUG_PRINT(x)    Serial.print (x)
    #define DEBUG_PRINTF(...)   Serial.printf (__VA_ARGS__)
#else
    #define DEBUG_PRINTLN(x)
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTF(...)
#endif

#endif