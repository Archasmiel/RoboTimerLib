// Action.h

#ifndef ACTION_H
#define ACTION_H

enum ActionType {
    ACTION,
    DELAY
};

class ActionBase {
public:
    virtual ~ActionBase() {}
    virtual void execute() = 0;
    virtual unsigned long getDelay() = 0;
    virtual ActionType getType() = 0;
};

class Action : public ActionBase {
public:
    unsigned long delay;
    void (*func)();

    Action(void (*func)()) : func(func), delay(0) {}

    void execute() override {
        if (func) func();
    }

    unsigned long getDelay() override {
        return delay;
    }

    ActionType getType() override {
        return ACTION;
    }
};

class Delay : public ActionBase {
private:
    unsigned long delayTime;

public:
    Delay(unsigned long delayTime) : delayTime(delayTime) {}

    void execute() override {
        // Delay does nothing when executed
    }

    unsigned long getDelay() override {
        return delayTime;
    }

    void setDelay(unsigned long newDelay) {
        delayTime = newDelay;
    }

    ActionType getType() override {
        return DELAY;
    }
};

#endif // ACTION_H
