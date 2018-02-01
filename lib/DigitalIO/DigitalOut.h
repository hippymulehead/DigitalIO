#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include <Arduino.h>

class DigitalOut {
    public:
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        int operator = (int s);
        int operator ! () const {return !m_state;}
        operator int() const {return m_state;}
        int state() {return m_state;}

    protected:
        int pin;
        volatile unsigned char *port;
        int m_state;

    private:
};

#endif // DIGITALOUT_H
