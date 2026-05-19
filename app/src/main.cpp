#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "ble_manager.h"

LOG_MODULE_REGISTER(vitaltrace);

int main() {
    LOG_INF("Starting firmware");

    BLEManager ble;
    ble.init();

    while (1) {
        k_sleep(K_SECONDS(1));
    }
}
