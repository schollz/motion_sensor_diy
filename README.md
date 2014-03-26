motion_sensor_diy
=================

Electronic schematics for RF motion sensor that uses Arduino as receiver hub


Instructions
=================

The eagle schematics show the wiring for the Motion Sensor and the Receiver. Each is very simple, here is the run down:

<h1>Motion sensor + RF transmitter</h1>

<strong>Components</strong>
<ul>
<li>PIR sensor</li>
<li>PT2262 encoder</li>
<li>ATtiny85</li>
<li>434 MHz RF transmitter</li>
<li>Several 500-1k Ohm resistors</li>
<li>LED (optional)</li>
</ul>

The motion sensor is simply a PIR sensor connected to a 434MHz RF transmitter via an encoder. The encoder uses four bits, in the form of resistors tied to HIGH (+VCC) or LOW (GND). That's enough for 12 sensors. 
The ATtiny85 is programmed via an Arduino which allows for devising a smart way of sending the RF data. It can be programmed to send the output as randomized timed sequences in order to reduce the conflicts of having other motion sensors on the same band.


<h1>RF Receiver</h1>

<strong>Components</strong>
<ul>
<li>Arduino</li>
<li>PT2272 encoder</li>
<li>434 MHz RF receiver</li>
</ul>

This circuit is even simpler. Connect the RF receiver output to the DIN of the PT2272. Then put each output pin (the four bits) into the Arduino pins 3-6. It's best to connect the VT (Viable Transmission indicator) pin of the PT2272 to the Pin 2 of the Arduino so that you can attach an interrupt on it. This way whenever VT goes high, the Arduino will read the other four pins and use that to determine which sensor is which (I leave this to you, though).
