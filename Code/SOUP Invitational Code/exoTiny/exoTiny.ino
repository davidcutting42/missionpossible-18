/**
    Exothermic Action - Mission Possible MK2
    Ward Melville HS Science Olympiad - Team A - 2017-2018
    exoTiny.ino
    Purpose: Triggers the next action when the resistance of a photocell changes more than a threshold value.

    @author David Cutting
    @version 1.1 1/26/2018
*/

// Definitions for microcontroller pin numbers
const int photocellPin = 1;
const int outPin = 4;

// Variables for states of the pins
int photocellValue;
int photocellBase;
bool statusOut = LOW;

void setup() {
  // Set the microcontroller pins as either inputs or outputs
  pinMode(photocellPin, INPUT);
  pinMode(outPin, OUTPUT);

  // Set the output pin to low
  digitalWrite(outPin, LOW); // Write the output pin to LOW

  // Read the initial value of the photocell (ambient light)
  photocellBase = analogRead(photocellPin);
}

void loop() {
  photocellValue = analogRead(photocellPin);
  
  if(photocellValue - photocellBase >= 200 && statusOut == LOW) { 
    // If the difference (NOT ABSOLUTE VALUE) between the current reading and the ambient reading is greater than the threshold...
    delay(500); // Delay 500 milliseconds (0.5 s) to allow observation
    statusOut = HIGH;
    digitalWrite(outPin, HIGH); // Trigger the next action
  }
}
