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
            switch(pinNumber) {
                case 0: {bitWrite(PORTD,0,value); break;}
                case 1: {bitWrite(PORTD,1,value); break;}
                case 2: {bitWrite(PORTD,2,value); break;}
                case 3: {bitWrite(PORTD,3,value); break;}
                case 4: {bitWrite(PORTD,4,value); break;}
                case 5: {bitWrite(PORTD,5,value); break;}
                case 6: {bitWrite(PORTD,6,value); break;}
                case 7: {bitWrite(PORTD,7,value); break;}
                case 8: {bitWrite(PORTB,0,value); break;}
                case 9: {bitWrite(PORTB,1,value); break;}
                case 10: {bitWrite(PORTB,2,value); break;}
                case 11: {bitWrite(PORTB,3,value); break;}
                case 12: {bitWrite(PORTB,4,value); break;}
                case 13: {bitWrite(PORTB,5,value); break;}
            }
        }

    protected:
        int         pin;

    private:
};

#endif // DIGITALOUT_H
