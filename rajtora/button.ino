int const buttons[] = {10, 11, 12};
long pressed[] = {0, 0, 0};
bool clicked[] = {false, false, false};

void buttonInit() {
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}
void buttonPerform(bool started) {
  for (int i = 0; i < 3; i++) {
    int port = buttons[i];
    long pressedAt = pressed[i];
    bool isClicked = clicked[i];
    if (stateRead(port) && pressedAt != 0 && !isClicked) {
      if (millis() - pressedAt > 750) {
        Serial.println("long");
        //press & hold actions
        switch (port) {
          case 10: changeBright(); break; //works allways
          case 11: changeColor(); break; //works allways
          case 12: break;
        }
        pressedAt = 0;
        isClicked = true;
      }
    }
    else if (!stateRead(port) && pressedAt != 0 && !isClicked) {
      Serial.println("short");
      //click actions
      switch (port) {
        case 10: if(!started){timePlus();}; break; //only works if not started
        case 11: if(!started){timeMinus();}; break; //only works if not started
        case 12: startStop(); break; //works allways
      }
      pressedAt = 0;
    }
    else if (!stateRead(port) && isClicked) {
      pressedAt = 0;
      isClicked = false;
    }
    else if (stateRead(port) && pressedAt == 0) {
      pressedAt = millis();
    }

    pressed[i] = pressedAt ;
    clicked[i] = isClicked;
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
    c = 0;
  }
}
void changeBright() {
  if (bright == 100) {
    bright = 0;
  }
  bright = bright + 25;
  Serial.println(bright);
  displayBright(bright);
}
void startStop() {
  started = !started;
}
