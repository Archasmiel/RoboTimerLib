// RoboTimer.h

#ifndef ROBOTIMER_H
#define ROBOTIMER_H

#include <Arduino.h>
#include "Action.h"

class RoboTimer {
private:
    unsigned long previousMillis = 0;
    bool isRunning = false;
    int currentActionIndex = 0;
    int totalActions = 0;
    ActionBase** actions = nullptr;
    int capacity = 0;

    void resizeActions(int newCapacity);

public:
    RoboTimer();
    ~RoboTimer();

    void start();
    RoboTimer& addAction(void (*func)());
    RoboTimer& addDelay(unsigned long delay);
    void update();
    void stop();
    void setActionDelay(int index, unsigned long newDelay);
};

#endif // ROBOTIMER_H
