#include <Keyboard.h>

void setup() {

 Keyboard.begin(); //start keyboard communication 
  delay(600);
  Keyboard.press(KEY_LEFT_GUI);
  delay(600); 
  Keyboard.press('r');
  delay(600); 
  Keyboard.release(KEY_LEFT_GUI);
  delay(600);
  Keyboard.press('c');
  delay(600);
  Keyboard.press('m');
  delay(600);
  Keyboard.press('d');
  delay(600);
  Keyboard.release('c');
  delay(600);
  Keyboard.release('m');
  delay(600);
  Keyboard.release('d');
  delay(600);
  Keyboard.press(KEY_RETURN);
  delay(600);
  Keyboard.release(KEY_RETURN);
  delay(600); 
  Keyboard.println("shutdown -r -f -t 10"); // restart command after 10 seconds with force flag
  Keyboard.press(KEY_RETURN);
  delay(600);
  Keyboard.release(KEY_RETURN);
  Keyboard.end();

}

void loop() {
}
