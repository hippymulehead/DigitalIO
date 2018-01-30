#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include <Arduino.h>

/*
MBed styled digital outs for Arduino
Provided by Mike Romans of Romans Audio
Object creation
    DigitalOut led1(13);
Pin Control
    led1 = HIGH // Sets pin 13 to high
    led1 = !led1 // inverts pin 13
Viewing State
    tempint = led1;
Copy state from pin to pin
    led1 = led2;
You can also use led1.write(value) to bypass the internal state
saving and just use it as a replacement for digitalWrite().
*/

class DigitalOut {
    public:
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        DigitalOut operator= (int s);
        int operator! () const;
        operator int() const;

    protected:
        int pin;
        volatile unsigned char *port;
        int state;

    private:
};

#endif // DIGITALOUT_H
