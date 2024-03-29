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
#include <zephyr.h>
#include <zephyr/types.h>
#include <stddef.h>

#include "attr_defs.h"

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

enum memfault_transport {
	MEMFAULT_TRANSPORT_NONE = 0,
	MEMFAULT_TRANSPORT_HTTP = 1,
	MEMFAULT_TRANSPORT_MQTT = 2,
	MEMFAULT_TRANSPORT_COAP = 3,
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
BUILD_ASSERT(sizeof(enum memfault_transport) == ATTR_SIZE_U8);
BUILD_ASSERT(sizeof(enum lwm2m_telem_security) == ATTR_SIZE_U8);
/* pyend */

/**************************************************************************************************/
/* Global Data Definitions                                                                        */
/**************************************************************************************************/
/* pystart - attribute ids */
#define ATTR_ID_reserved0                             0
#define ATTR_ID_api_version                           1
#define ATTR_ID_firmware_version                      2
#define ATTR_ID_dump_path                             3
#define ATTR_ID_load_path                             4
#define ATTR_ID_board                                 5
#define ATTR_ID_log_on_boot                           6
#define ATTR_ID_disable_flow_control                  7
#define ATTR_ID_baud_rate                             8
#define ATTR_ID_lwm2m_server_url                      9
#define ATTR_ID_lwm2m_endpoint                        10
#define ATTR_ID_lwm2m_security                        11
#define ATTR_ID_lwm2m_psk_id                          12
#define ATTR_ID_lwm2m_psk                             13
#define ATTR_ID_lwm2m_bootstrap                       14
#define ATTR_ID_lwm2m_short_id                        15
#define ATTR_ID_lwm2m_mfg                             16
#define ATTR_ID_lwm2m_mn                              17
#define ATTR_ID_lwm2m_sn                              18
#define ATTR_ID_lwm2m_fw_ver                          19
#define ATTR_ID_lwm2m_pwr_src                         20
#define ATTR_ID_lwm2m_pwr_src_volt                    21
#define ATTR_ID_lwm2m_sw_ver                          22
#define ATTR_ID_lwm2m_hw_ver                          23
#define ATTR_ID_lwm2m_batt_stat                       24
#define ATTR_ID_lwm2m_fup_pkg_name                    25
#define ATTR_ID_lwm2m_fup_pkg_ver                     26
#define ATTR_ID_lwm2m_fup_proxy_srv                   27
#define ATTR_ID_bluetooth_address                     28
#define ATTR_ID_dm_disable                            29
#define ATTR_ID_dm_cnx_delay                          30
#define ATTR_ID_dm_cnx_delay_min                      31
#define ATTR_ID_dm_cnx_delay_max                      32
#define ATTR_ID_factory_load_path                     33
#define ATTR_ID_device_id                             34
#define ATTR_ID_smp_auth_req                          35
#define ATTR_ID_gw_smp_auth_req                       36
#define ATTR_ID_smp_auth_timeout                      37
#define ATTR_ID_dm_cnx_retries                        38
#define ATTR_ID_dm_cnx_backoff_multi                  39
#define ATTR_ID_dm_cnx_backoff_retries                40
#define ATTR_ID_shell_password                        41
#define ATTR_ID_shell_session_timeout                 42
#define ATTR_ID_tel_trust_path                        43
#define ATTR_ID_tel_key_path                          44
#define ATTR_ID_dm_trust_path                         45
#define ATTR_ID_dm_key_path                           46
#define ATTR_ID_fs_trust_path                         47
#define ATTR_ID_fs_key_path                           48
#define ATTR_ID_p2p_trust_path                        49
#define ATTR_ID_p2p_key_path                          50
#define ATTR_ID_ipv4_addr                             51
#define ATTR_ID_network_id_filter                     52
#define ATTR_ID_memfault_transport                    53
#define ATTR_ID_mqtt_memfault_topic                   54
#define ATTR_ID_coap_mflt_proxy_route                 55
#define ATTR_ID_store_memfault_data                   56
#define ATTR_ID_gw_ipv4_addr                          57
#define ATTR_ID_lwm2m_telem_server_url                58
#define ATTR_ID_lwm2m_telem_endpoint                  59
#define ATTR_ID_lwm2m_telem_security                  60
#define ATTR_ID_lwm2m_telem_psk_id                    61
#define ATTR_ID_lwm2m_telem_psk                       62
#define ATTR_ID_lwm2m_telem_short_id                  63
#define ATTR_ID_lwm2m_telem_enable                    64
/* pyend */

/* pystart - attribute constants */
#define ATTR_TABLE_SIZE                                 65
#define ATTR_TABLE_MAX_ID                               64
#define ATTR_TABLE_WRITABLE_COUNT                       54
#define ATTR_TABLE_CRC_OF_NAMES                         0x1356f3a4
#define ATTR_MAX_STR_LENGTH                             255
#define ATTR_MAX_STR_SIZE                               256
#define ATTR_MAX_BIN_SIZE                               16
#define ATTR_MAX_INT_SIZE                               4
#define ATTR_MAX_KEY_NAME_SIZE                          23
#define ATTR_MAX_VALUE_SIZE                             256
#define ATTR_MAX_FILE_SIZE                              3469
#define ATTR_ENABLE_FPU_CHECK                           1

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
#define ATTR_FACTORY_LOAD_PATH_MAX_STR_SIZE             33
#define ATTR_DEVICE_ID_MAX_STR_SIZE                     65
#define ATTR_SHELL_PASSWORD_MAX_STR_SIZE                33
#define ATTR_TEL_TRUST_PATH_MAX_STR_SIZE                33
#define ATTR_TEL_KEY_PATH_MAX_STR_SIZE                  33
#define ATTR_DM_TRUST_PATH_MAX_STR_SIZE                 33
#define ATTR_DM_KEY_PATH_MAX_STR_SIZE                   33
#define ATTR_FS_TRUST_PATH_MAX_STR_SIZE                 33
#define ATTR_FS_KEY_PATH_MAX_STR_SIZE                   33
#define ATTR_P2P_TRUST_PATH_MAX_STR_SIZE                33
#define ATTR_P2P_KEY_PATH_MAX_STR_SIZE                  33
#define ATTR_IPV4_ADDR_MAX_STR_SIZE                     16
#define ATTR_MQTT_MEMFAULT_TOPIC_MAX_STR_SIZE           256
#define ATTR_COAP_MFLT_PROXY_ROUTE_MAX_STR_SIZE         33
#define ATTR_GW_IPV4_ADDR_MAX_STR_SIZE                  16
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
const char *const attr_get_string_memfault_transport(int value);
const char *const attr_get_string_lwm2m_telem_security(int value);
/* pyend */

#ifdef __cplusplus
}
#endif
#endif /* __ATTR_TABLE_H__ */
