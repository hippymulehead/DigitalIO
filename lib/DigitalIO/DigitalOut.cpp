#include "DigitalOut.h"
#include <Arduino.h>

DigitalOut::DigitalOut(int pinNumber, int value) {
    pinMode(pinNumber,OUTPUT);
    state = value;
    if (pinNumber < 8) {
        port = &PORTD;
        pin = pinNumber;
    } else {
        port = &PORTB;
        pin = pinNumber - 8;
    }
    bitWrite(*port, pin, state);
}

DigitalOut::~DigitalOut() {
}

DigitalOut DigitalOut::operator= (int s) {
    state = s;
    bitWrite(*port, pin, state);
    return *this;
}

int DigitalOut::operator! () const {
    //state = !state;
    //bitWrite(*port, pin, state);
    return !state;
}

void DigitalOut::write(int value) {
    bitWrite(*port, pin, value);
}
