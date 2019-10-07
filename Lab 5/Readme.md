# Lab 5: Jack in a Box

Lab report submitted by Noel Konagai.

## The Iterative Process

For this lab, I wanted to create a box that opens upon a button press. The figure I included in the box was a 3D-printed bear. Initially, I wanted to integrate the button to the side of the box to make it completely autonomous. However, as I have already assembled the box and glued the sides together, I had to cut a hole to the assembled box. I was able to achieve this, but then I struggled to have the Arduino board stay fixed on the side of the box when the button was pressed. This way, I settled for having the arduino board with the button outside of the box.

## Your Arduino code

The code reads the input of the button press. Then it writes the servo positions based on whether the button was pressed. I used 40 degrees for the open position so that the lid would close with gravity rather than with external help. 

```java
void setup()
{
  //Serial.begin(9600);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  // start with the box closed and the switch in the off postion
  switchState = LOW;
  previousSwitchState = LOW;

  // connect to our servo and make sure it is in the closed position
  servo.attach(servoPin);
  servo.write(closePos);

  // we should probably pay attention to the switch
  pinMode(switchPin, INPUT); 
}

void loop()
{ 
  int switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState)
    ToggleSwitch(switchState);

  delay(20);
}
```

## The Bear

I used the .stl file from this [link](https://www.instructables.com/id/Laser-Cut-Bear/). Initially, I wanted to laser cut cardboards which I could put together into a figure like this bear. I was attempting to do so with Kirimoto, but the cardboard turned out to be too thick to create a realistic looking bear figure of such small size. Therefore, I opted for 3D printing. As it turns out, the weight of the head of the bear was heavy enough for it to require a dissolvable material as a support, which I did not think about. This way the chin of the bear loops droopy.

## The final box

The final box video can be found in this [link](https://photos.app.goo.gl/XyFJnoK1NbuPCiTu7)

![Working Box](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%205/images/jack.png)

The droopy bear:
![Droopy bear](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%205/images/droopy_bear.jpg)