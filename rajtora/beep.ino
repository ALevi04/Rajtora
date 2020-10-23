int buzzer = 0;
int speaker = A0;
int freq = 500;
int speakerFreq = 2500;
int isPlugged = A1;
void beepInit() {
  pinMode(buzzer, OUTPUT);
  tone(buzzer, freq);
  delay(300);
  noTone(buzzer);
  pinMode(speaker, OUTPUT);
  pinMode(isPlugged, INPUT_PULLUP);
}

void beepShort() {
  if (isPlugged) {
    tone(speaker, speakerFreq);
  }
  else {
    tone(buzzer, freq);
  }
  finishTone(300, millis());
}

void beepLong() {
  if (isPlugged) {
    tone(speaker, speakerFreq);
  }
  else {
    tone(buzzer, freq);
  }
  finishTone(800, millis());
}

void beepBtn() {
  tone(buzzer, freq);
  finishTone(800, millis());
}
void finishTone(int delay, long pressedMillis) {
  if (millis() - pressedMillis > delay) {
    noTone(buzzer);
    noTone(speaker);
  }
}
