#include <Arduino.h>
#include "DigitalIn.h"

// Constructor
DigitalIn::DigitalIn(int pinNumber) {
    // Mega type baords
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // Nano & Uno type baords
    #elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168P__)
    m_mod = pinNumber / 8;
    m_rem = pinNumber % 8;
    switch (m_mod) {
        case 0: {
            port = &PORTD;
            pm = &DDRD;
            break;
        }
        case 1: {
            port = &PORTB;
            pm = &DDRB;
            break;
        }
    }
    #endif
    // Direct set the pin mode to be writeable
    bitWrite(*pm, m_rem, 0);
}

DigitalIn::~DigitalIn() {

}
