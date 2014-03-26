motion_sensor_diy
=================

Electronic schematics for RF motion sensor that uses Arduino as receiver hub


Instructions
=================

The eagle schematics show the wiring for the Motion Sensor and the Receiver. Each is very simple, here is the run down:

<h1>Motion sensor + RF transmitter</h1>

<strong>Components</strong>
<ul>
<li><a href="https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=6&cad=rja&uact=8&ved=0CDkQFjAF&url=http%3A%2F%2Fwww.mpja.com%2Fdownload%2F31227sc.pdf&ei=8FgzU868GsHLsQSTnYKIDg&usg=AFQjCNELdcZfKHaZhM4NlzFmhzu2_fOHwg&sig2=eFrgkllWo_47kU5vjeJpJA&bvm=bv.63738703,d.cWc">PIR sensor</a>, on <a href="http://www.amazon.com/HC-SR501-Sensor-Module-Pyroelectric-Infrared/dp/B007XQRKD4">Amazon</a> or <a href="http://www.ebay.com/itm/10pcs-HC-SR501-Adjust-IR-Pyroelectric-Infrared-PIR-Motion-Sensor-Detector-Module-/131028677440?pt=LH_DefaultDomain_0&hash=item1e81eaf340">Ebay</a></li>
<li><a href="http://www.100y.com.tw/pdf_file/PT2262-IRS.PDF">PT2262 encoder</a></li>
<li><a href="http://www.atmel.com/images/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf">ATtiny85</a></li>
<li><a href="http://www.amazon.com/433Mhz-transmitter-receiver-your-Experiment/dp/B00AMB3NCY">434 MHz RF transmitter</a></li>
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
