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
    Serial.print(led1.state);
You can also use led1.write(value) to bypass the internal state
saving and just use it as a replacement for digitalWrite().
*/

class DigitalOut {
    public:
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        DigitalOut operator= (int s);
        DigitalOut operator! ();
        void write(int value);
        int state;

    protected:
        int pin;
        unsigned char *port;

    private:
};

#endif // DIGITALOUT_H
