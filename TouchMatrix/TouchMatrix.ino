#define USE_NIMBLE
#include <BleKeyboard.h>
#include <FastLED.h>
#include "touchMatrix.h"

BleKeyboard bleKeyboard("TouchMatrix", "ElectroPoint4u", 100);
CRGB leds[1];

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Touch Matrix");
  FastLED.addLeds<SK6812, 23, GRB>(leds, 1);
  bleKeyboard.begin();
  leds[0] = CRGB::Red;
  FastLED.show();
}

void loop() {

  if (bleKeyboard.isConnected()) {
    leds[0] = CRGB(100, 0, 0);
    FastLED.show();
    touchRead();
    delay(100);
  }
  else {
    leds[0] = CRGB(100, 0, 0);
    FastLED.show();
    delay(500);
    leds[0] = CRGB(0, 0, 0);
    FastLED.show();
    delay(500);
  }
}

void touch_detected(int touch) {
  Serial.println(touch);
  leds[0] = CRGB::Blue;
  FastLED.show();

  switch (touch) {
    case 11:
      bleKeyboard.write(KEY_LEFT_ARROW);
      break;
    case 12:
      bleKeyboard.write(KEY_UP_ARROW);
      break;
    case 13:
      bleKeyboard.write(KEY_BACKSPACE);
      break;
    case 14:
      bleKeyboard.write(KEY_DOWN_ARROW);
      break;
    case 15:
      bleKeyboard.write(KEY_RIGHT_ARROW);
      break;

    case 21:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('A');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 22:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('C');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 23:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('X');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 24:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('V');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 25:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('Z');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 31:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('L');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 32:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('O');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 33:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('B');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 34:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('R');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 35:
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F5);
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 41:
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('H');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 42:
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('V');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 43:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('Q');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 44:
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('M');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 45:
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('B');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 51:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('L');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 52:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('V');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 53:
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('X');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 54:
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('U');
      delay(100);
      bleKeyboard.releaseAll();
      break;
    case 55:
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('P');
      delay(100);
      bleKeyboard.releaseAll();
      break;
  }
}
