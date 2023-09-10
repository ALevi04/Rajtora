void buttonInit() {
  int const buttonPorts[4] = {10, 11, 12};
  for (int i = 0; i <= 4; i++) {
    pinMode(buttonPorts[i], INPUT_PULLUP);
  }
}

void buttonPerform() {
  if (digitalRead(12) == false) {
    started = false ;
    Serial.println("Acted");
    delay(100);
  }
}


void allButtonPerform() {
  if (digitalRead(12) == false ) {
    beepLong();
    started = true;
    delay(500);
  }
  if (digitalRead(10) == false && !pressed ) {
   pressed = true;
   pr = millis();
  }
  if (digitalRead(10) == true && pressed ) {
    Serial.println("released");
   released = millis();
   Serial.println(pr);
   Serial.println(released);
    pressed = false;
     if (released-pr>500){
      Serial.println("500");
      c++;
    if (c == 3) {
      c = 0;
    }
      }
      else{
    beepBtn();
    time = time + 100;
    }
    delay(500);
  }
  if (digitalRead(11) == false && !pressed1 ) {
     pressed1 = true;
   pr = millis();
   }
   if (digitalRead(11) == true && pressed1 ) {
    released = millis();
 Serial.println("p11");
    pressed1 =false;
    if (released-pr>500){
      if (bright == 100) {
      bright = 25;
    }
    displayBright(bright);
    bright = bright + 25;
      }
      else{
    beepBtn();
    time = time - 100;
    
      }
      delay(500);
  }
 /* if (digitalRead(A0) == false ) {
    beepBtn();
    c++;
    if (c == 3) {
      c = 0;
    }
    delay(500);
  }
  if (digitalRead(4) == false ) {
    beepBtn();
    if (bright == 0) {
      bright = 100;
    }
    displayBright(bright);
    bright = bright - 25;
    delay(500);
  }*/
}
