/*
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

/**************************************************************************************************/
/* Includes                                                                                       */
/**************************************************************************************************/
#include <logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);
#include <zephyr.h>
#include <version.h>
#ifdef CONFIG_LCZ_MCUMGR_WRAPPER
#include "mcumgr_wrapper.h"
#endif
#ifdef CONFIG_FILE_SYSTEM_UTILITIES
#include "file_system_utilities.h"
#endif
#ifdef CONFIG_LCZ_HW_KEY
#include "lcz_hw_key.h"
#endif
#ifdef CONFIG_ATTR
#include "attr.h"
#endif
#ifdef CONFIG_LCZ_LWM2M_CLIENT
#include "lcz_lwm2m_client.h"
#endif
#ifdef CONFIG_LCZ_LWM2M_FW_UPDATE
#include "lcz_lwm2m_fw_update.h"
#endif
#include "app_version.h"
#ifdef CONFIG_SHELL_BACKEND_SERIAL
#include <shell/shell_uart.h>
#endif

/**************************************************************************************************/
/* Local Constant, Macro and Type Definitions                                                     */
/**************************************************************************************************/
#define DEFAULT_HW_VERSION "0"
#define PKG_NAME_PREFIX "BLE_GW_DM"
#define PKG_NAME PKG_NAME_PREFIX "[" CONFIG_BOARD "]"

/**************************************************************************************************/
/* Global Function Definitions                                                                    */
/**************************************************************************************************/
void main(void)
{
#ifdef CONFIG_SHELL_BACKEND_SERIAL
	/* Disable log output by default on the UART console.
	 * Re-enable logging using the 'log go' cmd.
	 * LCZ_SHELL_LOGIN selects SHELL_START_OBSCURED which disables log output before main().
	 */
#ifdef CONFIG_ATTR
	if (*(bool *)attr_get_quasi_static(ATTR_ID_log_on_boot) == false)
#endif
	{
		log_backend_deactivate(shell_backend_uart_get_ptr()->log_backend->backend);
	}
#endif
#ifdef CONFIG_FILE_SYSTEM_UTILITIES
	fsu_lfs_mount();
#endif

#ifdef CONFIG_LCZ_MCUMGR_WRAPPER
	mcumgr_wrapper_register_subsystems();
#endif

#ifdef CONFIG_ATTR
	(void)attr_set_string(ATTR_ID_firmware_version, APP_VERSION_STRING,
			      strlen(APP_VERSION_STRING));
	(void)attr_set_string(ATTR_ID_board, CONFIG_BOARD, strlen(CONFIG_BOARD));
#endif
#ifdef CONFIG_LCZ_LWM2M_CLIENT
	(void)lcz_lwm2m_client_set_device_model_number(CONFIG_BOARD);
	(void)lcz_lwm2m_client_set_device_firmware_version(APP_VERSION_STRING);
	(void)lcz_lwm2m_client_set_software_version(KERNEL_VERSION_STRING);
	(void)lcz_lwm2m_client_set_hardware_version(DEFAULT_HW_VERSION);
#endif
#ifdef CONFIG_LCZ_LWM2M_FW_UPDATE
	(void)lcz_lwm2m_fw_update_set_pkg_name(PKG_NAME);
	(void)lcz_lwm2m_fw_update_set_pkg_version(APP_VERSION_STRING);
#endif

	LOG_INF("BLE Gateway DM Firmware v%s [%s]", APP_VERSION_STRING, CONFIG_BOARD);
}
