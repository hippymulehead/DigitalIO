#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include <Arduino.h>

class DigitalOut {
    public:
        // Constructor
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        // Overriding = for simplicity
        int operator = (int s);
        // Overriding not for simplicity
        int operator ! () const {return !m_state;}
        // Returns an int when one is being asked for
        operator int() const {return m_state;}
        // Returns the state of the pin
        int read() {return m_state;}
        int m_mod;
        int m_rem;

    protected:

        volatile unsigned char *port;
        volatile unsigned char *pm;
        int m_state;

    private:
};

#endif // DIGITALOUT_H
