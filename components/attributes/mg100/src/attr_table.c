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
/* pystart - headers */
#include <zephyr.h>
#include <string.h>
#include <errno_str.h>
#include "attr_validator.h"
#include "attr_custom_validator.h"
/* pyend */
#include "attr_table.h"

/**************************************************************************************************/
/* Local Constant, Macro and Type Definitions                                                     */
/**************************************************************************************************/
/* pystart - RW/RO short defines */
#define DRW DEFAULT_RW_ATTRIBUTE_VALUES
#define DRO DEFAULT_RO_ATTRIBUTE_VALUES
#define y true
#define n false
/* pyend */

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
	char lwm2m_telem_server_url[255 + 1];
	char lwm2m_telem_endpoint[64 + 1];
	enum lwm2m_telem_security lwm2m_telem_security;
	char lwm2m_telem_psk_id[64 + 1];
	uint8_t lwm2m_telem_psk[16];
	uint16_t lwm2m_telem_short_id;
	bool lwm2m_telem_enable;
	char shell_password[32 + 1];
	char tel_trust_path[32 + 1];
	char tel_key_path[32 + 1];
	char dm_trust_path[32 + 1];
	char dm_key_path[32 + 1];
	char fs_trust_path[32 + 1];
	char fs_key_path[32 + 1];
	char p2p_trust_path[32 + 1];
	char p2p_key_path[32 + 1];
	enum lte_log_lvl lte_log_lvl;
} rw_attribute_t;
/* pyend */

/* pystart - rw defaults */
static const rw_attribute_t DEFAULT_RW_ATTRIBUTE_VALUES =  {
	.dump_path = "/lfs1/enc/attr_dump.txt",
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
	.lwm2m_telem_server_url = "coap://leshan.eclipseprojects.io:5683",
	.lwm2m_telem_endpoint = "endpoint",
	.lwm2m_telem_security = 3,
	.lwm2m_telem_psk_id = "my_device",
	.lwm2m_telem_psk = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },
	.lwm2m_telem_short_id = 2,
	.lwm2m_telem_enable = 0,
	.shell_password = "zephyr",
	.tel_trust_path = "/lfs1/tel/trust",
	.tel_key_path = "/lfs1/enc/tel/key",
	.dm_trust_path = "/lfs1/dm/trust",
	.dm_key_path = "/lfs1/enc/dm/key",
	.fs_trust_path = "/lfs1/fs/trust",
	.fs_key_path = "/lfs1/enc/fs/key",
	.p2p_trust_path = "/lfs1/p2p/trust",
	.p2p_key_path = "/lfs1/enc/p2p/key",
	.lte_log_lvl = 2,
};
/* pyend */

/* pystart - ro attributes */
typedef struct ro_attribute {
	char api_version[11 + 1];
	char firmware_version[64 + 1];
	char board[64 + 1];
	enum lwm2m_pwr_src lwm2m_pwr_src;
	int32_t lwm2m_pwr_src_volt;
	enum lwm2m_batt_stat lwm2m_batt_stat;
	char lwm2m_fup_pkg_name[32 + 1];
	char lwm2m_fup_pkg_ver[32 + 1];
	char bluetooth_address[12 + 1];
	char lte_imei[15 + 1];
	char lte_iccid[20 + 1];
	char lte_imsi[15 + 1];
	char lte_sn[14 + 1];
	char lte_version[29 + 1];
	enum lte_network_state lte_network_state;
	enum lte_startup_state lte_startup_state;
	enum lte_init_error lte_init_error;
	char lte_apn[64 + 1];
	int16_t lte_rsrp;
	int16_t lte_sinr;
	char lte_bands[20 + 1];
	char lte_active_bands[20 + 1];
	uint8_t lte_operator_index;
	enum lte_sleep_state lte_sleep_state;
	enum lte_rat lte_rat;
	enum lte_fup_status lte_fup_status;
} ro_attribute_t;
/* pyend */

/* pystart - ro defaults */
static const ro_attribute_t DEFAULT_RO_ATTRIBUTE_VALUES =  {
	.api_version = "0.0.3",
	.firmware_version = "0.0.0+0",
	.board = "my_board",
	.lwm2m_pwr_src = 0,
	.lwm2m_pwr_src_volt = 0,
	.lwm2m_batt_stat = 6,
	.lwm2m_fup_pkg_name = "my_firmware",
	.lwm2m_fup_pkg_ver = "0.0.0",
	.bluetooth_address = "0",
	.lte_imei = "",
	.lte_iccid = "",
	.lte_imsi = "",
	.lte_sn = "",
	.lte_version = "",
	.lte_network_state = 0,
	.lte_startup_state = 0,
	.lte_init_error = 0,
	.lte_apn = "",
	.lte_rsrp = 0,
	.lte_sinr = 0,
	.lte_bands = "",
	.lte_active_bands = "",
	.lte_operator_index = 255,
	.lte_sleep_state = 0,
	.lte_rat = 0,
	.lte_fup_status = 0
};
/* pyend */

/**************************************************************************************************/
/* Local Data Definitions                                                                         */
/**************************************************************************************************/
/* pystart - static define */
static rw_attribute_t rw;
static ro_attribute_t ro;
/* pyend */

/**************************************************************************************************/
/* Global Data Definitions                                                                        */
/**************************************************************************************************/
/* pystart - table */
/**
 * @brief Table shorthand
 *
 * @ref CreateStruct (Python script)
 * Writable but non-savable values are populated using RO macro.
 *
 *.........name...value...default....size...writable..readable..get enum str
 */
#ifdef CONFIG_ATTR_STRING_NAME
#define RW_ATTRS(n) STRINGIFY(n), rw.n, DRW.n, sizeof(rw.n), NULL
#define RW_ATTRX(n) STRINGIFY(n), &rw.n, &DRW.n, sizeof(rw.n), NULL
#define RW_ATTRE(n) STRINGIFY(n), &rw.n, &DRW.n, sizeof(rw.n), attr_get_string_ ## n
#define RO_ATTRS(n) STRINGIFY(n), ro.n, DRO.n, sizeof(ro.n), NULL
#define RO_ATTRX(n) STRINGIFY(n), &ro.n, &DRO.n, sizeof(ro.n), NULL
#define RO_ATTRE(n) STRINGIFY(n), &ro.n, &DRO.n, sizeof(ro.n), attr_get_string_ ## n
#else
#define RW_ATTRS(n) "", rw.n, DRW.n, sizeof(rw.n), NULL
#define RW_ATTRX(n) "", &rw.n, &DRW.n, sizeof(rw.n), NULL
#define RW_ATTRE(n) "", &rw.n, &DRW.n, sizeof(rw.n), attr_get_string_ ## n
#define RO_ATTRS(n) "", ro.n, DRO.n, sizeof(ro.n), NULL
#define RO_ATTRX(n) "", &ro.n, &DRO.n, sizeof(ro.n), NULL
#define RO_ATTRE(n) "", &ro.n, &DRO.n, sizeof(ro.n), attr_get_string_ ## n
#endif
/* pyend */

/* pystart - table */
/* If min == max then range isn't checked. */

/* index....name.....................type.flags.validator..prepare..min.max. */
const struct attr_table_entry ATTR_TABLE[ATTR_TABLE_SIZE] = {
	[0  ] = { RO_ATTRS(api_version)                         , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 6         , .max.ux = 11        },
	[1  ] = { RO_ATTRS(firmware_version)                    , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 5         , .max.ux = 64        },
	[2  ] = { RW_ATTRS(dump_path)                           , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[3  ] = { RW_ATTRS(load_path)                           , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[4  ] = { RO_ATTRS(board)                               , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[5  ] = { RW_ATTRX(log_on_boot)                         , ATTR_TYPE_BOOL          , 0x1f  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[6  ] = { RW_ATTRS(lwm2m_server_url)                    , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[7  ] = { RW_ATTRS(lwm2m_endpoint)                      , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[8  ] = { RW_ATTRE(lwm2m_security)                      , ATTR_TYPE_U8            , 0x1f  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 4         },
	[9  ] = { RW_ATTRS(lwm2m_psk_id)                        , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[10 ] = { RW_ATTRX(lwm2m_psk)                           , ATTR_TYPE_BYTE_ARRAY    , 0x1d  , av_array            , NULL                                , .min.ux = 16        , .max.ux = 16        },
	[11 ] = { RW_ATTRX(lwm2m_bootstrap)                     , ATTR_TYPE_BOOL          , 0x1f  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[12 ] = { RW_ATTRX(lwm2m_short_id)                      , ATTR_TYPE_U16           , 0x1f  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 65534     },
	[13 ] = { RW_ATTRS(lwm2m_mfg)                           , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[14 ] = { RW_ATTRS(lwm2m_mn)                            , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[15 ] = { RW_ATTRS(lwm2m_sn)                            , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[16 ] = { RW_ATTRS(lwm2m_fw_ver)                        , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[17 ] = { RO_ATTRE(lwm2m_pwr_src)                       , ATTR_TYPE_U8            , 0xb   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 7         },
	[18 ] = { RO_ATTRX(lwm2m_pwr_src_volt)                  , ATTR_TYPE_S32           , 0xa   , av_int32            , NULL                                , .min.sx = -600000   , .max.sx = 600000    },
	[19 ] = { RW_ATTRS(lwm2m_sw_ver)                        , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[20 ] = { RW_ATTRS(lwm2m_hw_ver)                        , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[21 ] = { RO_ATTRE(lwm2m_batt_stat)                     , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 6         },
	[22 ] = { RO_ATTRS(lwm2m_fup_pkg_name)                  , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[23 ] = { RO_ATTRS(lwm2m_fup_pkg_ver)                   , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[24 ] = { RW_ATTRS(lwm2m_fup_proxy_srv)                 , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[25 ] = { RO_ATTRS(bluetooth_address)                   , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 12        , .max.ux = 12        },
	[26 ] = { RW_ATTRX(dm_cnx_delay)                        , ATTR_TYPE_U16           , 0x1f  , av_cp16             , NULL                                , .min.ux = 0         , .max.ux = 600       },
	[27 ] = { RW_ATTRX(dm_cnx_delay_min)                    , ATTR_TYPE_U16           , 0x1f  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 599       },
	[28 ] = { RW_ATTRX(dm_cnx_delay_max)                    , ATTR_TYPE_U16           , 0x1f  , av_uint16           , NULL                                , .min.ux = 2         , .max.ux = 600       },
	[29 ] = { RW_ATTRS(factory_load_path)                   , ATTR_TYPE_STRING        , 0x17  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[30 ] = { RW_ATTRS(device_id)                           , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 0         , .max.ux = 64        },
	[31 ] = { RW_ATTRS(lwm2m_telem_server_url)              , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[32 ] = { RW_ATTRS(lwm2m_telem_endpoint)                , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[33 ] = { RW_ATTRE(lwm2m_telem_security)                , ATTR_TYPE_U8            , 0x1f  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 4         },
	[34 ] = { RW_ATTRS(lwm2m_telem_psk_id)                  , ATTR_TYPE_STRING        , 0x1f  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 64        },
	[35 ] = { RW_ATTRX(lwm2m_telem_psk)                     , ATTR_TYPE_BYTE_ARRAY    , 0x1d  , av_array            , NULL                                , .min.ux = 16        , .max.ux = 16        },
	[36 ] = { RW_ATTRX(lwm2m_telem_short_id)                , ATTR_TYPE_U16           , 0x1f  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 65534     },
	[37 ] = { RW_ATTRX(lwm2m_telem_enable)                  , ATTR_TYPE_BOOL          , 0x1f  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[38 ] = { RW_ATTRS(shell_password)                      , ATTR_TYPE_STRING        , 0x495 , av_string           , NULL                                , .min.ux = 4         , .max.ux = 32        },
	[39 ] = { RW_ATTRS(tel_trust_path)                      , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[40 ] = { RW_ATTRS(tel_key_path)                        , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[41 ] = { RW_ATTRS(dm_trust_path)                       , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[42 ] = { RW_ATTRS(dm_key_path)                         , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[43 ] = { RW_ATTRS(fs_trust_path)                       , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[44 ] = { RW_ATTRS(fs_key_path)                         , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[45 ] = { RW_ATTRS(p2p_trust_path)                      , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[46 ] = { RW_ATTRS(p2p_key_path)                        , ATTR_TYPE_STRING        , 0x13  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[47 ] = { RO_ATTRS(lte_imei)                            , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 15        },
	[48 ] = { RO_ATTRS(lte_iccid)                           , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 20        },
	[49 ] = { RO_ATTRS(lte_imsi)                            , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 14        , .max.ux = 15        },
	[50 ] = { RO_ATTRS(lte_sn)                              , ATTR_TYPE_STRING        , 0x2   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 14        },
	[51 ] = { RO_ATTRS(lte_version)                         , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 29        },
	[52 ] = { RO_ATTRE(lte_network_state)                   , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[53 ] = { RO_ATTRE(lte_startup_state)                   , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[54 ] = { RO_ATTRE(lte_init_error)                      , ATTR_TYPE_S8            , 0xa   , av_int8             , NULL                                , .min.sx = 0         , .max.sx = 0         },
	[55 ] = { RO_ATTRS(lte_apn)                             , ATTR_TYPE_STRING        , 0xb   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 64        },
	[56 ] = { RO_ATTRX(lte_rsrp)                            , ATTR_TYPE_S16           , 0xa   , av_int16            , NULL                                , .min.sx = 0         , .max.sx = 0         },
	[57 ] = { RO_ATTRX(lte_sinr)                            , ATTR_TYPE_S16           , 0xa   , av_int16            , NULL                                , .min.sx = 0         , .max.sx = 0         },
	[58 ] = { RO_ATTRS(lte_bands)                           , ATTR_TYPE_STRING        , 0xb   , av_string           , NULL                                , .min.ux = 1         , .max.ux = 20        },
	[59 ] = { RO_ATTRS(lte_active_bands)                    , ATTR_TYPE_STRING        , 0xa   , av_string           , NULL                                , .min.ux = 0         , .max.ux = 20        },
	[60 ] = { RO_ATTRX(lte_operator_index)                  , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[61 ] = { RO_ATTRE(lte_sleep_state)                     , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[62 ] = { RO_ATTRE(lte_rat)                             , ATTR_TYPE_U8            , 0xb   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[63 ] = { RW_ATTRE(lte_log_lvl)                         , ATTR_TYPE_U8            , 0x1b  , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         },
	[64 ] = { RO_ATTRE(lte_fup_status)                      , ATTR_TYPE_U8            , 0xa   , av_uint8            , NULL                                , .min.ux = 0         , .max.ux = 0         }
};
/* pyend */

/**************************************************************************************************/
/**************************************************************************************************/
/* Local Function Definitions                                                                     */
/**************************************************************************************************/
/* pystart - get string */
#ifdef CONFIG_ATTR_STRING_NAME
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

const char *const attr_get_string_lwm2m_telem_security(int value)
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

const char *const attr_get_string_lte_network_state(int value)
{
	switch (value) {
		case 0:           return "Not Registered";
		case 1:           return "Home Network";
		case 2:           return "Searching";
		case 3:           return "Registration Denied";
		case 4:           return "Out Of Coverage";
		case 5:           return "Roaming";
		case 8:           return "Emergency";
		case 240:         return "Unable To Configure";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_startup_state(int value)
{
	switch (value) {
		case 0:           return "Ready";
		case 1:           return "Waiting For ACcess Code";
		case 2:           return "Sim Not Present";
		case 3:           return "Sim Lock";
		case 4:           return "Unrecoverable Error";
		case 5:           return "Unknown";
		case 6:           return "Inactive Sim";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_init_error(int value)
{
	switch (value) {
		case 0:           return "None";
		case -1:          return "No Iface";
		case -2:          return "Iface Cfg";
		case -3:          return "Dns Cfg";
		case -4:          return "Modem";
		case -5:          return "Airplane";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_sleep_state(int value)
{
	switch (value) {
		case 0:           return "Uninitialized";
		case 1:           return "Hibernate";
		case 2:           return "Awake";
		case 3:           return "Lite Hibernate";
		case 4:           return "Sleep";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_rat(int value)
{
	switch (value) {
		case 0:           return "Cat M1";
		case 1:           return "Cat NB1";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_log_lvl(int value)
{
	switch (value) {
		case 0:           return "None";
		case 1:           return "Error";
		case 2:           return "Warning";
		case 3:           return "Info";
		case 4:           return "Debug";
		default:          return "?";
	}
}

const char *const attr_get_string_lte_fup_status(int value)
{
	switch (value) {
		case 0:           return "Idle";
		case 1:           return "Start";
		case 2:           return "Wip";
		case 3:           return "Pad";
		case 4:           return "Send Eot";
		case 5:           return "File Err";
		case 6:           return "Install";
		case 7:           return "Reboot Reconfig";
		case 8:           return "Complete";
		default:          return "?";
	}
}

#endif
/* pyend */

/**************************************************************************************************/
/* Global Function Definitions                                                                    */
/**************************************************************************************************/
/* pystart - attribute functions */
void attr_table_initialize(void)
{
	memcpy(&rw, &DRW, sizeof(rw_attribute_t));
	memcpy(&ro, &DRO, sizeof(ro_attribute_t));
}

void attr_table_factory_reset(void)
{
	size_t i = 0;
	for (i = 0; i < ATTR_TABLE_SIZE; i++) {
		memcpy(ATTR_TABLE[i].pData, ATTR_TABLE[i].pDefault,
			   ATTR_TABLE[i].size);
		}
}

const struct attr_table_entry *const attr_map(attr_id_t id)
{
	if (id > ATTR_TABLE_MAX_ID) {
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
/* pyend */

