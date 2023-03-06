// The purpose of this file is to permit compilation of gpio-cpp
// on non-linux systems. It makes no attempt
// to simulate the hardware so while compilation will work,
// results will depend on how the consuming code is written.

#include <gpio-cpp/gpio.hpp>

struct Gpio::Line { };
struct pollfd { };
Gpio::Line& Gpio::getLineFromFd(int) { static Gpio::Line line; return line; }
Gpio::Gpio(const std::string&, const std::string&) { }
void Gpio::setupLine(int, LineMode, LineBias) {}
void Gpio::releaseLine(int) {}
void Gpio::setupPollfd() {}
bool Gpio::read(int) { return false; }
void Gpio::write(int, bool) {}
sigslot::connection Gpio::subscribe(int, InputChangedHandler) { return sigslot::connection(); }
Gpio::~Gpio() {}
