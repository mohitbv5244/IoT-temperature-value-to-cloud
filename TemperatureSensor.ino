/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
#include <IoTkit.h>    // include IoTkit.h to use the Intel IoT Kit
#include <Ethernet.h>  // must be included to use IoTkit
#include <aJSON.h>
#include <stdio.h>
#include <Wire.h>

IoTkit iotkit;

#include "rgb_lcd.h"
rgb_lcd lcd;
const  int ledpin2 = 3;
const int pinTemp = A0;
const int colorR = 255;
const int colorG = 05;
const int colorB = 15;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  iotkit.begin();
  // initialize digital pin 13 as an output.
  lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
  pinMode(13, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  //const int pinTemp = A0; 
//float temperature;
//pinMode(pinTemp, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  lcd.setCursor(1, 0);
float temperature = analogRead(pinTemp);
 iotkit.send("measureTemp",temperature);
  if(temperature < 25)
  {
    iotkit.send("measureTemp",temperature);
  digitalWrite(13, LOW);
  digitalWrite(ledpin2, LOW);
  lcd.print("yes");
  delay(2000);
  lcd.clear();
  // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  }
  else
  {
    iotkit.send("measureTemp",temperature);
  digitalWrite(13, HIGH);
  delay(5000); 
  digitalWrite(ledpin2, HIGH);
  lcd.print("no");
   delay(2000);
  lcd.clear();// turn the LED off by making the voltage LOW
  delay(1000); 
  lcd.print(temperature);
  delay(5000);
  lcd.clear();// turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  }
  delay(5);
}
