#include <Wire.h>
#include <Adafruit_NeoPixel.h>
long time = 0;
bool called = false;
bool started = false;
int c = 0;
int bright = 25;
 bool pressed=false;
 bool pressed1=false;
   unsigned long pr =0;
  unsigned long released=0;


void setup() {

  beepInit();
  displayInit();
  buttonInit();
  timeChipInit();
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}
void loop() {
  displayBright(bright);
  
  if (started == true && digitalRead(1) == true && called == false) {
    time++;  
    buttonPerform();

    Serial.println(time);
   
      if (time % 100 == 57 || time % 100 == 58 || time % 100 == 59 || time % 100 == -1 || time % 100 == -2 || time % 100 == -3 ) {
     displayShow(time, c);       
    beepShort();
      }
      else if (time % 100 == 60) {
        time = time + 40;
      displayShow(time, c);
        beepLong();
        
      }
      
      else if (time % 100 == -99 && time != -0) {
        time = time + 40;
displayShow(time, c);
      }
      
      else if (time % 100 == -0 && time != -0) {
        time = time + 40;
displayShow(time, c);
        beepLong();
      }
      else if (time == -0) {
        time = 0;
        displayShow(time, c);
        beepLong();
      }
      else{
         displayShow(time, c);
        }
    
    called = true;
  }
  else if (called == true && digitalRead(1) == false ) {
    called = false;
  }
  else if (started == false) {
     displayShow(time, c);
    allButtonPerform();
    
  }
}
