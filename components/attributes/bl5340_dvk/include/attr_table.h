/**
 * @file attr_table.h
 * @brief
 *
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

#ifndef __ATTR_TABLE_H__
#define __ATTR_TABLE_H__

/**************************************************************************************************/
/* Includes                                                                                       */
/**************************************************************************************************/
/* pystart - headers */
#include <zephyr.h>
#include "attr_defs.h"
/* pyend */
#include <zephyr/types.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************/
/* Global Constants, Macros and Type Definitions                                                  */
/**************************************************************************************************/
/* pystart - enumerations */
enum lwm2m_security {
	LWM2M_SECURITY_PSK = 0,
	LWM2M_SECURITY_RPK = 1,
	LWM2M_SECURITY_CERT = 2,
	LWM2M_SECURITY_NO_SEC = 3,
	LWM2M_SECURITY_CERT_EST = 4,
};

enum lwm2m_pwr_src {
	LWM2M_PWR_SRC_DC = 0,
	LWM2M_PWR_SRC_INT_BATT = 1,
	LWM2M_PWR_SRC_EXT_BATT = 2,
	LWM2M_PWR_SRC_FUEL_CELL = 3,
	LWM2M_PWR_SRC_POE = 4,
	LWM2M_PWR_SRC_USB = 5,
	LWM2M_PWR_SRC_AC = 6,
	LWM2M_PWR_SRC_SOLAR = 7,
};

enum lwm2m_batt_stat {
	LWM2M_BATT_STAT_NORM = 0,
	LWM2M_BATT_STAT_CHARGING = 1,
	LWM2M_BATT_STAT_CHARGE_COMP = 2,
	LWM2M_BATT_STAT_DAMAGED = 3,
	LWM2M_BATT_STAT_LOW = 4,
	LWM2M_BATT_STAT_NOT_INST = 5,
	LWM2M_BATT_STAT_UNKNOWN = 6,
};

enum lwm2m_telem_security {
	LWM2M_TELEM_SECURITY_PSK = 0,
	LWM2M_TELEM_SECURITY_RPK = 1,
	LWM2M_TELEM_SECURITY_CERT = 2,
	LWM2M_TELEM_SECURITY_NO_SEC = 3,
	LWM2M_TELEM_SECURITY_CERT_EST = 4,
};

/* pyend */

/* pystart - enum size check */
BUILD_ASSERT(sizeof(enum lwm2m_security) == ATTR_SIZE_U8);
BUILD_ASSERT(sizeof(enum lwm2m_pwr_src) == ATTR_SIZE_U8);
BUILD_ASSERT(sizeof(enum lwm2m_batt_stat) == ATTR_SIZE_U8);
BUILD_ASSERT(sizeof(enum lwm2m_telem_security) == ATTR_SIZE_U8);
/* pyend */

/**************************************************************************************************/
/* Global Data Definitions                                                                        */
/**************************************************************************************************/
/* pystart - attribute ids */
#define ATTR_ID_api_version                           0
#define ATTR_ID_firmware_version                      1
#define ATTR_ID_dump_path                             2
#define ATTR_ID_load_path                             3
#define ATTR_ID_board                                 4
#define ATTR_ID_lwm2m_server_url                      5
#define ATTR_ID_lwm2m_endpoint                        6
#define ATTR_ID_lwm2m_security                        7
#define ATTR_ID_lwm2m_psk_id                          8
#define ATTR_ID_lwm2m_psk                             9
#define ATTR_ID_lwm2m_bootstrap                       10
#define ATTR_ID_lwm2m_short_id                        11
#define ATTR_ID_lwm2m_mfg                             12
#define ATTR_ID_lwm2m_mn                              13
#define ATTR_ID_lwm2m_sn                              14
#define ATTR_ID_lwm2m_fw_ver                          15
#define ATTR_ID_lwm2m_pwr_src                         16
#define ATTR_ID_lwm2m_pwr_src_volt                    17
#define ATTR_ID_lwm2m_sw_ver                          18
#define ATTR_ID_lwm2m_hw_ver                          19
#define ATTR_ID_lwm2m_batt_stat                       20
#define ATTR_ID_lwm2m_fup_pkg_name                    21
#define ATTR_ID_lwm2m_fup_pkg_ver                     22
#define ATTR_ID_lwm2m_fup_proxy_srv                   23
#define ATTR_ID_bluetooth_address                     24
#define ATTR_ID_dm_cnx_delay                          25
#define ATTR_ID_dm_cnx_delay_min                      26
#define ATTR_ID_dm_cnx_delay_max                      27
#define ATTR_ID_lwm2m_telem_server_url                28
#define ATTR_ID_lwm2m_telem_endpoint                  29
#define ATTR_ID_lwm2m_telem_security                  30
#define ATTR_ID_lwm2m_telem_psk_id                    31
#define ATTR_ID_lwm2m_telem_psk                       32
#define ATTR_ID_lwm2m_telem_short_id                  33
#define ATTR_ID_lwm2m_telem_enable                    34
/* pyend */

/* pystart - attribute constants */
#define ATTR_TABLE_SIZE                                 35
#define ATTR_TABLE_MAX_ID                               34
#define ATTR_TABLE_WRITABLE_COUNT                       27
#define ATTR_MAX_STR_LENGTH                             255
#define ATTR_MAX_STR_SIZE                               256
#define ATTR_MAX_BIN_SIZE                               16
#define ATTR_MAX_INT_SIZE                               4

/* Attribute Max String Lengths */
#define ATTR_API_VERSION_MAX_STR_SIZE                   12
#define ATTR_FIRMWARE_VERSION_MAX_STR_SIZE              65
#define ATTR_DUMP_PATH_MAX_STR_SIZE                     33
#define ATTR_LOAD_PATH_MAX_STR_SIZE                     33
#define ATTR_BOARD_MAX_STR_SIZE                         65
#define ATTR_LWM2M_SERVER_URL_MAX_STR_SIZE              256
#define ATTR_LWM2M_ENDPOINT_MAX_STR_SIZE                65
#define ATTR_LWM2M_PSK_ID_MAX_STR_SIZE                  65
#define ATTR_LWM2M_MFG_MAX_STR_SIZE                     33
#define ATTR_LWM2M_MN_MAX_STR_SIZE                      33
#define ATTR_LWM2M_SN_MAX_STR_SIZE                      65
#define ATTR_LWM2M_FW_VER_MAX_STR_SIZE                  33
#define ATTR_LWM2M_SW_VER_MAX_STR_SIZE                  33
#define ATTR_LWM2M_HW_VER_MAX_STR_SIZE                  33
#define ATTR_LWM2M_FUP_PKG_NAME_MAX_STR_SIZE            33
#define ATTR_LWM2M_FUP_PKG_VER_MAX_STR_SIZE             33
#define ATTR_LWM2M_FUP_PROXY_SRV_MAX_STR_SIZE           256
#define ATTR_BLUETOOTH_ADDRESS_MAX_STR_SIZE             13
#define ATTR_LWM2M_TELEM_SERVER_URL_MAX_STR_SIZE        256
#define ATTR_LWM2M_TELEM_ENDPOINT_MAX_STR_SIZE          65
#define ATTR_LWM2M_TELEM_PSK_ID_MAX_STR_SIZE            65

/* Attribute Byte Array Lengths */
#define ATTR_LWM2M_PSK_SIZE                             16
#define ATTR_LWM2M_TELEM_PSK_SIZE                       16
/* pyend */

/**************************************************************************************************/
/* Global Function Prototypes                                                                     */
/**************************************************************************************************/
/* pystart - prepare for read */
/* pyend */

/* pystart - get string */
const char *const attr_get_string_lwm2m_security(int value);
const char *const attr_get_string_lwm2m_pwr_src(int value);
const char *const attr_get_string_lwm2m_batt_stat(int value);
const char *const attr_get_string_lwm2m_telem_security(int value);
/* pyend */

#ifdef __cplusplus
}
#endif
#endif /* __ATTR_TABLE_H__ */
