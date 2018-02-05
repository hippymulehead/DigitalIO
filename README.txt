Fast and easy DigitalIO for Arduino.

DigitalIO sets up ins and outs as objects so the setup code from digitalWrite and digitalRead only has to be done once.
The way the code works is functionally like the DigitalOut DigitalIn from MBED.
This increases the speed of the calls by a lot!

All boards supported by Arduino ahouls now be working.

Usage:

DigitalOut:

To define a new DigitalOut
    DigitalOut led1(13,0);** // That's pin to do the DigitalIO on and the initial value.  No more setup is needed.

To set the pin high
    led1 = HIGH;

To set the pin low
    led1 = LOW;

To invert the pin
    led1 = !led1;

To copy the state of a pin to another pin
	led1 = led2.read();

DigitalIn:

To define a new DigitalIn
	DigitalIn button1(5);  // The pin to read from;

To read simply call
	int myvar = button1;

To assign to a DigitalOut
led1 = button1.read();

---
Blinky from MBed

```
#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);

void setup() {
}

void loop() {
    led1 = !led1;
    delay(100);
}
```

---

Read a button and assign it to an LED.

```
#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);
DigitalIn button1(5);

void setup() {
}

void loop() {
    led1 = button1.read();
}
```
