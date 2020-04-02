#include "fsl_debug_console.h"
#include "lcd_app.h"
#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "BUTTON.h"

void vLcdTask(void *pvParameters)
{
	for(;;)
	{
		WM_Exec();
		GUI_Delay(10);
	}
}
