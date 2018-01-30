#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);
DigitalOut led2(5,1);
//DigitalIn button1(4);

void setup() {
    Serial.begin(115200);
}

void loop() {
    led1 = !led1;
    Serial.println(led1);
    led2 = led1;
//    led2 = button1;
    delay(100);
}
