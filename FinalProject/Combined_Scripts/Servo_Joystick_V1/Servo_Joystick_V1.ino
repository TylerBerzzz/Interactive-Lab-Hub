/*Project Name: Skimpedo
 * Creators: Tyler Bershad 
 * Arduino Code Developer: Tyler Bershad
 * Last Modified: 11/22/2022
 * Description: This code's purpose is to control the servo's position using the joystick.
 * This is to act as "steering" capabilities by moving a rudder.
 */
#include <Servo.h>
#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h" 

//Setup Control Equipment
//Servo:
Servo myservo;  // create servo object to control a servo
//Joystick:
uint8_t Address = 0x20; //Start address (Default 0x20)
JOYSTICK joystick; //Create instance of this object

int Val;    

void setup() {
  Serial.begin(9600); //begin serial communication
  //Attach the servo to the pin it's connected to
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //Make sure the joystick is working:
  if(joystick.begin(Wire, Address) == false)
  {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
  //Set the servo to its baseline position
  myservo.write(90); //90 Degrees shall be the baseline. 
  delay(1000);
  Serial.println("All systems GO");
}

int X_pos = 90; //X position must be initially equal to the baseline.

void loop() {
  //Servo will be controlled by the X-DIR joystick.
  int X = joystick.getHorizontal();
  //int correctedX = X-494; //Zero the joystick
  int B = joystick.getButton();
  //Serial.println(X);

  if (X < 494){
    if (X < 10){
      X_pos = X_pos - 5;
      myservo.write(X_pos);
      delay(100); 
    }
  } 
  if (X > 494){
    if (X > 1020){
      X_pos = X_pos +5;
      myservo.write(X_pos);
      delay(100);
    }
  }

  //If the joystick is clicked, go to the baseline set value
  if (B==0){
    X_pos = 90;
    myservo.write(X_pos);
    delay(1000);
  }
  //Prevent the servo from going over its maximum range
  if(X_pos > 165){
    X_pos = 165; 
  }

  if(X_pos < 5){
    X_pos = 5;
  }
  
  else{
    //nothing
  }
  //delay(100);  
  Serial.println(X_pos);
}
