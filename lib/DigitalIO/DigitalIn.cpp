#include <Arduino.h>
#include "DigitalIn.h"

// Constructor
DigitalIn::DigitalIn(int pinNumber) {
    // FIXME sets up the pin for reading
    pinMode(pinNumber,INPUT);
    // Creates a pointer to the port and sets up the bit number to read from
    if (pinNumber < 8) {
        port = &PORTD;
        pin = pinNumber;
    } else {
        port = &PORTB;
        pin = pinNumber - 8;
    }
}

DigitalIn::~DigitalIn() {

}
