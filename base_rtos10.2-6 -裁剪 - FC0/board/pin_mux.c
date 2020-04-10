/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.0
processor: LPC54608J512
package_id: LPC54608J512ET180
mcu_data: ksdk2_0
processor_version: 3.0.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"



/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: A2, peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_30/FC0_TXD_SCL_MISO/CTIMER0_MAT0/SCT0_OUT9/TRACEDATA(1), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: B13, peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI/CTIMER2_MAT3/SCT0_OUT8/TRACEDATA(2), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: B12, peripheral: USBFSH, signal: USB_VBUS, pin_signal: PIO0_22/FC6_TXD_SCL_MISO_WS/UTICK_CAP1/CTIMER3_CAP3/SCT0_OUT3/USB0_VBUS, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: A12, peripheral: USBHSH, signal: USB_PORTPWRN, pin_signal: PIO4_9/ENET_TXD1/FC2_RXD_SDA_MOSI/USB1_PORTPWRN/USB1_FRAME/SCT0_GPI2, mode: pullUp, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: A14, peripheral: USBFSH, signal: USB_PORTPWRN, pin_signal: PIO4_7/CTIMER4_CAP3/USB0_PORTPWRN/USB0_FRAME/SCT0_GPI0, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: K12, peripheral: USBHSH, signal: USB_OVERCURRENTN, pin_signal: PIO1_1/FC3_RXD_SDA_MOSI/CTIMER0_CAP3/SCT0_GPI5/USB1_OVERCURRENTN, mode: pullUp, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: B14, peripheral: USBFSH, signal: USB_OVERCURRENTN, pin_signal: PIO4_8/ENET_TXD0/FC2_SCK/USB0_OVERCURRENTN/USB0_UP_LED/SCT0_GPI1, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M4F */
void BOARD_InitPins(void)
{
    /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
    CLOCK_EnableClock(kCLOCK_Iocon);

	EMC_InitPins();
	LCD_InitPins();
	LED_KEY_InitPins();
	USB_InitPins();
	FC_InitPins();
	Touch_InitPins();

		

	
	
}

void Touch_InitPins(void)
{
    const uint32_t port5_pin6_config = (/* Pin is configured as FC9_SCK */
                                         IOCON_PIO_FUNC3 |
                                         /* Selects pull-up function */
                                         IOCON_PIO_MODE_PULLUP |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN20 (coords: N2) is configured as FC9_SCK */
    IOCON_PinMuxSet(IOCON, 5U, 6U, port5_pin6_config);

    const uint32_t port5_pin7_config = (/* Pin is configured as FC9_RXD_SDA_MOSI */
                                         IOCON_PIO_FUNC3 |
                                         /* Selects pull-up function */
                                         IOCON_PIO_MODE_PULLUP |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN21 (coords: P5) is configured as FC9_RXD_SDA_MOSI */
    IOCON_PinMuxSet(IOCON, 5U, 7U, port5_pin7_config);

    const uint32_t port5_pin8_config = (/* Pin is configured as FC9_TXD_SCL_MISO */
                                         IOCON_PIO_FUNC3 |
                                         /* Selects pull-up function */
                                         IOCON_PIO_MODE_PULLUP |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN22 (coords: N5) is configured as FC9_TXD_SCL_MISO */
    IOCON_PinMuxSet(IOCON, 5U, 8U, port5_pin8_config);

    const uint32_t port5_pin9_config = (/* Pin is configured as FC9_CTS_SDA_SSEL0 */
                                         IOCON_PIO_FUNC3 |
                                         /* Selects pull-up function */
                                         IOCON_PIO_MODE_PULLUP |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN30 (coords: K13) is configured as FC9_CTS_SDA_SSEL0 */
    IOCON_PinMuxSet(IOCON, 5U, 9U, port5_pin9_config);

	
}
void FC_InitPins(void)
{
    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: B13) is configured as FC0_RXD_SDA_MOSI */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: A2) is configured as FC0_TXD_SCL_MISO */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);
}

void USB_InitPins(void)
{
    const uint32_t port0_pin22_config = (/* Pin is configured as USB0_VBUS */
                                         IOCON_PIO_FUNC7 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN22 (coords: B12) is configured as USB0_VBUS */
    IOCON_PinMuxSet(IOCON, 0U, 22U, port0_pin22_config);

    const uint32_t port2_pin17_config = (/* Pin is configured as USB1_OVERCURRENTN */
                                        IOCON_PIO_FUNC3 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN1 (coords: K12) is configured as USB1_OVERCURRENTN */
    IOCON_PinMuxSet(IOCON, 2U, 17U, port2_pin17_config);

    const uint32_t port4_pin7_config = (/* Pin is configured as USB0_PORTPWRN */
                                        IOCON_PIO_FUNC3 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN7 (coords: A14) is configured as USB0_PORTPWRN */
    IOCON_PinMuxSet(IOCON, 4U, 7U, port4_pin7_config);

    const uint32_t port0_pin28_config = (/* Pin is configured as USB0_OVERCURRENTN */
                                        IOCON_PIO_FUNC7 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN8 (coords: B14) is configured as USB0_OVERCURRENTN */
    IOCON_PinMuxSet(IOCON, 0U, 28U, port0_pin28_config);
		
    const uint32_t port4_pin9_config = (/* Pin is configured as USB1_PORTPWRN */
                                        IOCON_PIO_FUNC3 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN9 (coords: A12) is configured as USB1_PORTPWRN */
    IOCON_PinMuxSet(IOCON, 4U, 9U, port4_pin9_config);
		
    const uint32_t port4_pin8_config = (/* Pin is configured as USB0_OVERCURRENTN */
                                        4 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN8 (coords: B14) is configured as USB0_OVERCURRENTN */
    IOCON_PinMuxSet(IOCON, 4U, 8U, port4_pin8_config);
		
    const uint32_t port4_pin10_config = (/* Pin is configured as USB0_OVERCURRENTN */
                                        4 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN8 (coords: B14) is configured as USB0_OVERCURRENTN */
    IOCON_PinMuxSet(IOCON, 4U, 10U, port4_pin10_config);

}

void EMC_InitPins(void)
{
  const uint32_t port0_pin15_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_WEN */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN15_IDX, port0_pin15_config); /* PORT0 PIN15 (coords: L4) is configured as EMC_WEN */
  const uint32_t port0_pin18_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN18_IDX, port0_pin18_config); /* PORT0 PIN18 (coords: C14) is configured as EMC_A(0) */
  const uint32_t port0_pin19_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(1) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN19_IDX, port0_pin19_config); /* PORT0 PIN19 (coords: C6) is configured as EMC_A(1) */
  const uint32_t port0_pin2_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN2_IDX, port0_pin2_config); /* PORT0 PIN2 (coords: E9) is configured as EMC_D(0) */
  const uint32_t port0_pin20_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(2) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN20_IDX, port0_pin20_config); /* PORT0 PIN20 (coords: D13) is configured as EMC_A(2) */
  const uint32_t port0_pin21_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(3) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN21_IDX, port0_pin21_config); /* PORT0 PIN21 (coords: C13) is configured as EMC_A(3) */

  const uint32_t port0_pin3_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(1) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN3_IDX, port0_pin3_config); /* PORT0 PIN3 (coords: A10) is configured as EMC_D(1) */

  const uint32_t port0_pin4_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(2) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN4_IDX, port0_pin4_config); /* PORT0 PIN4 (coords: C8) is configured as EMC_D(2) */
  const uint32_t port0_pin5_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(3) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN5_IDX, port0_pin5_config); /* PORT0 PIN5 (coords: E7) is configured as EMC_D(3) */
  const uint32_t port0_pin6_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(4) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN6_IDX, port0_pin6_config); /* PORT0 PIN6 (coords: A5) is configured as EMC_D(4) */
  const uint32_t port0_pin7_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(5) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN7_IDX, port0_pin7_config); /* PORT0 PIN7 (coords: H12) is configured as EMC_D(5) */
  const uint32_t port0_pin8_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(6) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN8_IDX, port0_pin8_config); /* PORT0 PIN8 (coords: H10) is configured as EMC_D(6) */
  const uint32_t port0_pin9_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(7) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT0_IDX, PIN9_IDX, port0_pin9_config); /* PORT0 PIN9 (coords: G12) is configured as EMC_D(7) */
  const uint32_t port1_pin10_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_RASN */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN10_IDX, port1_pin10_config); /* PORT1 PIN10 (coords: N9) is configured as EMC_RASN */
  const uint32_t port1_pin11_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_CLK(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN11_IDX, port1_pin11_config); /* PORT1 PIN11 (coords: B4) is configured as EMC_CLK(0) */
  const uint32_t port1_pin12_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_DYCSN(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN12_IDX, port1_pin12_config); /* PORT1 PIN12 (coords: K9) is configured as EMC_DYCSN(0) */
  const uint32_t port1_pin13_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_DQM(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN13_IDX, port1_pin13_config); /* PORT1 PIN13 (coords: G10) is configured as EMC_DQM(0) */
  const uint32_t port1_pin14_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_DQM(1) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN14_IDX, port1_pin14_config); /* PORT1 PIN14 (coords: C12) is configured as EMC_DQM(1) */
  const uint32_t port1_pin15_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_CKE(0) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN15_IDX, port1_pin15_config); /* PORT1 PIN15 (coords: A11) is configured as EMC_CKE(0) */
  const uint32_t port1_pin16_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(10) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN16_IDX, port1_pin16_config); /* PORT1 PIN16 (coords: B7) is configured as EMC_A(10) */
  const uint32_t port1_pin19_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(8) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN19_IDX, port1_pin19_config); /* PORT1 PIN19 (coords: L1) is configured as EMC_D(8) */
  const uint32_t port1_pin20_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(9) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN20_IDX, port1_pin20_config); /* PORT1 PIN20 (coords: M1) is configured as EMC_D(9) */
  const uint32_t port1_pin21_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(10) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN21_IDX, port1_pin21_config); /* PORT1 PIN21 (coords: N8) is configured as EMC_D(10) */
  const uint32_t port1_pin23_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(11) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN23_IDX, port1_pin23_config); /* PORT1 PIN23 (coords: M10) is configured as EMC_A(11) */
  const uint32_t port1_pin24_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(12) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN24_IDX, port1_pin24_config); /* PORT1 PIN24 (coords: N14) is configured as EMC_A(12) */
  const uint32_t port1_pin25_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(13) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN25_IDX, port1_pin25_config); /* PORT1 PIN25 (coords: M12) is configured as EMC_A(13) */
  const uint32_t port3_pin25_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(14) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN25_IDX, port3_pin25_config); /* PORT3 PIN25 (coords: P9) is configured as EMC_A(14) */
  const uint32_t port1_pin26_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(8) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN26_IDX, port1_pin26_config); /* PORT1 PIN26 (coords: J10) is configured as EMC_A(8) */
  const uint32_t port1_pin27_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(9) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN27_IDX, port1_pin27_config); /* PORT1 PIN27 (coords: F10) is configured as EMC_A(9) */
  const uint32_t port1_pin28_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(12) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN28_IDX, port1_pin28_config); /* PORT1 PIN28 (coords: E12) is configured as EMC_D(12) */
  const uint32_t port1_pin29_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(13) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN29_IDX, port1_pin29_config); /* PORT1 PIN29 (coords: C11) is configured as EMC_D(13) */
  const uint32_t port1_pin30_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(14) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN30_IDX, port1_pin30_config); /* PORT1 PIN30 (coords: A8) is configured as EMC_D(14) */
  const uint32_t port1_pin31_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(15) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN31_IDX, port1_pin31_config); /* PORT1 PIN31 (coords: C5) is configured as EMC_D(15) */
  const uint32_t port1_pin4_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_D(11) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN4_IDX, port1_pin4_config); /* PORT1 PIN4 (coords: D4) is configured as EMC_D(11) */
  const uint32_t port1_pin5_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(4) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN5_IDX, port1_pin5_config); /* PORT1 PIN5 (coords: E4) is configured as EMC_A(4) */
  const uint32_t port1_pin6_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(5) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN6_IDX, port1_pin6_config); /* PORT1 PIN6 (coords: G4) is configured as EMC_A(5) */
  const uint32_t port1_pin7_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(6) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN7_IDX, port1_pin7_config); /* PORT1 PIN7 (coords: N1) is configured as EMC_A(6) */
  const uint32_t port1_pin8_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_A(7) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN8_IDX, port1_pin8_config); /* PORT1 PIN8 (coords: P8) is configured as EMC_A(7) */
  const uint32_t port1_pin9_config = (
    IOCON_PIO_FUNC6 |                                        /* Pin is configured as EMC_CASN */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_FAST |                                    /* Fast mode, slew rate control is disabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT1_IDX, PIN9_IDX, port1_pin9_config); /* PORT1 PIN9 (coords: K6) is configured as EMC_CASN */

}	

void LCD_InitPins(void)
{
  const uint32_t port2_pin11_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_PWR */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN11_IDX, port2_pin11_config); /* PORT2 PIN11 (coords: K3) is configured as LCD_PWR */
  const uint32_t port2_pin13_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_DCLK */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN13_IDX, port2_pin13_config); /* PORT2 PIN13 (coords: P7) is configured as LCD_DCLK */
  const uint32_t port2_pin14_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_FP */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN14_IDX, port2_pin14_config); /* PORT2 PIN14 (coords: L7) is configured as LCD_FP */
  const uint32_t port2_pin15_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_AC */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN15_IDX, port2_pin15_config); /* PORT2 PIN15 (coords: M8) is configured as LCD_AC */
  const uint32_t port2_pin16_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_LP */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN16_IDX, port2_pin16_config); /* PORT2 PIN16 (coords: L8) is configured as LCD_LP */
  const uint32_t port2_pin21_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(3) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN21_IDX, port2_pin21_config); /* PORT2 PIN21 (coords: L10) is configured as LCD_VD(3) */
  const uint32_t port2_pin22_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(4) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN22_IDX, port2_pin22_config); /* PORT2 PIN22 (coords: K10) is configured as LCD_VD(4) */
  const uint32_t port2_pin23_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(5) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN23_IDX, port2_pin23_config); /* PORT2 PIN23 (coords: M14) is configured as LCD_VD(5) */
  const uint32_t port2_pin24_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(6) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN24_IDX, port2_pin24_config); /* PORT2 PIN24 (coords: K14) is configured as LCD_VD(6) */
  const uint32_t port2_pin25_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(7) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN25_IDX, port2_pin25_config); /* PORT2 PIN25 (coords: J11) is configured as LCD_VD(7) */

  const uint32_t port2_pin28_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(10) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN28_IDX, port2_pin28_config); /* PORT2 PIN28 (coords: G13) is configured as LCD_VD(10) */
  const uint32_t port2_pin29_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(11) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN29_IDX, port2_pin29_config); /* PORT2 PIN29 (coords: G11) is configured as LCD_VD(11) */
  const uint32_t port2_pin30_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(12) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN30_IDX, port2_pin30_config); /* PORT2 PIN30 (coords: F12) is configured as LCD_VD(12) */
  const uint32_t port2_pin31_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(13) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT2_IDX, PIN31_IDX, port2_pin31_config); /* PORT2 PIN31 (coords: D14) is configured as LCD_VD(13) */
  const uint32_t port3_pin0_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(14) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN0_IDX, port3_pin0_config); /* PORT3 PIN0 (coords: D12) is configured as LCD_VD(14) */
  const uint32_t port3_pin1_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(15) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN1_IDX, port3_pin1_config); /* PORT3 PIN1 (coords: D11) is configured as LCD_VD(15) */

  const uint32_t port3_pin5_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(19) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN5_IDX, port3_pin5_config); /* PORT3 PIN5 (coords: B10) is configured as LCD_VD(19) */
  const uint32_t port3_pin6_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(20) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN6_IDX, port3_pin6_config); /* PORT3 PIN6 (coords: C9) is configured as LCD_VD(20) */
  const uint32_t port3_pin7_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(21) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN7_IDX, port3_pin7_config); /* PORT3 PIN7 (coords: B8) is configured as LCD_VD(21) */
  const uint32_t port3_pin8_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(22) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN8_IDX, port3_pin8_config); /* PORT3 PIN8 (coords: A7) is configured as LCD_VD(22) */
  const uint32_t port3_pin9_config = (
    IOCON_PIO_FUNC1 |                                        /* Pin is configured as LCD_VD(23) */
    IOCON_PIO_MODE_INACT |                                   /* No addition pin function */
    IOCON_PIO_INV_DI |                                       /* Input function is not inverted */
    IOCON_PIO_DIGITAL_EN |                                   /* Enables digital function */
    IOCON_PIO_INPFILT_OFF |                                  /* Input filter disabled */
    IOCON_PIO_SLEW_STANDARD |                                /* Standard mode, output slew rate control is enabled */
    IOCON_PIO_OPENDRAIN_DI                                   /* Open drain is disabled */
  );
  IOCON_PinMuxSet(IOCON, PORT3_IDX, PIN9_IDX, port3_pin9_config); /* PORT3 PIN9 (coords: C7) is configured as LCD_VD(23) */
	
}

void LED_KEY_InitPins(void)
{
//LED config
    const uint32_t port2_pin2_config = (/* Pin is configured as PIO2_2 */
                                        IOCON_PIO_FUNC0 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN2 (coords: C3) is configured as PIO2_2 */
    IOCON_PinMuxSet(IOCON, 2U, 2U, port2_pin2_config);//zhu dian led
    IOCON_PinMuxSet(IOCON, 3U, 23U, port2_pin2_config);//bei dian led
    IOCON_PinMuxSet(IOCON, 3U, 15U, port2_pin2_config);//sound fault led
    IOCON_PinMuxSet(IOCON, 3U, 16U, port2_pin2_config);//commond fault led
    IOCON_PinMuxSet(IOCON, 4U, 19U, port2_pin2_config);//Fire LED
	IOCON_PinMuxSet(IOCON, 1U, 18U, port2_pin2_config);//sounder led
	IOCON_PinMuxSet(IOCON, 3U, 20U, port2_pin2_config);//silence led
	IOCON_PinMuxSet(IOCON, 2U, 12U, port2_pin2_config);//communication led
	IOCON_PinMuxSet(IOCON, 4U, 22U, port2_pin2_config);//ping bi led
	IOCON_PinMuxSet(IOCON, 2U, 1U, port2_pin2_config);//sent out led
	IOCON_PinMuxSet(IOCON, 3U, 21U, port2_pin2_config);//bei yong led
	IOCON_PinMuxSet(IOCON, 4U, 23U, port2_pin2_config);//heart led----
	
	IOCON_PinMuxSet(IOCON, 3U, 2U, port2_pin2_config);//can0 indication led
	IOCON_PinMuxSet(IOCON, 2U, 5U, port2_pin2_config);//can1 indication led
	IOCON_PinMuxSet(IOCON, 3U, 14U, port2_pin2_config);//485 indication led
	

	
//key
    const uint32_t output_config = (/* Pin is configured as PIO2_2 */
                                        IOCON_PIO_FUNC0 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
	IOCON_PinMuxSet(IOCON, 3U, 13U, output_config);//key_L1
	IOCON_PinMuxSet(IOCON, 0U, 25U, output_config);//key_L2
	IOCON_PinMuxSet(IOCON, 3U, 30U, output_config);//key_L3
	IOCON_PinMuxSet(IOCON, 1U,  3U, output_config);//key_L4
	IOCON_PinMuxSet(IOCON, 3U, 31U, output_config);//key_L5
	IOCON_PinMuxSet(IOCON, 2U, 26U, output_config);//key_L6

    const uint32_t input_config = (/* Pin is configured as PIO2_2 */
                                        IOCON_PIO_FUNC0 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
	
	IOCON_PinMuxSet(IOCON, 3U, 22U, input_config);//key_C1
	IOCON_PinMuxSet(IOCON, 4U, 24U, input_config);//key_C2
	IOCON_PinMuxSet(IOCON, 4U, 25U, input_config);//key_C3
	IOCON_PinMuxSet(IOCON, 4U, 26U, input_config);//key_C4
	
	
//power state
	IOCON_PinMuxSet(IOCON, 0U, 14U, input_config);//key_C3
	IOCON_PinMuxSet(IOCON, 5U, 5U, input_config);//key_C4
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
