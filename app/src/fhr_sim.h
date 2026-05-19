#pragma once
#include <stdint.h>

class FHRSim {
public:
    uint16_t generate();
private:
    uint16_t last = 140;
};
