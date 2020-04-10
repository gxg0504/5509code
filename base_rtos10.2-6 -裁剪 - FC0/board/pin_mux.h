/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */



#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


#define IOCON_PIO_DIGITAL_EN 	0x0100u  /*!<@brief Enables digital function */
#define IOCON_PIO_FUNC0 		0x00u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC1 		0x01u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC2 		0x02u         /*!<@brief Selects pin function 3 */
#define IOCON_PIO_FUNC3 		0x03u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC4 		0x04u         /*!<@brief Selects pin function 3 */
#define IOCON_PIO_FUNC5 		0x05u         /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC6 		0x06u         /*!<@brief Selects pin function 3 */
#define IOCON_PIO_FUNC7 		0x07u         /*!<@brief Selects pin function 7 */
#define IOCON_PIO_INPFILT_OFF 	0x0200u /*!<@brief Input filter disabled */
#define IOCON_PIO_INV_DI 		0x00u        /*!<@brief Input function is not inverted */
#define IOCON_PIO_MODE_INACT 	0x00u    /*!<@brief No addition pin function */
#define IOCON_PIO_MODE_PULLUP 	0x20u   /*!<@brief Selects pull-up function */
#define IOCON_PIO_OPENDRAIN_DI 	0x00u  /*!<@brief Open drain is disabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u /*!<@brief Standard mode, output slew rate control is enabled */
#define IOCON_PIO_SLEW_FAST     0x0400u   /*!< Fast mode, slew rate control is disabled */

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port 3 */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port 3 */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port 0 */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port 0 */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port 0 */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port 0 */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port 0 */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port 0 */
#define PIN8_IDX                         8u   /*!< Pin number for pin 8 in a port 0 */
#define PIN9_IDX                         9u   /*!< Pin number for pin 9 in a port 0 */
#define PIN10_IDX                       10u   /*!< Pin number for pin 10 in a port 1 */
#define PIN11_IDX                       11u   /*!< Pin number for pin 11 in a port 1 */
#define PIN12_IDX                       12u   /*!< Pin number for pin 12 in a port 1 */
#define PIN13_IDX                       13u   /*!< Pin number for pin 13 in a port 1 */
#define PIN14_IDX                       14u   /*!< Pin number for pin 14 in a port 1 */
#define PIN15_IDX                       15u   /*!< Pin number for pin 15 in a port 0 */
#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port 1 */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port 0 */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port 0 */
#define PIN20_IDX                       20u   /*!< Pin number for pin 20 in a port 0 */
#define PIN21_IDX                       21u   /*!< Pin number for pin 21 in a port 0 */
#define PIN22_IDX                       22u   /*!< Pin number for pin 22 in a port 2 */
#define PIN23_IDX                       23u   /*!< Pin number for pin 23 in a port 1 */
#define PIN24_IDX                       24u   /*!< Pin number for pin 24 in a port 1 */
#define PIN25_IDX                       25u   /*!< Pin number for pin 25 in a port 1 */
#define PIN26_IDX                       26u   /*!< Pin number for pin 26 in a port 1 */
#define PIN27_IDX                       27u   /*!< Pin number for pin 27 in a port 1 */
#define PIN28_IDX                       28u   /*!< Pin number for pin 28 in a port 1 */
#define PIN29_IDX                       29u   /*!< Pin number for pin 29 in a port 0 */
#define PIN30_IDX                       30u   /*!< Pin number for pin 30 in a port 0 */
#define PIN31_IDX                       31u   /*!< Pin number for pin 31 in a port 1 */
#define PORT0_IDX                        0u   /*!< Port index */
#define PORT1_IDX                        1u   /*!< Port index */
#define PORT2_IDX                        2u   /*!< Port index */
#define PORT3_IDX                        3u   /*!< Port index */
/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M4F */
void EMC_InitPins(void);
void LCD_InitPins(void);
void LED_KEY_InitPins(void);
void USB_InitPins(void);
void FC_InitPins(void);
void Touch_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
