#include <FastLED.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "char.h"

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

CRGB leds[1];

int threshold = 5;
bool touch[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //touch values array

char tempPattern [5][5] = {
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' '}
};

void gotTouch0() {
  touch[0] = true;
}
void gotTouch1() {
  touch[1] = true;
}
void gotTouch2() {
  touch[2] = true;
}
void gotTouch3() {
  touch[3] = true;
}
void gotTouch4() {
  touch[4] = true;
}
void gotTouch5() {
  touch[5] = true;
}
void gotTouch6() {
  touch[6] = true;
}
void gotTouch7() {
  touch[7] = true;
}
void gotTouch8() {
  touch[8] = true;
}
void gotTouch9() {
  touch[9] = true;
}

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<SK6822, 23, GRB>(leds, 1);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setRotation(3);
  display.cp437(true);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.println(F("ESP32Char Detection"));
  display.display();
  delay(2000);
  display.clearDisplay();
  
  touchAttachInterrupt(T8, gotTouch0, threshold);
  touchAttachInterrupt(T6, gotTouch1, threshold);
  touchAttachInterrupt(T5, gotTouch2, threshold);
  touchAttachInterrupt(T4, gotTouch3, threshold);
  touchAttachInterrupt(T1, gotTouch4, threshold);
  touchAttachInterrupt(T9, gotTouch5, threshold);
  touchAttachInterrupt(T7, gotTouch6, threshold);
  touchAttachInterrupt(T3, gotTouch7, threshold);
  touchAttachInterrupt(T0, gotTouch8, threshold);
  touchAttachInterrupt(T2, gotTouch9, threshold);
}

void loop() {
  for(int i=0;i<5;i++){
    for(int j=5;j<10;j++){
      if(touch[i] && touch[j]){
        touch[i] = false;
        touch[j] = false;
        touch_detected(i,j-5);
      }
    }
  }
//////////////////////////////////////////////////////////////////
/*
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 70);
  display.println(F("New Pattern saved."));
  display.display();
  delay(2000);
  display.clearDisplay();
*/
}

void touch_detected(int tR, int tC){
  tempPattern[1][tR][tC] = '*';
  display.fillRect(tR*7, tC*7, 5, 5, WHITE);
  display.display();
}
