#include "DigitalOut.h"
#include <Arduino.h>

DigitalOut::DigitalOut(int pinNumber, byte value) {
    pin = pinNumber;
    pinMode(pin,OUTPUT);
    state = value;
    directWrite(pin, state);
}

DigitalOut::~DigitalOut() {
}

DigitalOut DigitalOut::operator= (byte s) {
    state = s;
    directWrite(pin, state);
    return *this;
}

DigitalOut DigitalOut::operator! () {
    state = !state;
    directWrite(pin, state);
    return *this;
}
