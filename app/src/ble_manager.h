#pragma once
#include <stdint.h>
#include <stdbool.h>

class BLEManager {
public:
    void init();
    void notify_battery(uint8_t level);
    void notify_fhr(uint16_t bpm);
    void set_streaming(bool enable);
private:
    bool streaming = false;
};
