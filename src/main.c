/*
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#include <zephyr.h>

#ifdef CONFIG_LCZ_MCUMGR_WRAPPER
#include "mcumgr_wrapper.h"
#endif
#ifdef CONFIG_FILE_SYSTEM_UTILITIES
#include "file_system_utilities.h"
#endif
#ifdef CONFIG_LCZ_HW_KEY
#include "lcz_hw_key.h"
#endif

#include "app_version.h"

void main(void)
{
#ifdef CONFIG_LCZ_HW_KEY
	lcz_hw_key_generate_and_init();
#endif

#ifdef CONFIG_FILE_SYSTEM_UTILITIES
	fsu_lfs_mount();
#endif

#ifdef CONFIG_LCZ_MCUMGR_WRAPPER
	mcumgr_wrapper_register_subsystems();
#endif

	LOG_INF("BLE Gateway DM Firmware v%s [%s]", APP_VERSION_STRING, CONFIG_BOARD);
}
