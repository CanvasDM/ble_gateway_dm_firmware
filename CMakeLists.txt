# SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause

cmake_minimum_required(VERSION 3.20.0)

if(NOT (BOARD STREQUAL qemu_cortex_m3))

set(mcuboot_CONF_FILE
    ${CMAKE_SOURCE_DIR}/config/mcuboot.${BOARD}.conf
)
set(PM_STATIC_YML_FILE
    ${CMAKE_SOURCE_DIR}/../modules/zephyr_lib/mcuboot_config/pm_static.sb.${BOARD}.yml
)

endif()

if((BOARD STREQUAL mg100) OR (BOARD STREQUAL pinnacle_100_dvk))

set(b0_OVERLAY_CONFIG
   ${CMAKE_SOURCE_DIR}/config/b0.${BOARD}.conf
)

elseif ((BOARD STREQUAL bl5340_dvk_cpuapp) OR (BOARD STREQUAL bl5340pa_dvk_cpuapp))

set(b0_DTC_OVERLAY_FILE
    ${CMAKE_SOURCE_DIR}/boards/bl5340_dvk_cpuapp.overlay
)
set(mcuboot_DTC_OVERLAY_FILE
    ${CMAKE_SOURCE_DIR}/boards/bl5340_dvk_cpuapp.overlay
)

endif()

# Prepend the additional boards directory but still allow the original Zephyr
# boards directory to be used with lower priority
list(PREPEND BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ble_gateway_dm_firmware)

target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/version
)

target_sources(app PRIVATE src/main.c)
