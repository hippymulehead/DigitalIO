#include <Arduino.h>
#include "DigitalOut.h"

DigitalOut::DigitalOut(int pinNumber, int value) {
	m_bit = digitalPinToBitMask(pinNumber);
	m_port = digitalPinToPort(pinNumber);
	if (m_port == NOT_A_PIN) return;
    m_out = portOutputRegister(m_port);
    m_state = value;
    pinMode(pinNumber, OUTPUT);
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
}

DigitalOut::~DigitalOut() {
}

int DigitalOut::operator= (int s) {
    m_state = s;
    //bitWrite(*out, m_bit, m_state);
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
    return m_state;
}
