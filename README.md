# gpio-cpp
gpio-cpp is a simple, not particularly featureful C++17 wrapper around the Linux userspace GPIO chardev interface. Specifically it wraps v2 of this interface.

This library was created to work on the Raspberry Pi but there's nothing super Pi-centric here in the functionality, so it will probably work fine on other platforms.

## Usage

```c++
#include <gpio-cpp/gpio.hpp>

// Create a gpio device
Gpio gpio("/dev/gpiochip0");

// Setup a line
gpio.setupLine(5, Gpio::LineMode::Input, Gpio::LineBias::PullUp);

// Read its value
bool line5Active = gpio.read(5);

// Subscribe to change events
gpio.subscribe(5, [&](int line, Gpio::LineTransition transition, std::chrono::steady_clock::time_point timestamp)
{
  if (transition == Gpio::LineTransition::FallingEdge)
  {
    // Handle the event however you line
  }
});
```

You can of course control outputs too:
```c++
// Setup an output line
gpio.setupLine(6, Gpio::LineMode::Output, Gpio::LineBias::PullDown);

// Write to the line
gpio.write(6);
```

When the `Gpio` object goes out of scope, everything is cleaned up. You can also release lines manually to allow other processes to use them right away:

```c++
gpio.releaseLine(6);
```

## Prerequisites
* Linux OS with the v2 GPIO userspace GPIO
  * Look for `/dev/gpiochipX`
* Sigslot for events
  * Included as a submodule