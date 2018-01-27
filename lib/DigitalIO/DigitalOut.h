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
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        DigitalOut operator= (int s);
        DigitalOut operator! ();
        int state;
        void directWrite(int pinNumber, int value) {
            switch(pinNumber) {
                case 0: {bitWrite(PORTD,0,value);}
                case 1: {bitWrite(PORTD,1,value);}
                case 2: {bitWrite(PORTD,2,value);}
                case 3: {bitWrite(PORTD,3,value);}
                case 4: {bitWrite(PORTD,4,value);}
                case 5: {bitWrite(PORTD,5,value);}
                case 6: {bitWrite(PORTD,6,value);}
                case 7: {bitWrite(PORTD,7,value);}
                case 8: {bitWrite(PORTB,0,value);}
                case 9: {bitWrite(PORTB,1,value);}
                case 10: {bitWrite(PORTB,2,value);}
                case 11: {bitWrite(PORTB,3,value);}
                case 12: {bitWrite(PORTB,4,value);}
                case 13: {bitWrite(PORTB,5,value);}
            }
        }

    protected:
        int         pin;

    private:
};

#endif // DIGITALOUT_H
