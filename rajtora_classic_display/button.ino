int const buttons[3] = {10, 11, 12};
long pressedAt = 0;
bool clicked = false;

void buttonInit() {
  for (int i = 0; i < sizeof(buttons); i++) {
    pinMode(i, INPUT_PULLUP);
  }
}

void buttonPerform() {
  for (int i = 0; i < sizeof(buttons); i++) {
    if (stateRead(i) && !started == 0) {
      if (millis() - started >= 750 && !clicked) {
        // press & hold functions
        switch (i) {
          case 10: changeBright(); break;
          case 11: changeColor(); break;
          case 12: break;
        }
      }

      clicked = true;
    }
    else if (stateRead(i) && !started == 0) {
      if (millis() - started < 750 && !clicked) {
        //press functions
        switch (i) {
          case 10: timePlus(); break;
          case 11: timeMinus(); break;
          case 12: startStop(); break;
        }
        started = 0;
      }
      else if (clicked) {
        started = 0;
        clicked = false;
      }
    }
    else if (stateRead(i) && started == 0) {
      started = millis();
      Serial.println("pressed");
    }
  }
}
bool stateRead(int port) {
  return !digitalRead(port);
}
void timePlus() {
  time = time + 100;
}
void timeMinus() {
  time = time - 100;
}
void changeColor() {
  c++;
  if (c == 3) {
    c == 0;
  }
}
void changeBright() {
  if (bright == 100) {
    bright = 0;
  }
  bright = bright + 25;
  displayBright(bright);
}
void startStop() {
  started = !started;
}
