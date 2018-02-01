#include "DigitalOut.h"
#include <Arduino.h>

DigitalOut::DigitalOut(int pinNumber, int value) {
    pinMode(pinNumber,OUTPUT);
    m_state = value;
    if (pinNumber < 8) {
        port = &PORTD;
        pin = pinNumber;
    } else {
        port = &PORTB;
        pin = pinNumber - 8;
    }
    bitWrite(*port, pin, m_state);
}

DigitalOut::~DigitalOut() {
}

int DigitalOut::operator= (int s) {
    m_state = s;
    bitWrite(*port, pin, m_state);
    return m_state;
}
