# Fast and easy DigitalIO for Arduino.

DigitalIO makes it simple and fast.  It uses direct port manipulation under the hood but only deals with PORTD & PORTB so it works on Uno and Nano styled boards.

Usage:

## DigitalOut:

To define a new DigitalOut  
    **DigitalOut led1(13,0);** // That's pin to do the DigitalIO on and the initial value.  No more setup is needed.

To set the pin high  
    **led1 = HIGH;**

To set the pin low  
    **led1 = LOW;**

To invert the pin  
    **led1 = !led1;**

To copy the state of a pin to another pin
	**led1 = led2.state();**

## DigitalIn:

To define a new DigitalIn
	**DigitalIn button1(5);**  // The pin to read from;

To read simply call
	**myvar = button1;**

To assign to a DigitalOut
    **led1 = button1.state();**

---
**Blinky from MBed**

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

**Read a button and assign it to an LED.**

```
#include <Arduino.h>   
#include <DigitalIO.h>

DigitalOut led1(13,0);
DigitalIn button1(5);

void setup() {
}

void loop() {
    led1 = button1.state();
}
```
