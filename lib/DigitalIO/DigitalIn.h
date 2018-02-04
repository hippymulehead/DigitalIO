#ifndef DIGITALIN_H
#define DIGITALIN_H

// Sets up the DigitalIn object
class DigitalIn
{
    public:
        // Constructor
        DigitalIn(int pinNumber);
        virtual ~DigitalIn();
        // Returns the state as an int.
        operator int() const {return bitRead(*port,pin);}
        // Returns the state to be coppied to a DigitalOut
        int read() {return bitRead(*port,pin);}

    protected:
        int pin;
        volatile unsigned char *port;
        volatile unsigned char *pm;
        int m_mod;
        int m_rem;

    private:
};

#endif // DIGITALIN_H
