const int red[3] = {255, 0, 0};
const int green[3] = {0, 255, 0};
const int blue[3] = {0, 0, 255};
int n;

int color[3][3] = {{255, 0, 0},
                   {0, 255, 0},
                   {0, 0, 255}
                   };


const int colors[] = {red, blue, green};
const bool num0[] = {true, true, true, true, true, true, false};
const bool num1[] = {false, false, false, true, true, false, false};
const bool num2[] = {false, true, true, false, true, true, true};
const bool num3[] = {false, false, true, true, true, true, true};
const bool num4[] = {true, false, false, true, true, false, true};
const bool num5[] = {true, false, true, true, false, true, true};
const bool num6[] = {true, true, true, true, false, true, true};
const bool num7[] = {false, false, false, true, true, true, false};
const bool num8[] = {true, true, true, true, true, true, true};
const bool num9[] = {true, false, true, true, true, true, true};
const bool numOff[] = {false, false, false, false, false, false, false};
const bool minusz[] = {false, false, false, false, false, false, true};

Adafruit_NeoPixel points = Adafruit_NeoPixel(2, 9, NEO_GRB + NEO_KHZ800);

const int NeoPCount = 28;
Adafruit_NeoPixel dig1 = Adafruit_NeoPixel(NeoPCount, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dig2 = Adafruit_NeoPixel(NeoPCount, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dig3 = Adafruit_NeoPixel(NeoPCount, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dig4 = Adafruit_NeoPixel(NeoPCount, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dig5 = Adafruit_NeoPixel(NeoPCount, 4, NEO_GRB + NEO_KHZ800);

const Adafruit_NeoPixel digit[] = {dig1, dig2, dig3, dig4, dig5, points};


void displayInit() {
  for (int i = 0; i < 6; i++) {
    digit[i].begin();
}
}

void showDigit(int num, int pos, int c) {
  n = 0;
  for (int i = 0; i < 7; i++) {
   if (numberRet(num)[i] == false) {
      digit[pos].setPixelColor(n++, 0, 0, 0);
      digit[pos].setPixelColor(n++, 0, 0, 0);
      digit[pos].setPixelColor(n++, 0, 0, 0);
      digit[pos].setPixelColor(n++, 0, 0, 0);
    }
    else {
      digit[pos].setPixelColor(n++, color[c][0], color[c][1], color[c][2]);
      digit[pos].setPixelColor(n++, color[c][0], color[c][1], color[c][2]);
      digit[pos].setPixelColor(n++, color[c][0], color[c][1], color[c][2]);
      digit[pos].setPixelColor(n++, color[c][0], color[c][1], color[c][2]);
    }

  }
  digit[pos].show();
}

bool *numberRet(int num) {
  switch (num) {
    case 0: return num0; break;
    case 1: return num1; break;
    case 2: return num2; break;
    case 3: return num3; break;
    case 4: return num4; break;
    case 5: return num5; break;
    case 6: return num6; break;
    case 7: return num7; break;
    case 8: return num8; break;
    case 9: return num9; break;
    case 10: return numOff; break;
    case 11: return minusz; break;
  }
}

void displayBright(int percent){
  for(int i = 0; i<5;i++){
    digit[i].setBrightness(percent);
    points.setBrightness(percent);
    }
  }

void displayShow(long time, int c) {
  points.setPixelColor(0, color[c][0], color[c][1], color[c][2]);
  points.setPixelColor(1, color[c][0], color[c][1], color[c][2]);
  points.show();
  char buf[10];
  sprintf(buf, "%5d", time);
  for (int i = 0; i < 5; i++) {
    if (buf[i] == ' ') {
      buf[i] = 10; // space
    }
    else if (buf[i] == '-') {
      buf[i] = 11; // negativ
    }
    else {
      buf[i] = buf[i] - 48;
    }
    showDigit(buf[i], i, c);
  }
}
