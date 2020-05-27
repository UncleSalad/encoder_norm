#include "Arduino.h"
#define clkPin 2
#define datPin 3
volatile bool A, B;
int counter;
void encInterrupt()
{
  if (digitalRead(clkPin)) 
  {
    A = !digitalRead(datPin);
  }
  else 
  {
    B = !digitalRead(datPin);
    if (!A && B) counter++;
    if (A && !B) counter--;
  }
}
void setup()
{
  Serial.begin(9600);
  pinMode(clkPin, INPUT_PULLUP);
  pinMode(datPin, INPUT_PULLUP);
  attachInterrupt(0, encInterrupt, CHANGE);
}
            
void loop()
{
  Serial.println(counter);
  delay(100);
}
