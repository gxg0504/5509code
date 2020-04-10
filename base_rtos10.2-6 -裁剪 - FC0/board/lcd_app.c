#include "fsl_debug_console.h"
#include "lcd_app.h"
#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "BUTTON.h"
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"
#include "fsl_spi.h"
#define TOUCH_DELAY   (20)



spi_master_handle_t touch_handle;		
int cursorPosX;
int cursorPosY;
GUI_PID_STATE pid_state;

//void vTouchTask(void *pvParameters)
//{
//	for(;;)
//	{
//		if (kStatus_Success != TSC2046_GetSingleTouch(&touch_handle,  &cursorPosX, &cursorPosY))
//		{
//				PRINTF("error reading touch controller\r\n");
//		}
//		else
//		{
//				pid_state.x = cursorPosY;
//				pid_state.y = cursorPosX;
//				pid_state.Pressed = 0;
//				pid_state.Layer = 0;
//				GUI_TOUCH_StoreStateEx(&pid_state);
//		}
//		vTaskDelay(TOUCH_DELAY);
//	}
//}

extern void test(void);
void vTouchTask(void *pvParameters)
{
	for(;;)
	{
		test();
		vTaskDelay(TOUCH_DELAY);
	}
}


void vLcdTask(void *pvParameters)
{
	for(;;)
	{
		WM_Exec();
		GUI_Delay(10);
	}
}

