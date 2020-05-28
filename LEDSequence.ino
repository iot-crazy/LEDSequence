#include <Arduino.h>


int data = 0;   // set pin 14 of 74HC595as data input pin SI 
int clk = 5;    // set pin 11 of 74hc595 as clock pin SCK 
int latch = 4;  // set pin 12 of 74hc595 as output latch RCK int ledState = 0;
int outputEnable = 14; // which pin enabls the output on the shift register

long delayInterval = 100;  // the time delay between each step of the sequence


void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(outputEnable, OUTPUT);
}

void updateLEDs(int value)
{
  digitalWrite(outputEnable, HIGH);
  digitalWrite(latch, LOW);//
  shiftOut(data,clk,MSBFIRST,value);//serialdata “output”,highlevelfirst 
  digitalWrite(latch, HIGH);// latch
  digitalWrite(outputEnable, LOW);
}
int mapLength = 8;
int mapData[9] = {B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001};


void loop()
{
  for (int i = 0; i < mapLength; i++)
  {
    updateLEDs(mapData[i]);
    delay(delayInterval);
  }

  for (int i = mapLength-2; i > 0; i--)
  {
    updateLEDs(mapData[i]);
    delay(delayInterval);
  }
}
