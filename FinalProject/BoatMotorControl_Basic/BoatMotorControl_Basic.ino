/*Project Name: Skimpedo
 * Creators: Tyler Bershad 
 * Arduino Code Developer: Tyler Bershad
 * Last Modified: 11/17/2022
 * Description: This code is to confirm the electronic speed controller (ESC) works at a bare minimum level.
 
 THIS CODE DOES NOT WORK YET
 Tutorial: https://howtomechatronics.com/tutorials/arduino/arduino-brushless-motor-control-tutorial-esc-bldc/
 */
 
#include <Servo.h>
Servo ESC;     // create servo object to control the ESC

int setVal = 0;
float correctedVal = 0.0;
int KT = 2850; //rpm per volt
float rpm = 0.0;

void setup() {
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);
}

void loop() {
  //potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  //potValue = map(setValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  //voltageValue = potValue * (5.0/180.0); 
  setVal = 0; //Input number here
  ESC.write(setVal);
  rpm = KT*setVal;
  Serial.println(rpm);
  delay(3000);

  setVal = 0; //Input number here
  correctedVal = setVal*(180/1023);
  ESC.write(correctedVal);
  rpm = KT*setVal;
  Serial.println(rpm);
  delay(100000);
}
  

    
  
  //Sweep the speed (CAUTION: Motor gets super hot.
//  // set the ESC_Speed of pin 9:
//  ESC.write(ESC_Speed);
//  Serial.println(ESC_Speed);
//  // change the ESC_Speed for next time through the loop:
//  ESC_Speed = ESC_Speed + ESC_Acceleration;
//
//  // reverse the direction of the fading at the ends of the fade:
//  if (ESC_Speed <= 0 || ESC_Speed >= ESC_maxValue) {
//    ESC_Acceleration = -ESC_Acceleration;
//  }
//  // wait for 30 milliseconds to see the dimming effect
//  delay(100);
 
