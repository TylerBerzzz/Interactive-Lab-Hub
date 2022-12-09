//Code Developed By: Tyler Bershad
//Last Modified:  12/1/2022
//Version: 2.0
//Description: The purpose of this script is send X/Y data from joystick to Other device over radio communication
//MCU = SAMD21


#include <SPI.h>

//Radio Head Library:
#include <RH_RF95.h> 

// We need to provide the RFM95 module's chip select and interrupt pins to the
// rf95 instance below.On the SparkFun ProRF those pins are 12 and 6 respectively.
RH_RF95 rf95(12, 6);

int LED = 13; //Status LED is on pin 13

int packetCounter = 0; //Counts the number of packets sent
long timeSinceLastPacket = 0; //Tracks the time stamp of last packet received

// The broadcast frequency is set to 921.2, but the SADM21 ProRf operates
// anywhere in the range of 902-928MHz in the Americas.

float frequency = 921.2; //Broadcast frequency


//Setup Joystick
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h" 
uint8_t Address = 0x20; //Start address (Default 0x20)
JOYSTICK joystick; //Create instance of this object

void setup()
{
  pinMode(LED, OUTPUT);

  SerialUSB.begin(9600);
  // It may be difficult to read serial messages on startup. The following line
  // will wait for serial to be ready before continuing. Comment out if not needed.
  while(!SerialUSB); 
  SerialUSB.println("RFM Client!"); 

  //Initialize the Radio.
  if (rf95.init() == false){
    SerialUSB.println("Radio Init Failed - Freezing");
    while (1);
  }
  else{
    //An LED inidicator to let us know radio initialization has completed. 
    SerialUSB.println("Transmitter up!"); 
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }

  // Set frequency
  rf95.setFrequency(frequency);

   // The default transmitter power is 13dBm, using PA_BOOST.
   // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then 
   // you can set transmitter powers from 5 to 23 dBm:
   // Transmitter power can range from 14-20dbm.
   rf95.setTxPower(14, false);

  //If there's a problem with joystick:
  if(joystick.begin(Wire, Address) == false)
  {
    SerialUSB.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
}


void loop()
{

    int X = joystick.getHorizontal();
    int correctedX = X-494;
    int Y = joystick.getVertical();
    int correctedY = Y-510;
    int B = joystick.getButton();

    SerialUSB.print("Joystick (X,Y): ");
    SerialUSB.print(correctedX);
    SerialUSB.print(",");
    SerialUSB.println(correctedY);
    if (B == 0)
    {
        SerialUSB.println("Button Pressed");
    }
  SerialUSB.println("Sending message");

  //Send a message to the other radio
  //when the button is pressed, send a 3
  if (B==0){
    uint8_t toSend[] = "3";
    rf95.send(toSend, sizeof(toSend));
    rf95.waitPacketSent();
  }
  //When the user is throttling up, turn fans on
  if (correctedX > 5){
    uint8_t toSend[] = "1";
    rf95.send(toSend, sizeof(toSend));
    rf95.waitPacketSent();
  }
  //When the user is not throttling up, send a 0.
  else{ 
    uint8_t toSend[] = "0";
    rf95.send(toSend, sizeof(toSend));
    rf95.waitPacketSent();
  }
  
//  uint8_t toSend[] = "";
//  //sprintf(toSend, "Hi, my counter is: %d", packetCounter++);
//  rf95.send(toSend, sizeof(toSend));
//  rf95.waitPacketSent();

  // Now wait for a reply
  byte buf[RH_RF95_MAX_MESSAGE_LEN];
  byte len = sizeof(buf);

  if (rf95.waitAvailableTimeout(2000)) {
    // Should be a reply message for us now
    if (rf95.recv(buf, &len)) {
      SerialUSB.print("Got reply: ");
      SerialUSB.println((char*)buf);
      //SerialUSB.print(" RSSI: ");
      //SerialUSB.print(rf95.lastRssi(), DEC);
    }
    else {
      SerialUSB.println("Receive failed");
    }
  }
  else {
    SerialUSB.println("No reply, is the receiver running?");
  }
  delay(10);
}
