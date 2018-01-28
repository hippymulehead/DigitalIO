#include <Arduino.h>
#include <DigitalIO.h>

DigitalOut led1(13,0);

unsigned long lastm = 0;
unsigned long thism = 0;
unsigned long diff = 0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    lastm = micros();
    led1 = !led1;
    thism = micros();
    diff = thism - lastm;
    Serial.print(diff);
    Serial.print(", ");
    delay(200);
}
