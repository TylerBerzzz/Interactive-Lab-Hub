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
//Motor:
Servo ESC;     // create servo object to control the ESC
//Joystick:
uint8_t Address = 0x20; //Start address (Default 0x20)
JOYSTICK joystick; //Create instance of this object

//motor Parameters:
int setVal = 0;
float correctedVal = 0.0;
int KT = 2850; //rpm per volt
float rpm = 0.0;

void setup() {
  Serial.begin(9600); //begin serial communication
  
  // Attach the ESC on pin 6
  ESC.attach(6,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  
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
int Y_pos = 20; //Y speed must be equal to 20 during baseline.

void loop() {
  //Servo will be controlled by the X-DIR joystick.
  int X = joystick.getHorizontal();
  // Motor will be controlled by the Y-DIR Joystick.
  int Y = joystick.getVertical();
  //Joystick button will be used for homing
  int B = joystick.getButton();
  //Serial.println(X);

  //Motor:
  if (Y < 510){
    if (Y < 10){
      Y_pos = Y_pos - 5;
      ESC.write(Y_pos);
      delay(100); 
    }
  } 
  if (Y > 510){
    if (Y > 1020){
      Y_pos = Y_pos +5;
      ESC.write(Y_pos);
      delay(100);
    }
  }

  //Prevent the motor from going over its maximum range
  if(Y_pos > 150){
    Y_pos = 150; 
  }

  if(Y_pos < 20){
    Y_pos = 20;
  }

  //Servo motor:
  if (X < 494){
    if (X < 10){
      X_pos = X_pos - 5;
      myservo.write(X_pos);
      delay(50); 
    }
  } 
  if (X > 494){
    if (X > 1020){
      X_pos = X_pos +5;
      myservo.write(X_pos);
      delay(50);
    }
  }

  //If the joystick is clicked, go to the baseline set value
  if (B==0){
    X_pos = 90;
    Y_pos = 0;
    myservo.write(X_pos);
    ESC.write(Y_pos);
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
  Serial.print("(X,Y): ");
  Serial.print(X_pos);
  Serial.print(",");
  Serial.println(Y_pos);

}
