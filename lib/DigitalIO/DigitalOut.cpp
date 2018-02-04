#include "DigitalOut.h"
#include <Arduino.h>

// The main object
DigitalOut::DigitalOut(int pinNumber, int value) {
    m_state = value;
    // Mega type baords
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // Nano & Uno type baords
    #elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__)
    m_mod = pinNumber / 8;
    m_rem = pinNumber % 8;
    switch (m_mod) {
        case 0: {port = &PORTD; pm = &DDRD; break;}
        case 1: {port = &PORTB; pm = &DDRB; break;}
    }
    #endif
    // Direct set the pin mode to be writeable
    bitWrite(*pm, m_rem, 1);
    // Direct write to the port and bit with the state of the object
    bitWrite(*port, m_rem, m_state);
}

DigitalOut::~DigitalOut() {
}

// Overriding =
int DigitalOut::operator= (int s) {
    // Sets the state
    m_state = s;
    // Direct write to the port and bit with the state of the object
    bitWrite(*port, m_rem, m_state);
    // Returns the state though I'm not sure this is needed.
    return m_state;
}
