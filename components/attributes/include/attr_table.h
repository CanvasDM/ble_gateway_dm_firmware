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
	LWM2M_SECURITY_LWM2M_SEC_PSK = 0,
	LWM2M_SECURITY_LWM2M_SEC_RPK = 1,
	LWM2M_SECURITY_LWM2M_SEC_CERT = 2,
	LWM2M_SECURITY_LWM2M_SEC_NO_SEC = 3,
	LWM2M_SECURITY_LWM2M_SEC_CERT_EST = 4,
};

/* pyend */

/* pystart - enum size check */
BUILD_ASSERT(sizeof(enum lwm2m_security) == ATTR_SIZE_U8);
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
/* pyend */

/* pystart - attribute constants */
#define ATTR_TABLE_SIZE                           12
#define ATTR_TABLE_MAX_ID                         11
#define ATTR_TABLE_WRITABLE_COUNT                 9
#define ATTR_MAX_STR_LENGTH                       255
#define ATTR_MAX_STR_SIZE                         256
#define ATTR_MAX_BIN_SIZE                         16
#define ATTR_MAX_INT_SIZE                         2

/* Attribute Max String Lengths */
#define ATTR_API_VERSION_MAX_STR_SIZE             12
#define ATTR_FIRMWARE_VERSION_MAX_STR_SIZE        65
#define ATTR_DUMP_PATH_MAX_STR_SIZE               33
#define ATTR_LOAD_PATH_MAX_STR_SIZE               33
#define ATTR_BOARD_MAX_STR_SIZE                   65
#define ATTR_LWM2M_SERVER_URL_MAX_STR_SIZE        256
#define ATTR_LWM2M_ENDPOINT_MAX_STR_SIZE          33
#define ATTR_LWM2M_PSK_ID_MAX_STR_SIZE            33

/* Attribute Byte Array Lengths */
#define ATTR_LWM2M_PSK_SIZE                       16
/* pyend */

/**************************************************************************************************/
/* Global Function Prototypes                                                                     */
/**************************************************************************************************/
/* pystart - prepare for read */
/* pyend */

/* pystart - get string */
const char *const attr_get_string_lwm2m_security(int value);
/* pyend */

#ifdef __cplusplus
}
#endif
#endif /* __ATTR_TABLE_H__ */
