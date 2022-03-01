# SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause

cmake_minimum_required(VERSION 3.20.0)

if((BOARD STREQUAL mg100) OR (BOARD STREQUAL pinnacle_100_dvk)
   OR (BOARD STREQUAL bl5340_dvk_cpuapp)
   OR (BOARD STREQUAL bl5340pa_dvk_cpuapp))
set(mcuboot_CONF_FILE
    ${CMAKE_SOURCE_DIR}/config/mcuboot.${BOARD}.conf
)

# Use static partition layout for board, this is needed for NRF Connect SDK
set(PM_STATIC_YML_FILE
    ${CMAKE_SOURCE_DIR}/../modules/zephyr_lib/mcuboot_config/pm_static.${BOARD}.yml
)

if ((BOARD STREQUAL bl5340_dvk_cpuapp) OR (BOARD STREQUAL bl5340pa_dvk_cpuapp))
set(mcuboot_DTC_OVERLAY_FILE
    ${CMAKE_SOURCE_DIR}/boards/bl5340_dvk_cpuapp.overlay
)
endif()
endif()

# Prepend the additional boards directory but still allow the original Zephyr
# boards directory to be used with lower priority
list(PREPEND BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ble_gateway_dm_firmware)

target_sources(app PRIVATE src/main.c)
