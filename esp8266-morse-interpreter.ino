
#include "Morse.h"
void dash();
void dot();
Morse morse = Morse(dot, dash); //dot and dash will point our functions dot() and dash()
byte morsePin = 2;

void setup() {
  pinMode(morsePin, OUTPUT);
}

void loop() {
  morse.print("sos we need chocolate");
  delay(5000);

}

/*
  Function to be executed when morse finds a dash "-"
*/
void dash() {
  digitalWrite(morsePin, LOW);
  delay(morse.unit * 3);
  digitalWrite(morsePin, HIGH);
}

/*
  Function to be executed when morse finds a dot "."
*/
void dot()
{
  digitalWrite(morsePin, LOW);
  delay(morse.unit);
  digitalWrite(morsePin, HIGH);
}

