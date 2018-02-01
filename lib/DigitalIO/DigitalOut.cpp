#include "DigitalOut.h"
#include <Arduino.h>

// The main object
DigitalOut::DigitalOut(int pinNumber, int value) {
    // FIXME Sets the pin to output mode
    pinMode(pinNumber,OUTPUT);
    // Sets the initial state
    m_state = value;
    // FIXME Creates a pointer to the port for the writes
    // and sets the bit number to write to
    if (pinNumber < 8) {
        port = &PORTD;
        pin = pinNumber;
    } else {
        port = &PORTB;
        pin = pinNumber - 8;
    }
    // Direct write to the port and bit with the state of the object
    bitWrite(*port, pin, m_state);
}

DigitalOut::~DigitalOut() {
}

// Overriding =
int DigitalOut::operator= (int s) {
    // Sets the state
    m_state = s;
    // Direct write to the port and bit with the state of the object
    bitWrite(*port, pin, m_state);
    // Returns the state though I'm not sure this is needed.
    return m_state;
}
