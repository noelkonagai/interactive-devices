/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int fsrLED;     // the analog reading converted to voltage
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{ 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  fsrReading = analogRead(fsrPin);
  Serial.println(fsrReading);
  fsrLED = map(fsrReading, 0, 1023, 0, 255); 
  Serial.println(fsrLED);  

  analogWrite(led, fsrLED);
  
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
