#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

void humanType(String text, int speedMin = 40, int speedMax = 120) {
  for (int i = 0; i < text.length(); i++) {
    Keyboard.print(text[i]);
    delay(random(speedMin, speedMax));
  }
}

void openRun() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(600);
}

void setup() {
  USB.begin();
  Keyboard.begin();

  delay(4000);  // wait for USB enumeration

  // --- Open Notepad ---
  openRun();
  humanType("notepad");
  Keyboard.write(KEY_RETURN);

  delay(1000);

  humanType("YOU GOT HACKED, DUMMY!");
  Keyboard.write(KEY_RETURN);
  delay(1500);

  // --- Open Browser Safely ---
  openRun();
  humanType("msedge https://crus.live/dashboard");
  Keyboard.write(KEY_RETURN);
}

void loop() {}
