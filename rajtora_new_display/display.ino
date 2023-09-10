#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel dig5 = Adafruit_NeoPixel(34, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dig4 = Adafruit_NeoPixel(34, 5, NEO_GRB + NEO_KHZ800);

//With conrers
const int num0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};
const int num1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
const int num2[] = {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const int num3[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const int num4[] = {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1};
const int num5[] = {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1};
const int num6[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1};
const int num7[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};
const int num8[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const int num9[] = {1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

const int numOff[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const int minusz[] = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1};

int *numberRet(int num) {
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

void printNum(int num)
{
  for (int i = 0; i < 34; i++)
  {
    if (numberRet(num)[i] == 0)
    {
    dig5.setPixelColor(i, 0, 0, 0);
    dig4.setPixelColor(i, 0, 0, 0);
    }
    else{
    dig5.setPixelColor(i, 255, 255, 255);
    dig4.setPixelColor(i, 255, 255, 255);
    }
  }
    dig5.setBrightness(255);
    dig5.show();
    dig4.setBrightness(255);
    dig4.show();

}

void setup() {
  dig5.begin();
  dig4.begin();
}

void loop() {
  for (int i = 0; i < 12; i++)
  {
    printNum(i);
    delay(1000);
  }
}