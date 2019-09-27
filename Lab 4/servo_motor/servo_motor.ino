/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 26 Sep 2019
 by Noel Konagai
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

float pos = 0;

int sensorPin = A0;    
int sensorValue = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  sensorValue = analogRead(sensorPin);
  myservo.write(map(analogRead(A0),0,1023,0,180));
}
