#include <zephyr/kernel.h>
#include "battery_sim.h"
#include "fhr_sim.h"
#include "ble_manager.h"
#include "app_config.h"
#include "shared_types.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(vitaltrace);

static BatterySim battery;
static FHRSim fhr;
static BLEManager ble;

static telemetry_t t;

void battery_thread() {
    while (1) {
        t.battery_level = battery.update();
        ble.notify_battery(t.battery_level);
        k_sleep(K_MSEC(BATTERY_UPDATE_MS));
    }
}

void fhr_thread() {
    while (1) {
        t.fhr_bpm = fhr.generate();
        ble.notify_fhr(t.fhr_bpm);
        k_sleep(K_MSEC(FHR_UPDATE_MS));
    }
}

void control_thread() {
    while (1) {
        static bool s = false;
        s = !s;
        t.streaming_enabled = s;
        ble.set_streaming(s);
        k_sleep(K_MSEC(15000));
    }
}

K_THREAD_DEFINE(bt, 1024, battery_thread, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(ft, 1024, fhr_thread, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(ct, 1024, control_thread, NULL, NULL, NULL, 5, 0, 0);
