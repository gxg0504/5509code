/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spi.h"
#include "board.h"
#include "fsl_debug_console.h"

#include "tsc2046.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SPI_MASTER SPI5
#define EXAMPLE_SPI_MASTER_IRQ FLEXCOMM5_IRQn
#define EXAMPLE_SPI_MASTER_CLK_SRC kCLOCK_Flexcomm5
#define EXAMPLE_SPI_MASTER_CLK_FREQ CLOCK_GetFreq(kCLOCK_Flexcomm5)
#define EXAMPLE_SPI_SSEL 0
#define EXAMPLE_SPI_SPOL kSPI_SpolActiveAllLow

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define BUFFER_SIZE (3)
static uint8_t srcBuff[BUFFER_SIZE];
static uint8_t destBuff[BUFFER_SIZE];
uint16_t data16;
/*******************************************************************************
 * Code
 ******************************************************************************/
#define	CHX 	        0x90 	/* 通道Y+的选择控制字 */	
#define	CHY 	        0xd0	/* 通道X+的选择控制字 */
int touch_init(void)
{
    spi_master_config_t userConfig = {0};
    uint32_t srcFreq               = 0;

    /* attach 12 MHz clock to SPI9 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM5);

    /* reset FLEXCOMM for SPI */
    RESET_PeripheralReset(kFC5_RST_SHIFT_RSTn);

    
    /*
     * userConfig.enableLoopback = false;
     * userConfig.enableMaster = true;
     * userConfig.polarity = kSPI_ClockPolarityActiveHigh;
     * userConfig.phase = kSPI_ClockPhaseFirstEdge;
     * userConfig.direction = kSPI_MsbFirst;
     * userConfig.baudRate_Bps = 500000U;
     */
    SPI_MasterGetDefaultConfig(&userConfig);
    srcFreq            = EXAMPLE_SPI_MASTER_CLK_FREQ;
    userConfig.sselNum = (spi_ssel_t)EXAMPLE_SPI_SSEL;
    userConfig.sselPol = (spi_spol_t)EXAMPLE_SPI_SPOL;
    SPI_MasterInit(EXAMPLE_SPI_MASTER, &userConfig, srcFreq);


}

typedef enum _touch_event
{
    kTouch_Down = 0,    /*!< The state changed to touched. */
    kTouch_Up = 1,      /*!< The state changed to not touched. */
    kTouch_Contact = 2, /*!< There is a continuous touch being detected. */
    kTouch_Reserved = 3 /*!< No touch information available. */
} touch_event_t;

status_t TSC2046_GetSingleTouch(spi_master_handle_t *handle,int *touch_x, int *touch_y)
{
    status_t status;
    spi_transfer_t xfer            = {0};
		uint16_t data16 = 0;
	
		srcBuff[0] = CHX;
		srcBuff[1] = 0;
		srcBuff[2] = 0;
    xfer.txData   = srcBuff;
    xfer.rxData   = destBuff;
    xfer.dataSize = sizeof(destBuff);
    status = SPI_MasterTransferBlocking(EXAMPLE_SPI_MASTER, &xfer);
    if (status == kStatus_Success)
    {
					data16 = destBuff[1];
					data16 = (data16<<8) + destBuff[2];
          PRINTF("data is %d\n\r", data16);
					*touch_x = data16;
					data16 = 0;
    }
		
		srcBuff[0] = CHY;
		srcBuff[1] = 0;
		srcBuff[2] = 0;
    xfer.txData   = srcBuff;
    xfer.rxData   = destBuff;
    xfer.dataSize = sizeof(destBuff);
    status = SPI_MasterTransferBlocking(EXAMPLE_SPI_MASTER, &xfer);
    if (status == kStatus_Success)
    {
					data16 = destBuff[1];
					data16 = (data16<<8) + destBuff[2];
          PRINTF("data is %d\n\r", data16);
					*touch_x = data16;
					data16 = 0;
    }


    return status;
}

uint8_t getX(uint8_t command)
{
		uint16_t data16 = 0;
		uint32_t st = 0;
		SPI_WriteData(EXAMPLE_SPI_MASTER,(uint16_t)command,0);
		st = SPI_GetStatusFlags(EXAMPLE_SPI_MASTER);
		PRINTF("%d\n",st);
		data16 = SPI_ReadData(EXAMPLE_SPI_MASTER);
	
}
void test(void)
{
    spi_transfer_t xfer            = {0};
		uint16_t data16 = 0;

//			srcBuff[0] = CHX;
//			srcBuff[1] = 0;
//			srcBuff[1] = 0;

//			/*Start Transfer*/
//			xfer.txData   = srcBuff;
//			xfer.rxData   = destBuff;
//			xfer.dataSize = sizeof(destBuff);
//			SPI_MasterTransferBlocking(EXAMPLE_SPI_MASTER, &xfer);


//			data16 = destBuff[1];
//			data16 = (data16<<8) + destBuff[2];
//			PRINTF("X: is %d  ", data16);
//			data16 = 0;


//			srcBuff[0] = CHY;
//			srcBuff[1] = 0;
//			srcBuff[1] = 0;

//			/*Start Transfer*/
//			xfer.txData   = srcBuff;
//			xfer.rxData   = destBuff;
//			xfer.dataSize = sizeof(destBuff);
////			SPI_MasterTransferBlocking(EXAMPLE_SPI_MASTER, &xfer);


//			data16 = destBuff[1];
//			data16 = (data16<<8) + destBuff[2];
//			PRINTF("Y: is %d\n\r", data16);
//			data16 = 0;
				getX(CHY);
				data16 = getX(0);
				data16 = (data16<<8) + getX(0);
				PRINTF("x: is %d\n\r", data16);
}
