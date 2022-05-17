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
	char lwm2m_server_url[255 + 1];
	char lwm2m_endpoint[32 + 1];
	enum lwm2m_security lwm2m_security;
	char lwm2m_psk_id[32 + 1];
	uint8_t lwm2m_psk[16];
	bool lwm2m_bootstrap;
	uint16_t lwm2m_short_id;
} rw_attribute_t;
/* pyend */

/* pystart - rw defaults */
static const rw_attribute_t DEFAULT_RW_ATTRIBUTE_VALUES =  {
	.dump_path = "/lfs1/attr_dump.txt",
	.load_path = "/lfs1/attr_load.txt",
	.lwm2m_server_url = "coap://leshan.eclipseprojects.io:5683",
	.lwm2m_endpoint = "my_device",
	.lwm2m_security = 3,
	.lwm2m_psk_id = "my_device",
	.lwm2m_psk = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },
	.lwm2m_bootstrap = 0,
	.lwm2m_short_id = 1
};
/* pyend */

/* pystart - ro attributes */
typedef struct ro_attribute {
	char api_version[11 + 1];
	char firmware_version[64 + 1];
	char board[64 + 1];
} ro_attribute_t;
/* pyend */

/* pystart - ro defaults */
static const ro_attribute_t DEFAULT_RO_ATTRIBUTE_VALUES =  {
	.api_version = "0.0.1",
	.firmware_version = "0.0.0+0",
	.board = "my_board",
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
	[5  ] = { RW_ATTRS(lwm2m_server_url)                    , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 11        , .max.ux = 255       },
	[6  ] = { RW_ATTRS(lwm2m_endpoint)                      , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[7  ] = { RW_ATTRE(lwm2m_security)                      , ATTR_TYPE_U8            , 0x1b  , av_uint8            , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[8  ] = { RW_ATTRS(lwm2m_psk_id)                        , ATTR_TYPE_STRING        , 0x1b  , av_string           , NULL                                , .min.ux = 1         , .max.ux = 32        },
	[9  ] = { RW_ATTRX(lwm2m_psk)                           , ATTR_TYPE_BYTE_ARRAY    , 0x1b  , av_array            , NULL                                , .min.ux = 16        , .max.ux = 16        },
	[10 ] = { RW_ATTRX(lwm2m_bootstrap)                     , ATTR_TYPE_BOOL          , 0x1b  , av_bool             , NULL                                , .min.ux = 0         , .max.ux = 1         },
	[11 ] = { RW_ATTRX(lwm2m_short_id)                      , ATTR_TYPE_U16           , 0x1b  , av_uint16           , NULL                                , .min.ux = 1         , .max.ux = 65534     }
};
/* pyend */

/**************************************************************************************************/
/**************************************************************************************************/
/* Local Function Definitions                                                                     */
/**************************************************************************************************/
/* pystart - prepare for read */
/* pyend */

/* pystart - get string */
#ifdef CONFIG_ATTR_STRING_NAME
const char *const attr_get_string_lwm2m_security(int value)
{
	switch (value) {
		case 0:           return "LwM2M Sec Psk";
		case 1:           return "LwM2M Sec Rpk";
		case 2:           return "LwM2M Sec Cert";
		case 3:           return "LwM2M Sec No Sec";
		case 4:           return "LwM2M Sec Cert Est";
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

