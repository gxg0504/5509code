/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"
/*  Standard C Included Files */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "fsl_common.h"
#include "fsl_power.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"

#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "BUTTON.h"
#include "emwin_config.h"

#include "usb_host_config.h"
#include "usb_host.h"
#include "usb_host_msd.h"
#include "host_msd_fatfs.h"

#include "board.h"
#include "pin_mux.h"

#include "usb_app.h"
#include "lcd_app.h"
#include "key_led_app.h"
#include "usart_app.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
//Touch
#define TOUCHTASK_STACKSIZE 100
#define TOUCHTASK_PRIORITY  (tskIDLE_PRIORITY + 1UL)
TaskHandle_t xTouchTaskHandle = NULL;
//LCD
#define LCDTASK_PRIORITY  		(tskIDLE_PRIORITY + 0UL)
#define LCDTASK_STACKSIZE 		512
TaskHandle_t xLcdTaskHandle = NULL;
//USB App
#define USBAPPTASK_PRIORITY  	(tskIDLE_PRIORITY + 1UL)
#define USBAPPTASK_STACKSIZE 	512
TaskHandle_t xUsbAppTaskHandle = NULL;
//USB Host
#define USBHOSTTASK_PRIORITY  	(tskIDLE_PRIORITY + 2UL)
#define USBHOSTTASK_STACKSIZE 	512
TaskHandle_t xUsbHostTaskHandle = NULL;
//LED
#define LEDTASK_PRIORITY  	(tskIDLE_PRIORITY + 3UL)
#define LEDTASK_STACKSIZE 	128
TaskHandle_t xLedTaskHandle = NULL;
//KEY
#define KEYTASK_PRIORITY  	(tskIDLE_PRIORITY + 4UL)
#define KEYTASK_STACKSIZE 	128
TaskHandle_t xKeyTaskHandle = NULL;
//Uart0
#define FC0TASK_PRIORITY  	(tskIDLE_PRIORITY + 5UL)
#define FC0TASK_STACKSIZE 	128
TaskHandle_t xFC0TaskHandle = NULL;

int main(void)
{
	status_t status;
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    /* Route Main clock to LCD. */
    CLOCK_AttachClk(kMAIN_CLK_to_LCD_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivLcdClk, 1, true);
	
    BOARD_InitPins();
    BOARD_BootClockFROHF96M();
    BOARD_InitDebugConsole();
	BOARD_InitSDRAM();
    POWER_DisablePD(kPDRUNCFG_PD_USB0_PHY); /*< Turn on USB Phy */
    POWER_DisablePD(kPDRUNCFG_PD_USB1_PHY); /*< Turn on USB Phy */
	
	USB_HostApplicationInit();
	
		touch_init();
    status = APP_LCDC_Init();
    if (status != kStatus_Success){PRINTF("LCD init failed\n");}
    assert(status == kStatus_Success);
	
	emwin_init();
	
	//GPIO Init
	GPIO_Config();
//	board_key_init();
	board_led_init();

	xTaskCreate(vTouchTask,"Touch Task",TOUCHTASK_STACKSIZE,NULL,TOUCHTASK_PRIORITY,&xTouchTaskHandle);

	//LCD Task
	if(xTaskCreate(vLcdTask,"LCD Task",LCDTASK_STACKSIZE,NULL,LCDTASK_PRIORITY,&xLcdTaskHandle) != pdPASS)
	{
        PRINTF("create LCD task error\r\n");
	}
	//USB APP Task
    if (xTaskCreate(USB_HostTask, "usb host task", USBHOSTTASK_STACKSIZE, g_HostHandle, USBHOSTTASK_PRIORITY, &xUsbHostTaskHandle) != pdPASS)
    {
        PRINTF("create host task error\r\n");
    }
	//USB APP Task
    if (xTaskCreate(USB_HostApplicationTask, "app task", USBAPPTASK_STACKSIZE, &g_MsdFatfsInstance, USBAPPTASK_PRIORITY,&xUsbAppTaskHandle) != pdPASS)
    {
        PRINTF("create mouse task error\r\n");
    }
	//LED Task
	if(xTaskCreate(vLedTask,"LED Task",LEDTASK_STACKSIZE,NULL,LEDTASK_PRIORITY,&xLedTaskHandle) != pdPASS)
	{
        PRINTF("create LED task error\r\n");
	}
	//Key Task
//	if(xTaskCreate(vKeyTask,"Key Task",KEYTASK_STACKSIZE,NULL,KEYTASK_PRIORITY,&xKeyTaskHandle) != pdPASS)
//	{
//        PRINTF("create LED task error\r\n");
//	}
	
//	if (xTaskCreate(uart_task, "Uart_task", FC0TASK_STACKSIZE, NULL, FC0TASK_PRIORITY, &xFC0TaskHandle) != pdPASS)
//	{
//			PRINTF("Task creation failed!.\r\n");
//	}
	
	
    vTaskStartScheduler();

    while (1)
    {
        ;
    }
}
