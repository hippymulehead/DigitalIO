#ifndef DIGITALIN_H
#define DIGITALIN_H


class DigitalIn
{
    public:
        DigitalIn(int pinNumber);
        virtual ~DigitalIn();
        operator int() const;

    protected:
        int pin;
        volatile unsigned char *port;

    private:
};

#endif // DIGITALIN_H
