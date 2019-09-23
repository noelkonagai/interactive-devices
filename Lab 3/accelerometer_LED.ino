#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

// RGB LED Vars
int redPin = 9;
int greenPin = 10;
int bluePin = 13;

int x;
int y;
int z;

void setup(void) {
  #ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
  #endif

  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");

  // LCD Setup
  lcd.begin(16, 2);
  // RGB LED Setup
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  /* Get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);

  // Write the x, y, z accelerations to the LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X:"); lcd.print(event.acceleration.x); lcd.print(" ");
  lcd.print("Y:"); lcd.print(event.acceleration.y); lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Z:"); lcd.print(event.acceleration.z);

  x = map(event.acceleration.x, -10, 10, 0, 255);
  y = map(event.acceleration.y, -10, 10, 0, 255);
  z = map(event.acceleration.z, -10, 20, 0, 255);
  
  Serial.print(x); Serial.print(","); Serial.print(y); Serial.print(","); Serial.print(z); Serial.println();

  setColor(x, y, z);
  delay(500);
 
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
