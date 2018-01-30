#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(5,0);

void setup() {
}

void loop() {
    led1 = !led1;
    delay(100);
}
