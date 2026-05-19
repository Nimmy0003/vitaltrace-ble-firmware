#include "battery_sim.h"
#include "app_config.h"

BatterySim::BatterySim() { level = BATTERY_MAX; }

uint8_t BatterySim::update() {
    if (level > BATTERY_MIN) level -= BATTERY_DRAIN_STEP;
    else level = BATTERY_MAX;
    return level;
}
