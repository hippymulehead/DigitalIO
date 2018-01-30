#include <Arduino.h>
#include "DigitalIn.h"

DigitalIn::DigitalIn(int pinNumber) {
    pinMode(pinNumber,INPUT);
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

DigitalIn::operator int() const {
    return bitRead(*port,pin);
}
