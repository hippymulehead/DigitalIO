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
*/

class DigitalOut {
    public:
        DigitalOut(int pinNumber, byte value);
        virtual ~DigitalOut();
        DigitalOut operator= (byte s);
        DigitalOut operator! ();
        byte state;

        void directWrite(int pinNumber, byte value) {
            switch(p) {
                case 0: {
                    bitWrite(PORTD,p,value);
                    break;
                }
                case 1: {
                    bitWrite(PORTB, p, value);
                    break;
                }
            }
        }

    protected:
        int         pin;
        int         b;
        int         p;

    private:
};

#endif // DIGITALOUT_H
