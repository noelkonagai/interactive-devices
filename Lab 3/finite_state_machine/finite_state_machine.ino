/*
 Finite State Machine
 
 created 25 Sep 2019
 by Noel Konagai
 modified from switchCase2 by WendyJu
 */

#include <EEPROM.h>
#include "pitches.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int numStates = 3;
const int EEPROMSIZE = 1024;
 
int redPin = 13;
int greenPin = 12;
int bluePin = 11;

int buttonPin = 2;
int sensorPin = A0;

int state,lastState = -1;
int buttonState = 0;
int rgbValue[30];

int rValue[10];
int gValue[10];
int bValue[10];

void setup() {
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
    }
  // Initialize serial communication
  Serial.begin(9600);  
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop() {
  display_message("hello!");

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("HIGH");
    recording();     
    playback();  
    }

//  switch (state) {
//  case 0:    
//    doState0();
//    break;
//  case 1:    
//    doState1();
//    break;
//  case 2:    
//    doState2();
//    break;
//  } 
//  lastState = state;

}

int recording(){
  display_message("Recording red.");
  delay(1000);
  display_message("Ready?");
  delay(750);
  display_message("Set.");
  delay(750);
  display_message("Record!");
  delay(200);
  for(int i = 0; i < 10; i++){
    int rMapped = map(analogRead(sensorPin), 0, 1023, 0, 255);
    rgbValue[i] = rMapped;
    Serial.println(rgbValue[i]);
    display.clearDisplay();
    display.setCursor(0,12);
    display.println(rgbValue[i]);
    display.display();
    delay(500);
  }
  
  
  display_message("Recording green.");
  delay(1000);
  
  for(int i = 10; i < 20; i++){
    int gMapped = map(analogRead(sensorPin), 0, 1023, 0, 255);
    rgbValue[i] = gMapped;
    Serial.println(rgbValue[i]);
    display.clearDisplay();
    display.setCursor(0,12);
    display.println(rgbValue[i]);
    display.display();
    delay(500);
  }

  display_message("Recording blue.");
  delay(1000);
  
  for(int i = 20; i < 30; i++){
    int bMapped = map(analogRead(sensorPin), 0, 1023, 0, 255);
    rgbValue[i] = bMapped;
    Serial.println(rgbValue[i]);
    display.clearDisplay();
    display.setCursor(0,12);
    display.println(rgbValue[i]);
    display.display();
    delay(500);
  }
}

void display_message(String message) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(message);
  display.display();
}

void playback() {
  display_message("Playing back RGB values");
  
  for(int i = 0; i < 10; i++){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("RGB Values");
    
    setColor(rgbValue[i], rgbValue[i+10], rgbValue[i+20]);
    delay(1000);
    setColor(0, 0, 0);
    delay(500);
    Serial.println(i);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}
