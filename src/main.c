/*
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#include <zephyr.h>

#include "app_version.h"

void main(void)
{
	LOG_INF("BLE Gateway DM Firmware v%s [%s]", APP_VERSION_STRING, CONFIG_BOARD);
}
