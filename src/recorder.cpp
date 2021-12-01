#include "audio_system.h"
#include "led.h"

static void stop_recorder(void);

enum state_recorder 
{
    stop_record,
    recording_state,
    play_last_record,
};

static uint8_t mode = stop_record;

File file_record;

#define SDCARD_CS_PIN    BUILTIN_SDCARD

void start_recorder(void)
{
    if (mode == recording_state)
        stop_recorder();
    else 
    {
        if (mode == play_last_record)
        {
            led_button(1, 3, 0x10, 0);
            playSdRawRecord.stop();
        }
        if (!(SD.begin(SDCARD_CS_PIN))) {
        // stop here if no SD card, but print a message
            DEBUG_PRINTLN("Unable to access the SD card");
            for (int i=0; i<4; i++)
            {
                led_button(0, 3, 0xFF, 0);
                delay(100);
                led_button(0, 3, 0x10, 0);
                delay(100);
            }
            return;
        }
        DEBUG_PRINTLN("Start record");
        led_button(0, 3, 0xFF, 0);
        if (SD.exists("RECORD.RAW")) 
        {
            // The SD library writes new data to the end of the
            // file, so to start a new recording, the old file
            // must be deleted before new data is written.
            SD.remove("RECORD.RAW");
        }
        file_record = SD.open("RECORD.RAW", FILE_WRITE);
        if (file_record) {
            record.begin();
            mode = recording_state;
        }
    }
}

static void stop_recorder(void)
{
    DEBUG_PRINTLN("Stop record");      
    led_button(0, 3, 0x10, 0);
    record.end();
    if (mode == recording_state)
    {
        while(record.available() > 0)
        {
            file_record.write((byte*)record.readBuffer(), 256);
            record.freeBuffer();    
        }
        file_record.close();
    }

    mode  = stop_record;
}

void update_recorder(void)
{  
    if (mode == recording_state)
    {
        if (record.available() >= 2) {
            byte buffer[512];
            // Fetch 2 blocks from the audio library and copy
            // into a 512 byte buffer.  The Arduino SD library
            // is most efficient when full 512 byte sector size
            // writes are used.
            memcpy(buffer, record.readBuffer(), 256);
            record.freeBuffer();
            memcpy(buffer+256, record.readBuffer(), 256);
            record.freeBuffer();
            // write all 512 bytes to the SD card
            //elapsedMicros usec = 0;
            file_record.write(buffer, 512);
        }
    } 
    if (mode == play_last_record)
        if(!playSdRawRecord.isPlaying())
        {
            playSdRawRecord.play("RECORD.RAW");
        }
}

void play_record(void)
{
    DEBUG_PRINTF("Play record %d\r\n", mode);
    
    if (mode == recording_state)
    {
        stop_recorder();
    }
    if (mode != play_last_record)
    {
        if (SD.exists("RECORD.RAW"))
        {
            DEBUG_PRINTLN("RECORD exists");
            led_button(1, 3, 0xFF, 0);
            playSdRawRecord.play("RECORD.RAW");
            mode = play_last_record;
        }
    } else if ((mode == play_last_record) && playSdRawRecord.isPlaying())
    {
        led_button(1, 3, 0x10, 0);
        playSdRawRecord.stop();
        mode = stop_record;
    }
}

