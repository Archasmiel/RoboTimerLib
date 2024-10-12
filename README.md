# RoboTimer Library

## Overview
RoboTimer is a flexible and easy-to-use Arduino library that helps you manage timed sequences of actions and delays in your projects. The library allows you to add custom actions (functions) or delays and execute them in sequence. It's perfect for robotics projects, animations, or any situation where you need timed events.

The library includes:
- The ability to add multiple actions and delays.
- Customizable delays between actions.
- Methods to start, stop, and update the sequence of actions.
- Modify action delays dynamically.

## Features
- **Simple API**: Easy to use for beginners and flexible enough for advanced projects.
- **Supports Custom Actions**: Add functions (actions) that will be executed in a specific timed sequence.
- **Dynamic Delays**: You can add delays between actions and change them on the fly.
- **Action Management**: Start, stop, and manage the sequence of actions.
  
## Installation

1. Download the library as a ZIP file or clone the repository.
2. In the Arduino IDE, go to `Sketch` -> `Include Library` -> `Add .ZIP Library...` and select the downloaded ZIP file.
3. Once added, you can include it in your Arduino sketches by adding `#include <RoboTimer.h>`.

## Example Usage

Here’s a basic example that demonstrates how to use the RoboTimer library to add actions and delays:

### Example: Blinking an LED with Delays
```cpp
#include <RoboTimer.h>

// Create an instance of RoboTimer
RoboTimer timer;

// Define a custom action (blinking an LED)
void blinkLED() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle the LED
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    // Add an action to blink the LED and a delay of 1000ms (1 second)
    timer.addAction(blinkLED).addDelay(1000);

    // Start the timer
    timer.start();
}

void loop() {
    // Update the timer to execute actions and delays
    timer.update();
}
```

### Example: More Complex Timing
```cpp
#include <RoboTimer.h>

RoboTimer timer;

void action1() {
    // Do something, like turn on a motor
}

void action2() {
    // Do something else, like turn off a motor
}

void setup() {
    // Add multiple actions and delays
    timer.addAction(action1).addDelay(500);  // Action 1 followed by 500ms delay
    timer.addAction(action2).addDelay(1000); // Action 2 followed by 1000ms delay

    timer.start();
}

void loop() {
    timer.update();
}
```

## API Reference

### Class: `RoboTimer`

The `RoboTimer` class provides a way to manage and execute actions and delays in a timed manner.

#### Constructor
- **`RoboTimer()`**
  - Initializes a new instance of the `RoboTimer` class.

#### Methods

- **`void start()`**
  - Starts the timer and resets the action index to 0.

- **`RoboTimer& addAction(void (*func)())`**
  - Adds an action to be executed by the timer.
  - **Parameters:**
    - `func`: A pointer to a function that takes no parameters and returns void.

- **`RoboTimer& addDelay(unsigned long delay)`**
  - Adds a delay between actions.
  - **Parameters:**
    - `delay`: The duration of the delay in milliseconds.

- **`void update()`**
  - Updates the timer, executing the current action if the delay period has elapsed.

- **`void stop()`**
  - Stops the timer and prevents any further actions from executing.

- **`void setActionDelay(int index, unsigned long newDelay)`**
  - Changes the delay of a specific action.
  - **Parameters:**
    - `index`: The index of the action in the list.
    - `newDelay`: The new delay duration in milliseconds.
  
### Class: `ActionBase` (Base class for actions)

#### Methods

- **`unsigned long getDelay()`**
  - Returns the delay time associated with the action.

- **`void execute()`**
  - Executes the action defined by the derived class.

### Class: `Action` (Derived from `ActionBase`)

#### Constructor
- **`Action(void (*func)())`**
  - Initializes a new action with the specified function.

#### Methods

- **`void execute()`**
  - Executes the stored function.

### Class: `Delay` (Derived from `ActionBase`)

#### Constructor
- **`Delay(unsigned long delay)`**
  - Initializes a new delay with the specified duration.

#### Methods

- **`void setDelay(unsigned long newDelay)`**
  - Changes the delay duration.
  - **Parameters:**
    - `newDelay`: The new delay duration in milliseconds.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! If you would like to contribute to this project