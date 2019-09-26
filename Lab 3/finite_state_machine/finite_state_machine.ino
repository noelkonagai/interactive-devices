/*
 Finite State Machine
 
 created 25 Sep 2019
 by Noel Konagai
 modified from switchCase2 by WendyJu
 */

#include <EEPROM.h>

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
const int sensorMin = 0;
const int sensorMax = 1024;
const int EEPROMSIZE = 1024;

// Input pin for softpot
int buttonPin = 2;
int sensorPin = 0;
int ledPin = LED_BUILTIN;    
int state,lastState = -1;
int buttonState = 0;
int recorded[];

void setup() {
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
    }
  // Initialize serial communication
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  display_message("Hello!");
  
  // map the pot range to number of states :
  state = map(analogRead(sensorPin), sensorMin, sensorMax, 0, numStates);

//  Serial.println(analogRead(sensorPin));
//  delay(100);

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("HIGH");
    display_message("Recording...");
    recording();
    delay(100);
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
  while(recorded.length < 10){
    rec = recorded.copyOf(arr, arr.length + 1);
    rec[rec.length - 1] = ;
    recorded
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
