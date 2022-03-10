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

# generate build ID based on UTC timestamp
string(TIMESTAMP build_time "%s" UTC)
set(APP_VERSION_BUILD ${build_time})
set(ver_file ${CMAKE_SOURCE_DIR}/src/version/app_version.h)
configure_file(${CMAKE_SOURCE_DIR}/src/version/app_version.h.in ${ver_file})
# Get application version
file(READ ${ver_file} ver)
string(REGEX MATCH "APP_VERSION_MAJOR ([0-9]*)" _ ${ver})
set(ver_major ${CMAKE_MATCH_1})
string(REGEX MATCH "APP_VERSION_MINOR ([0-9]*)" _ ${ver})
set(ver_minor ${CMAKE_MATCH_1})
string(REGEX MATCH "APP_VERSION_PATCH ([0-9]*)" _ ${ver})
set(ver_patch ${CMAKE_MATCH_1})
set(app_version ${ver_major}.${ver_minor}.${ver_patch}+${build_time})
message("app version: ${app_version}")

if(NOT (BOARD STREQUAL qemu_cortex_m3))
# Set application version for mcuboot
set(mcuboot_ver_conf ${CMAKE_SOURCE_DIR}/build/generated_mcuboot_image_version.conf)
set(MCUBOOT_IMAGE_VERSION ${app_version})
configure_file(${CMAKE_SOURCE_DIR}/src/version/mcuboot_image_version.conf.in ${mcuboot_ver_conf})
list(APPEND OVERLAY_CONFIG ${CMAKE_SOURCE_DIR}/config/firmware_update.conf ${mcuboot_ver_conf})
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
