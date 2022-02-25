/*
 * Copyright (c) 2022 Laird Connectivity LLC
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

#include <zephyr.h>
#include <sys/printk.h>

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
}
