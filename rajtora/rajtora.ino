#include <Wire.h>
#include <Adafruit_NeoPixel.h>
long time = 0;
bool called = false;
bool started = false;
int c = 0;
int bright = 25;


void setup() {
  beepInit();
  displayInit();
  buttonInit();
  timeChipInit();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  buttonPerform(started);
  displayBright(bright);
  displayShow(time, c);

  if (started == true && digitalRead(1) == true && called == false) {
    time++;
    int sec = time%100;
    Serial.println(time);
    switch(sec){
      case 57:beepShort();break;
      case 58:beepShort();break;
      case 59:beepShort();break;
      case -1:beepShort();break;
      case -2:beepShort();break;
      case -3:beepShort();break;
      case 60: time +=40;beepLong();break;
      case -99: if(time!=-0){time +=40;beepLong();}break;
      case -0: if(time!=-0){time +=40;beepLong();}break;
      
      }
  if (time == -0) {
      time = 0;
      beepLong();
    }
    displayShow(time, c);
    called = true;
  }
  else if (called == true && digitalRead(1) == false ) {
    called = false;
  }
}
