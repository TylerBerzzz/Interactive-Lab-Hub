//Code Developed By: Tyler Bershad
//Last Modified:  11/22/2022
//Version: 2.0
//Description: The purpose of this script is to convert the X/Y joystick ranges into a logical range. The 0,0 (X,Y) point should be when the controller is in its static position.
//MCU = SAMD21

#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h" 

uint8_t Address = 0x20; //Start address (Default 0x20)
JOYSTICK joystick; //Create instance of this object

void setup() {
  SerialUSB.begin(9600);
  
  //If there's a problem:
  if(joystick.begin(Wire, Address) == false)
  {
    SerialUSB.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
}

void loop() {
    int X = joystick.getHorizontal();
    int correctedX = X-494;
    int Y = joystick.getVertical();
    int correctedY = Y-510;
    int B = joystick.getButton();

    //For noise purposes, shunt out values close to 0.
    if(correctedX < 5 && correctedX > -5){
      correctedX = 0;
    }
    if(correctedY < 5 && correctedY > -5){
      correctedY = 0;
    }
    SerialUSB.print("Joystick (X,Y): ");
    SerialUSB.print(correctedX);
    SerialUSB.print(",");
    SerialUSB.println(correctedY);
    if (B == 0)
    {
        SerialUSB.println("Button Pressed");
    }

  delay(10);
}
