#include <Arduino.h>
#include <DigitalIO.h>

// Define a pair of DigitalOut objects for testing
DigitalOut led1(13,0);
DigitalOut led2(5,1);

void setup() {
    // Start Serial so we can check the state
    // And print to the terminal
    Serial.begin(115200);
}

void loop() {
    // This assigns the state of led1 to not led1 and then writes
    led1 = !led1;
    // Gets the state of led1 and prints it to the terminal
    Serial.println(led1);
    // Sets the state of led2 to that of led1
    // When doing this you need to use the state() function
    // I can't figure out how to get the object to return
    // an int via = to another object.
    // C++ gets pissy about that.
    led2 = !led1.state();
    // Short delay
    delay(100);
}
