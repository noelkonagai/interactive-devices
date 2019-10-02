# Paper Puppets

*A lab report by Noel Konagai*

## Part A. Actuating DC motors

Link to working actuating DC motor [video](https://photos.app.goo.gl/s4vHXaPVV1zUkpjz8)

## Part B. Actuating Servo motors

### Part 1. Connect the Servo to your breadboard

**a. Which color wires correspond to power, ground and signal?**

Ground is brown, 5V is red, and signal is the yellow wire.

### Part 2. Connect the Servo to your Arduino

**a. Which Arduino pin should the signal line of the servo be attached to?**

In my case, it is pin 9. 

```java
myservo.attach(9)
```

[Link to code](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%204/servo_motor/servo_motor.ino)

**b. What aspects of the Servo code control angle or speed?**

The following for loop control the angle and the speed of the sweep.

```java
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
```

## Part C. Integrating input and output

**Include a photo/movie of your raw circuit in action.**

I integrated a softpot in my circuit with which I was able to indicate the angle of rotation through a swipe of a finger. 

[Link to video](https://photos.app.goo.gl/zv8Qy7W7KQK2uNfY8)

## Part D. Paper puppet

**a. Make a video of your proto puppet.**

[Link to video](https://photos.app.goo.gl/gRphAnbTgx9C5rct5)
I realized that the arms of my puppet are uneven. I was not sure at the time of shooting the video why that was the case. However, for Part E I fixed this.

## Part E. Make it your own

**a. Make a video of your final design.**
 
 [Link to video](https://photos.app.goo.gl/94jWSJfF5ymYshdx9)
 I combined the puppet and my previous code where I used a softpot input to control the sweep of the servo motor.
