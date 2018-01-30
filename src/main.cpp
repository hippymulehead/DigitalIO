#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);
DigitalOut led2(5,0);
DigitalIn button1(4);

void setup() {
}

void loop() {
    led1 = !led1;
    led2 = button1;
    delay(100);
}
