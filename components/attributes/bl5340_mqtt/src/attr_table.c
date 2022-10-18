/**
 * @file attr_table.c
 * @brief
 *
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

/**************************************************************************************************/
/* Includes                                                                                       */
/**************************************************************************************************/
#include <zephyr.h>
#include <string.h>
#include <errno_str.h>
#include "attr_validator.h"
#include "attr_table.h"

#ifdef CONFIG_ATTR_CUSTOM_VALIDATOR
#include "attr_custom_validator.h"
#endif

/**************************************************************************************************/
/* Local Constant, Macro and Type Definitions                                                     */
/**************************************************************************************************/
#define DRW DEFAULT_RW_ATTRIBUTE_VALUES
#define DRO DEFAULT_RO_ATTRIBUTE_VALUES
#define y true
#define n false

/* pystart - rw attributes */
typedef struct rw_attribute {
	char dump_path[32 + 1];
	char load_path[32 + 1];
	bool log_on_boot;
	char lwm2m_server_url[255 + 1];
	char lwm2m_endpoint[64 + 1];
	enum lwm2m_security lwm2m_security;
	char lwm2m_psk_id[64 + 1];
	uint8_t lwm2m_psk[16];
	bool lwm2m_bootstrap;
	uint16_t lwm2m_short_id;
	char lwm2m_mfg[32 + 1];
	char lwm2m_mn[32 + 1];
	char lwm2m_sn[64 + 1];
	char lwm2m_fw_ver[32 + 1];
	char lwm2m_sw_ver[32 + 1];
	char lwm2m_hw_ver[32 + 1];
	char lwm2m_fup_proxy_srv[255 + 1];
	uint16_t dm_cnx_delay;
	uint16_t dm_cnx_delay_min;
	uint16_t dm_cnx_delay_max;
	char factory_load_path[32 + 1];
	char device_id[64 + 1];
	bool smp_auth_req;
	bool gw_smp_auth_req;
	uint32_t smp_auth_timeout;
	char shell_password[32 + 1];
	char tel_trust_path[32 + 1];
	char tel_key_path[32 + 1];
	char dm_trust_path[32 + 1];
	char dm_key_path[32 + 1];
	char fs_trust_path[32 + 1];
	char fs_key_path[32 + 1];
	char p2p_trust_path[32 + 1];
	char p2p_key_path[32 + 1];
	char mqtt_user_name[127 + 1];
	char mqtt_password[127 + 1];
	char mqtt_endpoint[127 + 1];
	char mqtt_port[4 + 1];
	char mqtt_id[127 + 1];
	uint32_t mqtt_watchdog;
	uint8_t mqtt_publish_qos;
	enum mqtt_peer_verify mqtt_peer_verify;
	uint8_t mqtt_subscribe_qos;
	bool mqtt_use_credentials;
	bool mqtt_connect_on_request;
	bool mqtt_id_randomize;
	bool mqtt_ble_enable;
	char mqtt_ble_topic[255 + 1];
	char mqtt_ble_prefix[63 + 1];
	char mqtt_ble_delimiter[1 + 1];
	char mqtt_ble_postfix[15 + 1];
	bool mqtt_ble_quote;
	uint16_t mqtt_ble_network_id_filter;
} rw_attribute_t;
/* pyend */

/* pystart - rw defaults */
static const rw_attribute_t DEFAULT_RW_ATTRIBUTE_VALUES =  {
	.dump_path = "/lfs1/attr_dump.txt",
	.load_path = "/lfs1/enc/attr_load.txt",
	.log_on_boot = 0,
	.lwm2m_server_url = "coap://leshan.eclipseprojects.io:5683",
	.lwm2m_endpoint = "my_device",
	.lwm2m_security = 3,
	.lwm2m_psk_id = "my_device",
	.lwm2m_psk = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },
	.lwm2m_bootstrap = 0,
	.lwm2m_short_id = 1,
	.lwm2m_mfg = "Laird Connectivity",
	.lwm2m_mn = "model",
	.lwm2m_sn = "serial_number",
	.lwm2m_fw_ver = "0.0.0",
	.lwm2m_sw_ver = "0.0.0",
	.lwm2m_hw_ver = "0.0.0",
	.lwm2m_fup_proxy_srv = "coaps://coap-proxy.salticidae.net:5684",
	.dm_cnx_delay = 0,
	.dm_cnx_delay_min = 1,
	.dm_cnx_delay_max = 300,
	.factory_load_path = "/lfs1/enc/factory_load.txt",
	.device_id = "",
	.smp_auth_req = 0,
	.gw_smp_auth_req = 0,
	.smp_auth_timeout = 300,
	.shell_password = "zephyr",
	.tel_trust_path = "/lfs1/tel/trust",
	.tel_key_path = "/lfs1/enc/tel/key",
	.dm_trust_path = "/lfs1/dm/trust",
	.dm_key_path = "/lfs1/enc/dm/key",
	.fs_trust_path = "/lfs1/fs/trust",
	.fs_key_path = "/lfs1/enc/fs/key",
	.p2p_trust_path = "/lfs1/p2p/trust",
	.p2p_key_path = "/lfs1/enc/p2p/key",
	.mqtt_user_name = "",
	.mqtt_password = "",
	.mqtt_endpoint = "",
	.mqtt_port = "8883",
	.mqtt_id = "",
	.mqtt_watchdog = 0,
	.mqtt_publish_qos = 1,
	.mqtt_peer_verify = 2,
	.mqtt_subscribe_qos = 1,
	.mqtt_use_credentials = 1,
	.mqtt_connect_on_request = 1,
	.mqtt_id_randomize = 0,
	.mqtt_ble_enable = 0,
	.mqtt_ble_topic = "",
	.mqtt_ble_prefix = "",
	.mqtt_ble_delimiter = "",
	.mqtt_ble_postfix = "",
	.mqtt_ble_quote = 0,
	.mqtt_ble_network_id_filter = 0
};
/* pyend */

/* pystart - ro attributes */
typedef struct ro_attribute {
	uint32_t reserved0;
	char api_version[11 + 1];
	char firmware_version[64 + 1];
	char board[64 + 1];
	enum lwm2m_pwr_src lwm2m_pwr_src;
	int32_t lwm2m_pwr_src_volt;
	enum lwm2m_batt_stat lwm2m_batt_stat;
	char lwm2m_fup_pkg_name[32 + 1];
	char lwm2m_fup_pkg_ver[32 + 1];
	char bluetooth_address[12 + 1];
	char ipv4_addr[15 + 1];
	char gw_ipv4_addr[15 + 1];
	char mqtt_id_random[145 + 1];
} ro_attribute_t;
/* pyend */

/* pystart - ro defaults */
static const ro_attribute_t DEFAULT_RO_ATTRIBUTE_VALUES =  {
	.reserved0 = 0,
	.api_version = "0.4.0",
	.firmware_version = "0.0.0+0",
	.board = "my_board",
	.lwm2m_pwr_src = 0,
	.lwm2m_pwr_src_volt = 0,
	.lwm2m_batt_stat = 6,
	.lwm2m_fup_pkg_name = "my_firmware",
	.lwm2m_fup_pkg_ver = "0.0.0",
	.bluetooth_address = "0",
	.ipv4_addr = "",
	.gw_ipv4_addr = "",
	.mqtt_id_random = "",
};
/* pyend */

/**************************************************************************************************/
/* Local Data Definitions                                                                         */
/**************************************************************************************************/
static rw_attribute_t rw;
static ro_attribute_t ro;

/**************************************************************************************************/
/* Global Data Definitions                                                                        */
/**************************************************************************************************/
/**
 * @brief Table shorthand
 *
 * @ref CreateStruct (Python script)
 * Writable but non-savable values are populated using RO macro.
 *
 *.........name...value...default....size...writable..readable..get enum str
 */
#define RW_ATTRS(n) STRINGIFY(n), rw.n, DRW.n, sizeof(rw.n), NULL
#define RW_ATTRX(n) STRINGIFY(n), &rw.n, &DRW.n, sizeof(rw.n), NULL
#define RW_ATTRE(n) STRINGIFY(n), &rw.n, &DRW.n, sizeof(rw.n), attr_get_string_ ## n
#define RO_ATTRS(n) STRINGIFY(n), ro.n, DRO.n, sizeof(ro.n), NULL
#define RO_ATTRX(n) STRINGIFY(n), &ro.n, &DRO.n, sizeof(ro.n), NULL
#define RO_ATTRE(n) STRINGIFY(n), &ro.n, &DRO.n, sizeof(ro.n), attr_get_string_ ## n

/* If min == max then range isn't checked.
 *
 * index....name.....................type.flags.validator..prepare..min.max.
 */
/* pystart - table */
const struct attr_table_entry ATTR_TABLE[ATTR_TABLE_SIZE] = {
	[0  ] = { RO_ATTRX(reserved0)                           , ATTR_TYPE_U32           , 0x0   , av_uint32           , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[1  ] = { RO_ATTRS(api_version)                         , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 6         , .max.ux = 11        },
	[2  ] = { RO_ATTRS(firmware_version)                    , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 5         , .max.ux = 64        },
	[3  ] = { RW_ATTRS(dump_path)                           , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[4  ] = { RW_ATTRS(load_path)                           , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[5  ] = { RO_ATTRS(board)                               , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[6  ] = { RW_ATTRX(log_on_boot)                         , ATTR_TYPE_BOOL          , 0x1b  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[7  ] = { RW_ATTRS(lwm2m_server_url)                    , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[8  ] = { RW_ATTRS(lwm2m_endpoint)                      , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[9  ] = { RW_ATTRE(lwm2m_security)                      , ATTR_TYPE_U8            , 0x1b  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 4         },
	[10 ] = { RW_ATTRS(lwm2m_psk_id)                        , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[11 ] = { RW_ATTRX(lwm2m_psk)                           , ATTR_TYPE_BYTE_ARRAY    , 0x59  , av_array            , NULL                                , .min.ux = 16        , .max.ux = 16        },
	[12 ] = { RW_ATTRX(lwm2m_bootstrap)                     , ATTR_TYPE_BOOL          , 0x1b  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[13 ] = { RW_ATTRX(lwm2m_short_id)                      , ATTR_TYPE_U16           , 0x1b  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 65534     },
	[14 ] = { RW_ATTRS(lwm2m_mfg)                           , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[15 ] = { RW_ATTRS(lwm2m_mn)                            , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[16 ] = { RW_ATTRS(lwm2m_sn)                            , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[17 ] = { RW_ATTRS(lwm2m_fw_ver)                        , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[18 ] = { RO_ATTRE(lwm2m_pwr_src)                       , ATTR_TYPE_U8            , 0xb   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 7         },
	[19 ] = { RO_ATTRX(lwm2m_pwr_src_volt)                  , ATTR_TYPE_S32           , 0xa   , av_int32            , NULL                                , .min.sx = -600000   , .max.sx = 600000    },
	[20 ] = { RW_ATTRS(lwm2m_sw_ver)                        , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[21 ] = { RW_ATTRS(lwm2m_hw_ver)                        , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[22 ] = { RO_ATTRE(lwm2m_batt_stat)                     , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 6         },
	[23 ] = { RO_ATTRS(lwm2m_fup_pkg_name)                  , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[24 ] = { RO_ATTRS(lwm2m_fup_pkg_ver)                   , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[25 ] = { RW_ATTRS(lwm2m_fup_proxy_srv)                 , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[26 ] = { RO_ATTRS(bluetooth_address)                   , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 12        , .max.ux = 12        },
	[27 ] = { RW_ATTRX(dm_cnx_delay)                        , ATTR_TYPE_U16           , 0x1b  , av_cp16             , NULL                                , .min.ux = 0         , .max.ux = 600       },
	[28 ] = { RW_ATTRX(dm_cnx_delay_min)                    , ATTR_TYPE_U16           , 0x1b  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 599       },
	[29 ] = { RW_ATTRX(dm_cnx_delay_max)                    , ATTR_TYPE_U16           , 0x1b  , av_uint16           , NULL                                , .min.ux = 2         , .max.ux = 600       },
	[30 ] = { RW_ATTRS(factory_load_path)                   , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[31 ] = { RW_ATTRS(device_id)                           , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 64        },
	[32 ] = { RW_ATTRX(smp_auth_req)                        , ATTR_TYPE_BOOL          , 0x1b  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[33 ] = { RW_ATTRX(gw_smp_auth_req)                     , ATTR_TYPE_BOOL          , 0x1b  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[34 ] = { RW_ATTRX(smp_auth_timeout)                    , ATTR_TYPE_U32           , 0x1b  , av_uint32           , NULL                                , .min.ux = 0         , .max.ux = 86400     },
	[35 ] = { RW_ATTRS(shell_password)                      , ATTR_TYPE_STRING        , 0x91  , av_string           , NULL                                , .min.ux = 4         , .max.ux = 32        },
	[36 ] = { RW_ATTRS(tel_trust_path)                      , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[37 ] = { RW_ATTRS(tel_key_path)                        , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[38 ] = { RW_ATTRS(dm_trust_path)                       , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[39 ] = { RW_ATTRS(dm_key_path)                         , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[40 ] = { RW_ATTRS(fs_trust_path)                       , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[41 ] = { RW_ATTRS(fs_key_path)                         , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[42 ] = { RW_ATTRS(p2p_trust_path)                      , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[43 ] = { RW_ATTRS(p2p_key_path)                        , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[44 ] = { RO_ATTRS(ipv4_addr)                           , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 15        },
	[45 ] = { RO_ATTRS(gw_ipv4_addr)                        , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 15        },
	[46 ] = { RW_ATTRS(mqtt_user_name)                      , ATTR_TYPE_STRING        , 0x11  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 127       },
	[47 ] = { RW_ATTRS(mqtt_password)                       , ATTR_TYPE_STRING        , 0x11  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 127       },
	[48 ] = { RW_ATTRS(mqtt_endpoint)                       , ATTR_TYPE_STRING        , 0x11  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 127       },
	[49 ] = { RW_ATTRS(mqtt_port)                           , ATTR_TYPE_STRING        , 0x11  , av_string           , NULL                                , .min.ux = 3         , .max.ux = 4         },
	[50 ] = { RW_ATTRS(mqtt_id)                             , ATTR_TYPE_STRING        , 0x11  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 127       },
	[51 ] = { RW_ATTRX(mqtt_watchdog)                       , ATTR_TYPE_U32           , 0x13  , av_uint32           , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[52 ] = { RW_ATTRX(mqtt_publish_qos)                    , ATTR_TYPE_U8            , 0x13  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[53 ] = { RW_ATTRE(mqtt_peer_verify)                    , ATTR_TYPE_U8            , 0x13  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[54 ] = { RW_ATTRX(mqtt_subscribe_qos)                  , ATTR_TYPE_U8            , 0x13  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[55 ] = { RW_ATTRX(mqtt_use_credentials)                , ATTR_TYPE_BOOL          , 0x13  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[56 ] = { RW_ATTRX(mqtt_connect_on_request)             , ATTR_TYPE_BOOL          , 0x13  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[57 ] = { RW_ATTRX(mqtt_id_randomize)                   , ATTR_TYPE_BOOL          , 0x13  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[58 ] = { RO_ATTRS(mqtt_id_random)                      , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 145       },
	[59 ] = { RW_ATTRX(mqtt_ble_enable)                     , ATTR_TYPE_BOOL          , 0x13  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[60 ] = { RW_ATTRS(mqtt_ble_topic)                      , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 255       },
	[61 ] = { RW_ATTRS(mqtt_ble_prefix)                     , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 63        },
	[62 ] = { RW_ATTRS(mqtt_ble_delimiter)                  , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[63 ] = { RW_ATTRS(mqtt_ble_postfix)                    , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 15        },
	[64 ] = { RW_ATTRX(mqtt_ble_quote)                      , ATTR_TYPE_BOOL          , 0x13  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[65 ] = { RW_ATTRX(mqtt_ble_network_id_filter)          , ATTR_TYPE_U16           , 0x13  , av_uint16           , NULL                                , .min.ux = 0         , .max.ux = 0         }
};
/* pyend */

/**************************************************************************************************/
/* Local Function Definitions                                                                     */
/**************************************************************************************************/
/* pystart - get string */
const char *const attr_get_string_lwm2m_security(int value)
{
	switch (value) {
		case 0:           return "PSK";
		case 1:           return "RPK";
		case 2:           return "Cert";
		case 3:           return "No Sec";
		case 4:           return "Cert Est";
		default:          return "?";
	}
}

const char *const attr_get_string_lwm2m_pwr_src(int value)
{
	switch (value) {
		case 0:           return "DC";
		case 1:           return "Int Batt";
		case 2:           return "Ext Batt";
		case 3:           return "Fuel Cell";
		case 4:           return "PoE";
		case 5:           return "USB";
		case 6:           return "AC";
		case 7:           return "Solar";
		default:          return "?";
	}
}

const char *const attr_get_string_lwm2m_batt_stat(int value)
{
	switch (value) {
		case 0:           return "Norm";
		case 1:           return "Charging";
		case 2:           return "Charge Comp";
		case 3:           return "Damaged";
		case 4:           return "Low";
		case 5:           return "Not Inst";
		case 6:           return "Unknown";
		default:          return "?";
	}
}

const char *const attr_get_string_mqtt_peer_verify(int value)
{
	switch (value) {
		case 0:           return "None";
		case 1:           return "Optional";
		case 2:           return "Required";
		case 3:           return "Unset";
		default:          return "?";
	}
}

/* pyend */

/**************************************************************************************************/
/* Global Function Definitions                                                                    */
/**************************************************************************************************/
void attr_table_initialize(void)
{
	memcpy(&rw, &DRW, sizeof(rw_attribute_t));
	memcpy(&ro, &DRO, sizeof(ro_attribute_t));
}

void attr_table_factory_reset(void)
{
	size_t i = 0;
	for (i = 0; i < ATTR_TABLE_SIZE; i++) {
		memcpy(ATTR_TABLE[i].pData, ATTR_TABLE[i].pDefault, ATTR_TABLE[i].size);
	}
}

const struct attr_table_entry *const attr_map(attr_id_t id)
{
	if (id == 0 || id > ATTR_TABLE_MAX_ID) {
		return NULL;
	} else {
		return &ATTR_TABLE[id];
	}
}

attr_index_t attr_table_index(const struct attr_table_entry *const entry)
{
	__ASSERT(PART_OF_ARRAY(ATTR_TABLE, entry), "Invalid entry");
	return (entry - &ATTR_TABLE[0]);
}
