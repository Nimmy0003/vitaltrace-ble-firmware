#include "ble_manager.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(vitaltrace);

void BLEManager::init() {
    LOG_INF("BLE init (simulated)");
}

void BLEManager::notify_battery(uint8_t level) {
    LOG_INF("Battery: %d%%", level);
}

void BLEManager::notify_fhr(uint16_t bpm) {
    if (!streaming) return;
    LOG_INF("FHR: %d BPM", bpm);
}

void BLEManager::set_streaming(bool enable) {
    streaming = enable;
    LOG_INF("Streaming %s", enable ? "ON" : "OFF");
}
