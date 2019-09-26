# Data Logger (and using cool sensors!)

*A lab report by Noel Konagai.*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

The analog values change between 0 and 1023, in other words they have a 10 bit value.
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

10 bits.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

I connected the RGB LED to pins 9, 10, 13, and each of the colored legs to a resistance of 1kOhm. Despite that, the LED was too bright to discern better the colors so I used a photoresistor for the red leg to see if the red will appear dimmer. It somehow did appear dimmer, but I was not convinced.

[Link to video](https://photos.app.goo.gl/MV5qYjsxaNbFD8Y28)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

After converting the analog to digital reading to voltages, I was able to get values between 0.1 to 3.8Vs. I was not able to exert enough force to get closer to 5V.

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

At a glance it seems to be logarithmic, but it is hard to tell as it is hard to exert a force that is constantly increasing. All things considered, it is a positive correlation.

[Link to Color LED code](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/led_color.ino)

![FSR Reading Image](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/Screen%20Shot%202019-09-21%20at%207.15.38%20PM.png)

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes. I used the input from the FSR coming in at A0 pin, mapped it to range between 0 and 255, and wrote it to the LED pin. Below the code snippet demonstrates this.

```java
fsrReading = analogRead(fsrPin);
fsrLED = map(fsrReading, 0, 1023, 0, 255);   
analogWrite(led, fsrLED);
```
Link to FSR Fading LED [code](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/fsr_led_fade.ino)
Link to [video](https://photos.app.goo.gl/nKdNUExjPa1w256cA)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

Photo cell needed about 2kOhm of resistance and the help of my Phone's flashlight. 

Softpot needed 10kOhm of resistance.

Flex sensor needed 25kOhm of resistance.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

Photo cell increases its resistance when it's darker, thus with the brightness the resistance has an inverse relationship.

As for the softpot, its resistance has a linear relationship to the distance from the touching point to the connected end.

The flex sensor's resistance decreases as it is bent forwards, and it increases as it is bent backwards.

### Part D. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

First to the LCD screen I write the acceleration values.
```java
lcd.clear();
lcd.setCursor(0,0);
lcd.print("X:"); lcd.print(event.acceleration.x); lcd.print(" ");
lcd.print("Y:"); lcd.print(event.acceleration.y); lcd.print(" ");
lcd.setCursor(0,1);
lcd.print("Z:"); lcd.print(event.acceleration.z);
```

Then I map the acceleration values to the range of 0 to 255. Here I gave -10 and 10 or 20 as the bounding edges, because by inspection the acceleration values didn't exceed these values, but this also meant that at the upper and lower ends of the 0-255 range I will not get RGB values. Then I set the color of the LED using these values.

```java
x = map(event.acceleration.x, -10, 10, 0, 255);
y = map(event.acceleration.y, -10, 10, 0, 255);
z = map(event.acceleration.z, -10, 20, 0, 255);

Serial.print(x); Serial.print(","); Serial.print(y); Serial.print(","); Serial.print(z); Serial.println();

setColor(x, y, z);
```

Link to [code](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/accelerometer_LED.ino)

Link to [video](https://photos.app.goo.gl/5LgmESzC5Gz6ThMq5)

## Part E. Graphic Display

**Modify the example code so that you can print out the output of the A0 pin. Include your code in your lab report.**

I created a loop where the A0 pin is read and it gets dipsplayed to the OLED.

```java
void loop() {
  sensorValue = analogRead(sensorPin);
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Analog 0:");
  display.setCursor(0, 12);
  display.println(sensorValue);
  Serial.print(sensorValue);
  display.display();

}
```

![Image of OLED](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/OLED_analog0.jpg)

## Part F. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

The order does matter. Let's say we switch up clear/write/read to a different order write/clear/read then we would not be able to read what we wrote.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

Because we only want to clear/write/read once every time that state is triggered. Otherwise, imagine a scenario when one loops over writing and manages to change states while the writing hasn't been finished. This would probably read to erroneous writing of the string.

**c. How many byte-sized data samples can you store on the Atmega328?**

You can write 1024 byte-sized data samples on Atmega328.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

A byte-sized data is equal to 8 bits, this means a value that is in the range of 0-255. We can use the map function to map the analog reading of 0-1023 to 0-255. As for I2C devices, we would need to figure out the range in which the reading value varies and map it to 0-255.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

You can use the EEPROM.put() function, which allows to write data of primitive types or struct types. When the data is bigger it can store it in consecutive addresses.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

The analog values were printed back to the Arduino Serial Monitor with ```Serial.println(analogRead(sensorPin));```.

Link to [code](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%203/switch_state/SwitchState2.ino)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
