/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __TSC2046_H__
#define __TSC2046_H__

#include "fsl_spi.h"
#include "board.h"
extern spi_master_handle_t touch_handle;

status_t TSC2046_GetSingleTouch(spi_master_handle_t *handle,int *touch_x, int *touch_y);
int touch_init(void);

#endif /* __APP_H__ */
