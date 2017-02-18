#include <Adafruit_NeoPixel.h>
//白、黄色、オレンジ、ピンク、むらさき、青
int color[] = {255, 255, 255, 255, 234, 68, 255, 93, 23, 255, 47, 186, 174, 16, 255, 30, 160, 255, 255, 255, 255};
int realizeR;
int realizeG;
int realizeB;

#define PIN            6
#define NUMPIXELS      5

int j;
int totalActionTime;
int colorChangeTime;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  j = 0;
  int colors = 6;
  colorChangeTime = 2000;
  totalActionTime = colorChangeTime * colors;
  
}

void loop() {

  unsigned long ellapsed = millis();
  int actionTime = ellapsed % totalActionTime;
  int colorTime = ellapsed % colorChangeTime;

  for (int i = 0; i < 6; i++) {
    if (actionTime > colorChangeTime * i && actionTime < colorChangeTime * (i + 1) ) {
      int a = 3 * i;
      colorEasing(colorTime, a);
    }
  }

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(realizeR, realizeG, realizeB));
  }
  pixels.show();
}

void colorEasing(int currentTime, int firstVal) {

  float nowR = map(currentTime, 0, colorChangeTime, color[firstVal], color[firstVal + 3]);
  float nowG = map(currentTime, 0, colorChangeTime, color[firstVal + 1], color[firstVal + 4]);
  float nowB = map(currentTime, 0, colorChangeTime, color[firstVal + 2], color[firstVal + 5]);

  realizeR = nowR;
  realizeG = nowG;
  realizeB = nowB;
}
