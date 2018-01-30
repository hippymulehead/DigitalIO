MBed style DigitalIO for Arduino.

Curerently DigitalOut is written and working.  It uses direct port manipulation under the hood but only deals with PORTD & PORTB so it works on Uno and Nano styled boards.

Useage:

To define a new DigitalOut
    DigitalOut led1(13,0); // That's pin to do the DigitalIO on and the initial value.  No more setup is needed.

To set the pin high
    led1 = HIGH;

To set the pin low
    led1 = LOW;

To invert the pin
    led1 = !led1;

Per request you can also use led1.state to get the state of the pin.

-------------

You can also do a direct write without using the internal state by doing the following
    led1.write(HIGH);

-------------
//Blinky from MBed
#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);

void setup() {
}

void loop() {
    led1 = !led1;
    delay(100);
}
