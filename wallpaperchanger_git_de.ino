#include "DigiKeyboard.h"
#include "DigiKeyboardDe.h" // QWERTZ LAYOUT OF DIGIKEYBOARD LIBRARY, MUST BE INSTALLED

void setup(){
  pinMode(1, OUTPUT); // LED ON MODEL A
  }

void loop(){

  digitalWrite(1, HIGH);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke('r', MOD_GUI_LEFT);
  DigiKeyboard.delay(1500);
  DigiKeyboardDe.print(F("powershell"));
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboardDe.print(F("Set-PSReadlineOption -HistorySaveStyle SaveNothing")); // ONLY WORKS ON WINDOWS 10 
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("$vol = get-wmiobject -Class Win32_Volume | where{$_.SerialNumber -eq YOUR_SERIAL_NUMBER}")); // FILTER CONNECTED USB DEVICES BY SERIAL NUMBER
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("$dl = $vol.DriveLetter")); // GET DRIVE LETTER OF MATCHING USB DEVICE
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("$path = $dl + '/data/YOUR_IMAGE.jpeg'")); // WALLPAPER PATH
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH);
  DigiKeyboardDe.print(F("reg add 'HKEY_CURRENT_USER\\Control Panel\\Desktop' /v Wallpaper /t REG_SZ /d $path /f")); // DOES NOT REQUIRE ADMIN PRIVILEGES
  DigiKeyboard.delay(100);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("Yes")); // SOMETIMES POWERSHELL ASKS TO CONFIRM THE CHANGES
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("Set-ItemProperty 'HKCU:\\Control Panel\\Desktop' -Name “WallpaperStyle” -Value 6")); // CHANGE WALLPAPER MODE
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("Clear-History")); // CLEARS THE RUN HISTORY
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboardDe.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
  
  }
