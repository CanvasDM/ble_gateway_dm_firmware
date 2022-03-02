/**
 * @file app_version.h
 * @brief
 *
 * Copyright (c) 2022 Laird Connectivity
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */
#ifndef __APP_VERSION_H__
#define __APP_VERSION_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************/
/* Application Firmware Version                                                                   */
/**************************************************************************************************/
#define APP_VERSION_MAJOR 0
#define APP_VERSION_MINOR 1
#define APP_VERSION_PATCH 0
#define APP_VERSION_STRING                                                                         \
	STRINGIFY(APP_VERSION_MAJOR)                                                               \
	"." STRINGIFY(APP_VERSION_MINOR) "." STRINGIFY(APP_VERSION_PATCH)

#ifdef __cplusplus
}
#endif

#endif /* __APP_VERSION_H__ */
