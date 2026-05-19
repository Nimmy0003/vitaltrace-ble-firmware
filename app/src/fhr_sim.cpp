#include "fhr_sim.h"
#include "app_config.h"
#include <stdlib.h>

uint16_t FHRSim::generate() {
    int d = (rand() % 5) - 2;
    int n = (int)last + d;
    if (n < FHR_MIN) n = FHR_MIN;
    if (n > FHR_MAX) n = FHR_MAX;
    last = (uint16_t)n;
    return last;
}
