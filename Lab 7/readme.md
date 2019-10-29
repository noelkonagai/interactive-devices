# Video Doorbell, Lab 7

*A lab report by Noel Konagai*

### In This Report

1. Upload a video of your version of the camera lab to your lab Github repository
1. As usual, update your class Hub repository to add your repository.
1. Answer the questions in-line below on your README.md.

## Part A. HelloYou from the Raspberry Pi

**a. Link to a video of your HelloYou sketch running.**
[Link to video](https://photos.app.goo.gl/mDDVWGNKWpuW4vf26)

## Part B. Web Camera

**a. Compare `helloYou/server.js` and `IDD-Fa18-Lab7/pictureServer.js`. What elements had to be added or changed to enable the web camera? (Hint: It might be good to know that there is a UNIX command called `diff` that compares files.)**

We have a number of additions in ```pictureServer.js```, which could be summarized as follows.

First we required ```node-webcam```.

```java
var NodeWebcam = require( "node-webcam" );
```

Then we defined some options for the webcam, such as height and width of the image.

```java
var opts = { /*some options*/ }
```

And last, we initialized the webcam in the ```Webcam``` variable.

```java
var Webcam = NodeWebcam.create( opts );
```

**b. Include a video of your working video doorbell**

[Link to video](https://photos.app.goo.gl/hn5xKYqxRFPhLKr89)

## Part C. Make it your own

**a. Find, install, and try out a node-based library and try to incorporate into your lab. Document your successes and failures (totally okay!) for your writeup. This will help others in class figure out cool new tools and capabilities.**

*Things I have tried but did not work:*

I tried to emit audio using socket. This resulted to be way more complicated that I thought, and simply the audio would not work.

Server side Javascript:

```javascript
io.emit('play', { audio: '/public/audio/doorbell.mp3'});
```

Client side Javascript:

```javascript
socket.on('play', function (data) {
  document.getElementById('audioContainer').src=data
  console.log("Trying to play audio");
  console.log(data);
});
```

I also tried to improve on the camera image quality. According to some forums, if we skip the first few frames, the camera will adjust its brightness setting and we can get better images. I implemented a for loop, with which I was saving every 100th image, and well, it seems to work sometimes. Below is a comparison.

![Img1](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%207/images/image1.jpg) ![Img2](https://github.com/noelkonagai/interactive-devices/blob/master/Lab%207/images/image2.jpg)

However, if I leave this loop inside the code, it would take a long time to display it on the client side. So I had to remove it.

Last, because my audio attempt failed, I resorted to text display using the following code. For this I had to create a CSS file to make sure the text color is white.

```javascript
var x = document.createElement("h1");
var t = document.createTextNode("Someone is at the door");
x.appendChild(t);
document.body.appendChild(x); 
```

**b. Upload a video of your working modified project**

[Link to video](https://photos.app.goo.gl/ehgLtnJLzUje8XxH8)
