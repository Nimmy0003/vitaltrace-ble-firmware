cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(vitaltrace)

target_sources(app PRIVATE
    app/src/main.cpp
    app/src/threads.cpp
    app/src/battery_sim.cpp
    app/src/fhr_sim.cpp
    app/src/ble_manager.cpp
)
