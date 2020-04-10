/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

/*  Standard C Included Files */
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_lcdc.h"
#include "fsl_i2c.h"
#include "fsl_ft5406.h"

#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "BUTTON.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_I2C_MASTER_BASE (I2C2_BASE)
#define I2C_MASTER_CLOCK_FREQUENCY (12000000)

#define SDRAM_BASE_ADDR 0xa0000000
#define SDRAM_SIZE_BYTES (8 * 1024 * 1024)

#define APP_LCD LCD
#define APP_LCD_IRQHandler LCD_IRQHandler
#define APP_LCD_IRQn LCD_IRQn

#define LCD_PANEL_CLK 30000000
#define LCD_PPL 800
#define LCD_HSW 6
#define LCD_HFP 210
#define LCD_HBP 46
#define LCD_LPP 480
#define LCD_VSW 1
#define LCD_VFP 22
#define LCD_VBP 23
#define LCD_POL_FLAGS kLCDC_InvertVsyncPolarity | kLCDC_InvertHsyncPolarity
#define LCD_INPUT_CLK_FREQ CLOCK_GetFreq(kCLOCK_LCD)
#define LCD_WIDTH 800
#define LCD_HEIGHT 480
#define LCD_BITS_PER_PIXEL 16

/* Work memory for emWin */
#define GUI_NUMBYTES 0x20000
#define GUI_MEMORY_ADDR (SDRAM_BASE_ADDR)

/* Display framebuffer */
#define VRAM_ADDR (GUI_MEMORY_ADDR + GUI_NUMBYTES)
#define VRAM_SIZE (LCD_HEIGHT * LCD_WIDTH * LCD_BITS_PER_PIXEL / 8)
#define EXAMPLE_I2C_MASTER ((I2C_Type *)EXAMPLE_I2C_MASTER_BASE)
#define I2C_MASTER_SLAVE_ADDR_7BIT 0x7EU
#define I2C_BAUDRATE 100000U


/* Frame end flag. */
static volatile bool s_frameEndFlag;

static SemaphoreHandle_t xQueueMutex;
static SemaphoreHandle_t xSemaTxDone;

void APP_LCD_IRQHandler(void)
{
    uint32_t intStatus = LCDC_GetEnabledInterruptsPendingStatus(APP_LCD);

    LCDC_ClearInterruptsStatus(APP_LCD, intStatus);

    if (intStatus & kLCDC_VerticalCompareInterrupt)
    {
        s_frameEndFlag = true;
    }
    __DSB();
}

status_t APP_LCDC_Init(void)
{
    /* Initialize the display. */
    lcdc_config_t lcdConfig;

    LCDC_GetDefaultConfig(&lcdConfig);

    lcdConfig.panelClock_Hz = LCD_PANEL_CLK;
    lcdConfig.ppl = LCD_PPL;
    lcdConfig.hsw = LCD_HSW;
    lcdConfig.hfp = LCD_HFP;
    lcdConfig.hbp = LCD_HBP;
    lcdConfig.lpp = LCD_LPP;
    lcdConfig.vsw = LCD_VSW;
    lcdConfig.vfp = LCD_VFP;
    lcdConfig.vbp = LCD_VBP;
    lcdConfig.polarityFlags = LCD_POL_FLAGS;
    lcdConfig.upperPanelAddr = VRAM_ADDR;
    lcdConfig.bpp = kLCDC_16BPP565;
    lcdConfig.display = kLCDC_DisplayTFT;
    lcdConfig.swapRedBlue = false;

    LCDC_Init(APP_LCD, &lcdConfig, LCD_INPUT_CLK_FREQ);

    /* Trigger interrupt at start of every vertical back porch. */
    LCDC_SetVerticalInterruptMode(APP_LCD, kLCDC_StartOfBackPorch);
    LCDC_EnableInterrupts(APP_LCD, kLCDC_VerticalCompareInterrupt);
    NVIC_EnableIRQ(APP_LCD_IRQn);

    LCDC_Start(APP_LCD);
    LCDC_PowerUp(APP_LCD);

    return kStatus_Success;
}

status_t APP_I2C_Init(void)
{
    i2c_master_config_t masterConfig;

    I2C_MasterGetDefaultConfig(&masterConfig);

    /* Change the default baudrate configuration */
    masterConfig.baudRate_Bps = I2C_BAUDRATE;

    /* Initialize the I2C master peripheral */
    I2C_MasterInit(EXAMPLE_I2C_MASTER, &masterConfig, I2C_MASTER_CLOCK_FREQUENCY);

    return kStatus_Success;
}

/*******************************************************************************
 * Application implemented functions required by emWin library
 ******************************************************************************/
void LCD_X_Config(void)
{
    GUI_DEVICE_CreateAndLink(GUIDRV_LIN_16, GUICC_565, 0, 0);

    LCD_SetSizeEx(0, LCD_WIDTH, LCD_HEIGHT);
    LCD_SetVSizeEx(0, LCD_WIDTH, LCD_HEIGHT);

    LCD_SetVRAMAddrEx(0, (void *)VRAM_ADDR);
}

int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void *pData)
{
    return 0;
}

void GUI_X_Config(void)
{
    /* Assign work memory area to emWin */
    GUI_ALLOC_AssignMemory((void *)GUI_MEMORY_ADDR, GUI_NUMBYTES);

    /* Select default font */
    GUI_SetDefaultFont(GUI_FONT_6X8);
}

/*********************************************************************
*
*       GUI_X_Init()
*
* Note:
*     GUI_X_Init() is called from GUI_Init is a possibility to init
*     some hardware which needs to be up and running before the GUI.
*     If not required, leave this routine blank.
*/
void GUI_X_Init(void)
{
	
}

/*********************************************************************
* 
*      Multitasking:
*
*                 GUI_X_InitOS()
*                 GUI_X_GetTaskId()
*                 GUI_X_Lock()
*                 GUI_X_Unlock()
*
* Note:
*   The following routines are required only if emWin is used in a
*   true multi task environment, which means you have more than one
*   thread using the emWin API.
*   In this case the
*                       #define GUI_OS  (1)
*  needs to be in GUIConf.h
*/

/*! @brief Init OS.Creates the resource semaphore or mutex typically used by GUI_X_Lock() and GUI_X_Unlock().*/
void GUI_X_InitOS(void)
{
	/* Create a Mutex lock*/
	xQueueMutex = xSemaphoreCreateMutex();
	configASSERT(xQueueMutex !=NULL);
	
	vSemaphoreCreateBinary(xSemaTxDone);
	configASSERT(xSemaTxDone != NULL);
}

/*! @brief Locks the GUI*/
void GUI_X_Lock(void)
{
	xSemaphoreTake(xQueueMutex , portMAX_DELAY);
}

/*! @brief Unlocks the GUI */
void GUI_X_Unlock(void)
{
	xSemaphoreGive(xQueueMutex);
}

/*! @brief Get the Task handle */
U32 GUI_X_GetTaskId(void)
{
    return ((uint32_t)xTaskGetCurrentTaskHandle());
}

void GUI_X_WaitEvent (void)
{
	while( xSemaphoreTake(xSemaTxDone, portMAX_DELAY ) != pdTRUE );
}


void GUI_X_SignalEvent (void)
{
	xSemaphoreGive( xSemaTxDone );
}
void GUI_X_ExecIdle(void)
{
}

GUI_TIMER_TIME GUI_X_GetTime(void)
{
    return ((int) xTaskGetTickCount());
}

/*! @brief Returns after a specified time period in milliseconds. */
void GUI_X_Delay(int ms)
{
	vTaskDelay(ms);
}

void *emWin_memcpy(void *pDst, const void *pSrc, long size)
{
    return memcpy(pDst, pSrc, size);
}

#define CLEAR_BUTTON_ID (GUI_ID_BUTTON0)

#define COLOR_BUTTONS 8
#define COLOR_BUTTON_FIRST_ID (GUI_ID_USER)
#define COLOR_BUTTON_LAST_ID (COLOR_BUTTON_FIRST_ID + COLOR_BUTTONS - 1)

static GUI_COLOR button_color[COLOR_BUTTONS] = {GUI_WHITE,   GUI_YELLOW, GUI_ORANGE, GUI_RED,
                                                GUI_MAGENTA, GUI_BLUE,   GUI_GREEN,  GUI_BLACK};

static void cbBackgroundWin(WM_MESSAGE *pMsg)
{
    int widget_id;

    switch (pMsg->MsgId)
    {
        case WM_NOTIFY_PARENT:
            widget_id = WM_GetId(pMsg->hWinSrc);
            if (widget_id >= COLOR_BUTTON_FIRST_ID && widget_id <= COLOR_BUTTON_LAST_ID)
            {
                GUI_SetColor(button_color[widget_id - COLOR_BUTTON_FIRST_ID]);
            }
            else if (widget_id == CLEAR_BUTTON_ID && pMsg->Data.v == WM_NOTIFICATION_CLICKED)
            {
                GUI_Clear();
            }
            break;
        default:
            WM_DefaultProc(pMsg);
    }
}

static void cbCanvasWin(WM_MESSAGE *pMsg)
{
    GUI_PID_STATE *pid_state;
    static GUI_PID_STATE pid_state_0;

    switch (pMsg->MsgId)
    {
        case WM_TOUCH:
            pid_state = (GUI_PID_STATE *)pMsg->Data.p;
            if (pid_state->Pressed)
            {
                if (pid_state_0.Pressed)
                {
                    GUI_DrawLine(pid_state_0.x, pid_state_0.y, pid_state->x, pid_state->y);
                }
                else
                {
                    GUI_DrawPoint(pid_state->x, pid_state->y);
                }
            }
            pid_state_0 = *pid_state;
            break;
        default:
            WM_DefaultProc(pMsg);
    }
}

void emwin_init(void)
{
	int i = 0;
	/* emWin start */
    GUI_Init();

    /* Set size and default color for the background window */
    WM_SetSize(WM_HBKWIN, LCD_WIDTH, LCD_HEIGHT);
    WM_SetDesktopColor(GUI_WHITE);

    /* Set callback for the backgroung window */
    WM_SetCallback(WM_HBKWIN, cbBackgroundWin);

    /* Solid color display */
    GUI_SetBkColor(GUI_WHITE);
    GUI_Clear();

    BUTTON_SetReactOnLevel();

    /* Create the 'clear' button */
    BUTTON_Handle hButtonClear;
    hButtonClear = BUTTON_CreateEx(4, 2, 30, 25, 0, WM_CF_SHOW, 0, CLEAR_BUTTON_ID);
    BUTTON_SetText(hButtonClear, "CLR");

    /* Create color selection buttons */
    BUTTON_Handle hButtonColor[COLOR_BUTTONS];
    for (i = 0; i < COLOR_BUTTONS; i++)
    {
        hButtonColor[i] = BUTTON_CreateEx(4, i * 30 + 32, 30, 25, 0, WM_CF_SHOW, 0, COLOR_BUTTON_FIRST_ID + i);
        BUTTON_SetSkinClassic(hButtonColor[i]);
        BUTTON_SetBkColor(hButtonColor[i], BUTTON_CI_UNPRESSED, button_color[i]);
    }

    /* Create canvas */
    WM_HWIN hCanvas;
    hCanvas = WM_CreateWindowAsChild(35, 0, WM_GetWindowSizeX(WM_HBKWIN) - 35, WM_GetWindowSizeY(WM_HBKWIN), 0,
                                     WM_CF_SHOW, cbCanvasWin, 0);
    /* Select canvas window and leave it selected forever */
    WM_SelectWindow(hCanvas);
    GUI_SetColor(GUI_BLACK);
    GUI_SetDrawMode(GUI_DM_NORMAL);
    GUI_SetPenSize(4);
    GUI_DispStringHCenterAt("Touch and drag to draw.\nClick the CLR button to clear the canvas.",
                            WM_GetWindowSizeX(hCanvas) / 2, WM_GetWindowSizeY(hCanvas) / 2);

    WM_Exec();
	
}
