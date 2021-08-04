#include <FastLED.h>

#define NUM_LEDS 9
#define DATA_PIN 16
CRGB leds[NUM_LEDS];

int threshold = 40;

bool touch1detected = false;
bool touch2detected = false;
bool touch3detected = false;
bool touch4detected = false;
bool touch5detected = false;
bool touch6detected = false;
bool touch7detected = false;
bool touch8detected = false;
bool touch9detected = false;

void gotTouch1() {
  touch1detected = true;
}
void gotTouch2() {
  touch2detected = true;
}
void gotTouch3() {
  touch3detected = true;
}
void gotTouch4() {
  touch4detected = true;
}
void gotTouch5() {
  touch5detected = true;
}
void gotTouch6() {
  touch6detected = true;
}
void gotTouch7() {
  touch7detected = true;
}
void gotTouch8() {
  touch8detected = true;
}
void gotTouch9() {
  touch9detected = true;
}


void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Touch Interrupt");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  LEDS.setBrightness(100);
  touchAttachInterrupt(T3, gotTouch1, threshold);
  touchAttachInterrupt(T2, gotTouch2, threshold);
  touchAttachInterrupt(T0, gotTouch3, threshold);
  touchAttachInterrupt(T9, gotTouch4, threshold);
  touchAttachInterrupt(T6, gotTouch5, threshold);
  touchAttachInterrupt(T5, gotTouch6, threshold);
  touchAttachInterrupt(T4, gotTouch7, threshold);
  touchAttachInterrupt(T7, gotTouch8, threshold);
  touchAttachInterrupt(T8, gotTouch9, threshold);
}

void loop() {
  if (touch1detected) {
    touch1detected = false;
    touch_light(0);
  }
  if (touch2detected) {
    touch2detected = false;
    touch_light(1);
  }
  if (touch3detected) {
    touch3detected = false;
    touch_light(2);
  }
  if (touch4detected) {
    touch4detected = false;
    touch_light(3);
  }
  if (touch5detected) {
    touch5detected = false;
    touch_light(4);
  }
  if (touch6detected) {
    touch6detected = false;
    touch_light(5);
  }
  if (touch7detected) {
    touch7detected = false;
    touch_light(6);
  }
  if (touch8detected) {
    touch8detected = false;
    touch_light(7);
  }
  if (touch9detected) {
    touch9detected = false;
    touch_light(8);
  }
}

void touch_light(int num){
  static uint8_t hue = 0;
    leds[num] = CHSV(hue++, 255, 255);
    FastLED.show();
    leds[num].nscale8(250);
    delay(10);
}
