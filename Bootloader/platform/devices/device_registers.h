/*
 * Copyright 2020-2022 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file device_registers.h
 * @version 1.4.0
 */

#ifndef DEVICE_REGISTERS_H
#define DEVICE_REGISTERS_H

#define STD_ON  (1)
#define STD_OFF (0)

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */

/* Register definitions */
#include "YTM32B1MD2/include/YTM32B1MD2.h"
/* CPU specific feature definitions */
#include "YTM32B1MD2/include/YTM32B1MD2_features.h"
#include "YTM32B1MD2/startup/system_YTM32B1MD2.h"

#include "devassert.h"

#endif /* DEVICE_REGISTERS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
