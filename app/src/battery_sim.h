#pragma once
#include <stdint.h>

class BatterySim {
public:
    BatterySim();
    uint8_t update();
private:
    uint8_t level;
};
