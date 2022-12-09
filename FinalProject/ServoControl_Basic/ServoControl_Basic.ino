/*Project Name: Skimpedo
 * Creators: Tyler Bershad 
 * Arduino Code Developer: Tyler Bershad
 * Last Modified: 11/17/2022
 * Description: This code is to confirm the micro servo works at a bare minimum level.
 
 THIS CODE WORKS
 */
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int Val;    

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  Val = 10;
  myservo.write(Val); //Set to baseline value
  delay(1000); 

  Val = 90;
  myservo.write(Val); //Set to baseline value
  delay(1000); 

  Val = 170;
  myservo.write(Val); //Set to baseline value
  delay(1000); 
  

}
