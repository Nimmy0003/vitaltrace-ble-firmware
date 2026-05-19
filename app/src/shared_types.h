#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t battery_level;
    uint16_t fhr_bpm;
    bool streaming_enabled;
} telemetry_t;
