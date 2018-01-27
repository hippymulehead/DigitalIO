#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);

void setup() {
    Serial.begin(115200);
}

void loop() {
    led1 = !led1;
    Serial.print(led1.state);
    delay(100);
}
