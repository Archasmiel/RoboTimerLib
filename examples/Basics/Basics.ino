#include <RoboTimer.h>

RoboTimer timer;

// Example action that will be scheduled by the timer
void printMessage() {
    Serial.println("Hello from RoboTimer!");
}

void setup() {
    Serial.begin(9600);

    // Add an action and a delay, then start the timer
    timer.addAction(printMessage).addDelay(1000);  // 1000ms = 1 second
    timer.start();
}

void loop() {
    // Continuously update the timer
    timer.update();
}
