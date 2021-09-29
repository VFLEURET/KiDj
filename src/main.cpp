// Kidj V1.0

// #include <Bounce.h>
 #include <Audio.h>
// #include "button.h"
//#include "audio_system.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Bonjour KiDj");

 // init_button();
 // init_mixer();
 // init_audio();

}

void loop() {
  uint32_t current_millis, previous_millis;

  //update_button();
 //update_vumetre(); 
  //update_effect();

  current_millis = millis();
  if (current_millis > (previous_millis + 1000)) {
    Serial.print("Memory usage :");
    Serial.println(AudioMemoryUsageMax());
    previous_millis = current_millis;
  }
  
}
