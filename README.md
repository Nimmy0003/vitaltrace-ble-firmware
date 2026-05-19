# VitalTrace BLE Firmware (Assessment Project)

## Overview
Simulated wearable medical device using Zephyr RTOS concepts.

The project demonstrates a modular embedded system with BLE communication, sensor simulation, and RTOS style threading design.

---

## Features

Battery service simulation  
Fetal Heart Rate simulation  
BLE notification abstraction  
RTOS thread based design  

---

## Architecture

Battery Thread  
FHR Thread  
BLE Manager  

Data flows from sensor threads to BLE manager for notification handling.

---

## Build

This project is designed around Zephyr RTOS concepts.

Zephyr SDK is required for full build.

For this assessment, CI uses a simplified build mock due to SDK limitations in hosted environments.

---

## Build Steps

```bash
git clone https://github.com/Nimmy0003/vitaltrace-ble-firmware.git
cd vitaltrace-ble-firmware

mkdir build
cd build

cmake ..
make -j4
