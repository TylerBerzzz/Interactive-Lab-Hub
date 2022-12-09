//Code Developed By: Tyler Bershad
//Last Modified:  11/22/2022
//Version: 1.0
//Description: This script's purpose is to show that data can be collected and printed in the serial USB line for the QWIIC Joystick.
//Acknowledgement: Version 1.0 is almost entirely copied from the Sparkfun Qwiic joystick library example.

#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h" 

uint8_t Address = 0x20; //Start address (Default 0x20)
JOYSTICK joystick; //Create instance of this object

void setup() {
  SerialUSB.begin(9600);

  if(joystick.begin(Wire, Address) == false)
  {
    SerialUSB.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
}

void loop() {
    int X = joystick.getHorizontal();
    int Y = joystick.getVertical();
    int B = joystick.getButton();
    SerialUSB.print(X);
    SerialUSB.print(",");
    SerialUSB.println(Y);
    if (B == 0)
    {
        SerialUSB.println("B");
    }
//    SerialUSB.println(B);
//    if  (X > 575)
//    {
//        SerialUSB.println("L");
//    }
//    else if (X < 450)
//    {
//        SerialUSB.println("R");
//    }
//
//    if  (Y > 575)
//    {
//        SerialUSB.println("U");
//    }
//    else if (Y < 450)
//    {
//        SerialUSB.println("D");
//    }
//
//    if (B == 0)
//    {
//        SerialUSB.println("Button");
//    }


  delay(10);
}
