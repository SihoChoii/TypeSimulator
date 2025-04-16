# Type Simulator for Teensy 4.0

A Teensy 4.0 based project that realistically simulates human typing patterns, complete with natural speed variations, pauses, and occasional typos.

## Features

- Simulates human typing at configurable words-per-minute (default: 35 WPM)
- Natural typing rhythm with random speed variations
- Realistic pauses after punctuation and paragraph breaks
- Optional typing error simulation with corrections
- Compatible with Teensy 4.0 microcontroller

## Configuration Options

The simulator can be customized by changing these parameters:

```cpp
const float WPM = 35.0;                      // Target words per minute
const float MIN_VARIANCE = 0.7;              // Minimum speed variance (70%)
const float MAX_VARIANCE = 1.3;              // Maximum speed variance (130%)
const float ERROR_PROBABILITY = 0.01;        // Typing error probability (1%)
```

## Setup Instructions

1. Install [Teensy boards]([https://www.pjrc.com/teensy/teensyduino.html](https://www.pjrc.com/teensy/tutorial.html)) onto Arduino IDE
2. Set USB Type to "Keyboard" in the Arduino IDE Tools menu
3. Upload the sketch to your Teensy 4.0
4. Connect Teensy to the target computer to begin typing simulation

## How It Works

The simulator calculates appropriate delays between keystrokes based on the target WPM, and adds natural variation to make typing appear human. It includes special handling for:

- Longer pauses after punctuation (.,!?)
- Extended pauses after paragraph breaks
- Occasional typing errors followed by backspace corrections
- Simulation of adjacent key errors based on QWERTY keyboard layout

## Planned Features

- Hardware button integration to start/stop typing
- SD card support for loading large text files
- More sophisticated error models
- Multiple typing speed profiles (beginner, average, expert)
- Web portal for automaticalyl adding escpae characters

## License

[MIT License](LICENSE)
