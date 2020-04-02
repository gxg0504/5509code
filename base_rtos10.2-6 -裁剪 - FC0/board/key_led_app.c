#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"
#include "key_led_app.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"


void vLedTask(void *pvParameters)
{
	
	for(;;)
	{
		GPIO_PortToggle(GPIO, 2, 1u << 2);
		GPIO_PortToggle(GPIO, 3, 1u << 15);
		GPIO_PortToggle(GPIO, 3, 1u << 16);
		GPIO_PortToggle(GPIO, 3, 1u << 20);
		GPIO_PortToggle(GPIO, 3, 1u << 21);
		GPIO_PortToggle(GPIO, 3, 1u << 23);
		GPIO_PortToggle(GPIO, 4, 1u << 19);
		GPIO_PortToggle(GPIO, 4, 1u << 22);
		GPIO_PortToggle(GPIO, 4, 1u << 23);
		GPIO_PortToggle(GPIO, 1, 1u << 18);
		GPIO_PortToggle(GPIO, 2, 1u << 12);
		GPIO_PortToggle(GPIO, 2, 1u << 1);
		GPIO_PortToggle(GPIO, 3, 1u << 2);
		GPIO_PortToggle(GPIO, 3, 1u << 14);
		GPIO_PortToggle(GPIO, 2, 1u << 5);
		GPIO_PortToggle(GPIO, 2, 1u << 27);


		vTaskDelay(500);
	}
}
void vKeyTask(void *pvParameters)
{
	int a = 0;
//	int b = 0;
//	int c = 0;
	
	for(;;)
	{
//		b = GPIO_PinRead(GPIO,4,24);
//		c = GPIO_PinRead(GPIO,4,25);
//		d = GPIO_PinRead(GPIO,4,26);
//		a = GPIO_PinRead(GPIO,3,22);
		
//		PRINTF("a=%d,b=%d,c=%d,d=%d\r\n",a,b,c,d);
		if((a = keyScan()) != 0)
			PRINTF("key=%d\r\n",a);
		vTaskDelay(20);
	}
}

void GPIO_Config(void)
{
	//LED
	/* Define the init structure for the output LED pin*/
	gpio_pin_config_t led0_config = {
			kGPIO_DigitalOutput,
			0,
	};
	gpio_pin_config_t led1_config = {
			kGPIO_DigitalOutput,
			1,
	};
    gpio_pin_config_t keyInput_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
		/* Init output LED GPIO. */
	GPIO_PortInit(GPIO, 0);
	GPIO_PinInit(GPIO, 0, 25, &led0_config);	//key_L2
	GPIO_PinInit(GPIO, 0, 14, &led1_config);	//key_L2
	
	GPIO_PortInit(GPIO, 1);
	GPIO_PinInit(GPIO, 1, 18, &led1_config);	//sounder led
	GPIO_PinInit(GPIO, 1, 3, &led0_config);	//key_L4
	
	GPIO_PortInit(GPIO, 2);
	GPIO_PinInit(GPIO, 2, 2, &led1_config);	//zhu dian led
	GPIO_PinInit(GPIO, 2, 12, &led1_config);//communication led
	GPIO_PinInit(GPIO, 2, 1, &led1_config);	//sent out led
	GPIO_PinInit(GPIO, 2, 5, &led0_config);	//can1 indication led
	GPIO_PinInit(GPIO, 2, 27, &led1_config);//buzzer***select
	GPIO_PinInit(GPIO, 2, 26, &led0_config);//key_L6
	
	GPIO_PortInit(GPIO, 3);
	GPIO_PinInit(GPIO, 3, 23, &led1_config);//bei dian led
	GPIO_PinInit(GPIO, 3, 15, &led1_config);//sound fault led
	GPIO_PinInit(GPIO, 3, 16, &led1_config);//commond fault led
	GPIO_PinInit(GPIO, 3, 20, &led1_config);//silence led
	GPIO_PinInit(GPIO, 3, 21, &led1_config);//bei yong led
	GPIO_PinInit(GPIO, 3, 2, &led0_config);	//can0 indication led
	GPIO_PinInit(GPIO, 3, 14, &led0_config);//485 indication led
	GPIO_PinInit(GPIO, 3, 13, &led0_config);///key_L1
	GPIO_PinInit(GPIO, 3, 30, &led0_config);///key_L3
	GPIO_PinInit(GPIO, 3, 31, &led0_config);//key_L5
	GPIO_PinInit(GPIO, 3, 22, &keyInput_config);//key_C1
	
	GPIO_PortInit(GPIO, 4);
	GPIO_PinInit(GPIO, 4, 19, &led1_config);//Fire LED
	GPIO_PinInit(GPIO, 4, 22, &led1_config);//ping bi led
	GPIO_PinInit(GPIO, 4, 23, &led1_config);//heart led----
	GPIO_PinInit(GPIO, 4, 24, &keyInput_config);//key_C2
	GPIO_PinInit(GPIO, 4, 25, &keyInput_config);//key_C3
	GPIO_PinInit(GPIO, 4, 26, &keyInput_config);//key_C4
	GPIO_PinInit(GPIO, 4, 6, &led1_config);//back light***select
	
	GPIO_PortInit(GPIO, 5);
	GPIO_PinInit(GPIO, 5, 5, &keyInput_config);//Fire LED
	
	keyClearValueV();
}
uint8_t keyGetValueH(void)
{
	uint8_t value =0;
	value = (GPIO_PinRead(GPIO,4,24)| (GPIO_PinRead(GPIO,4,25)<<1)| (GPIO_PinRead(GPIO,4,26)<<2) | (GPIO_PinRead(GPIO,3,22)<<3));
	return value;
}

void keySetValueV(uint8_t value)
{
	if(value & 1<<0)
		GPIO_PortSet(GPIO, 3, 1u << 13);
	else
		GPIO_PortClear(GPIO, 3, 1u << 13);
	
	if(value & 1<<1)
		GPIO_PortSet(GPIO, 0, 1u << 25);
	else
		GPIO_PortClear(GPIO, 0, 1u << 25);
	
	if(value & 1<<2)
		GPIO_PortSet(GPIO, 3, 1u << 30);
	else
		GPIO_PortClear(GPIO, 3, 1u << 30);
	
	if(value & 1<<3)
		GPIO_PortSet(GPIO, 1, 1u << 3);
	else
		GPIO_PortClear(GPIO, 1, 1u << 3);
	
	if(value & 1<<4)
		GPIO_PortSet(GPIO, 3, 1u << 31);
	else
		GPIO_PortClear(GPIO, 3, 1u << 31);
	
	if(value & 1<<5)
		GPIO_PortSet(GPIO, 2, 1u << 26);
	else
		GPIO_PortClear(GPIO, 2, 1u << 26);
	
}
void keyClearValueV(void)
{
	GPIO_PortClear(GPIO, 3, 1u << 13);
	GPIO_PortClear(GPIO, 0, 1u << 25);
	GPIO_PortClear(GPIO, 3, 1u << 30);
	GPIO_PortClear(GPIO, 1, 1u << 3);
	GPIO_PortClear(GPIO, 3, 1u << 31);
	GPIO_PortClear(GPIO, 2, 1u << 26);
}


void board_key_init(void) 
{

	
	
}

void board_led_init(void)
{
	gpio_pin_config_t led1_config = {
			kGPIO_DigitalOutput,
			1,
	};
		GPIO_PortSet(GPIO, 0, 1u << 14);
		GPIO_PinWrite(GPIO, 0, 14,1);
		GPIO_PinInit(GPIO, 0, 14, &led1_config);	//key_L2
		GPIO_PortSet(GPIO, 0, 1u << 14);
		GPIO_PinWrite(GPIO, 0, 14,1);
}

int keyGetValue(void)
{
	uint8_t value = 0,Horizontal = 0,Vertical = 0;
	uint8_t setvalue;
	uint8_t i;

	value = keyGetValueH();
	if(value != 0x0F)//be pressed
	{
			
		switch(value)
		{
			case 0x0e: Vertical = 0;break;
			case 0x0d: Vertical = 1;break;
			case 0x0b: Vertical = 2;break;
			case 0x07: Vertical = 3;break;
		}
		for(i = 0; i<6; i++)
		{
			setvalue = 0x3F&(~(1<<i));
			keySetValueV(setvalue);
			
			value = keyGetValueH();
			if(value != 0x0F)
			{
				switch(setvalue)
				{
					case 0x3e: Horizontal = 1;break;
					case 0x3d: Horizontal = 2;break;
					case 0x3b: Horizontal = 3;break;
					case 0x37: Horizontal = 4;break;
					case 0x2F: Horizontal = 5;break;
					case 0x1F: Horizontal = 6;break;
				
				}
//			PRINTF("Vertical=%d,Horizontal=%d\r\n",Vertical,Horizontal);
				break;

			}
		}
		keyClearValueV();
	}
	return (Vertical*6 + Horizontal);
}

int keyScan(void)
{
	static uint8_t KeyST=0,KeyTimeCnt=0;
	static uint8_t value = 0;
	if(!KeyST)//check key
	{
		if(!KeyTimeCnt)
		{
			if(keyGetValue() != 0)//be pressed
			{
				KeyTimeCnt++;
			}
		}
		else// sure pressed
		{
			if((value = keyGetValue()) != 0)
			{
				if(++KeyTimeCnt>=KEY_TIME_MAX)
				{
					KeyTimeCnt=0;
					KeyST++;
					
				}
			}
		}
				
	}
	else	//unpressed check
	{
			if(keyGetValue() == 0)
			{
				if(++KeyTimeCnt>=KEY_TIME_MAX)//sure unpressed
				{//有键按动了
					KeyTimeCnt=0;KeyST=0;
					return value;
				}
			}
			else
			{
				KeyTimeCnt=0;
			}
		
	}
	return 0;
}

//int keyScan(void)
//{
//    static u8 keyST = 0,keyTimeCnt = 0,keyNum = 0;
//	u8 row,col;
//    static KeyValueTypeDef KeyValue;

//    if(!keyST)
//    {
//        if(!keyTimeCnt)//检测有按键按下
//        {
//			for(row=0;((*HX[row])&0x1)&&row<ROWSIZE;row++);

//            if(row==ROWSIZE)
//            {
//                return 0;
//            }
//            for(col=0;col<COLSIZE;col++) (*LX[col]) = 1;
//            for(col=0;col<COLSIZE;col++)
//            {
//                (*LX[col]) = 0;
//                if(!(*HX[row])) {break;}
//                (*LX[col]) = 1;
//            }
//            if(col<COLSIZE)
//            {
//                keyTimeCnt++;
//                KeyValue.keyVal=(row<<4)|col;//检测期间行号占高四位，列号占低4位

//            }
//            else
//            {
//                for(col=0;col<COLSIZE;col++) (*LX[col]) = 0; return  0;
////                LPC_GPIO1->FIOCLR=0x3C400;goto SYSTICKHANDLER1;
//            }
//            
//        }
//        else//确认按下
//        {
//            if(!(*HX[KeyValue.keyValH]))
//                {
//                    if(++keyTimeCnt>=6)
//                        {
//                            keyTimeCnt=0;
//                            keyST++;
//                        }
//#if  KEY_SOUND == 1
//    if(Host.KeySound)   BEEP = 1;  
//#endif
//                }
//            else
//                {
//                    keyTimeCnt=0;

//#if  KEY_SOUND == 1
//    if(Host.KeySound)   BEEP = 0;  
//#endif
//                    
//                }
//        }
//        
//    }
//    else//按键松开
//    {
//        if(*HX[KeyValue.keyValH])
//        {

//            if(++keyTimeCnt>=6)
//            {//有键按动了
//                keyTimeCnt=0;keyST=0;
//                for(col=0;col<COLSIZE;col++) (*LX[col]) = 0;
//                //确实有键按下并松开了，生成键值五进制
//                keyNum=(KeyValue.keyValH)*ROWSIZE+(KeyValue.keyValL);
////                PRINT_Log("keyNum: %d\r\n", keyNum);

//#if  KEY_SOUND == 1
//    if(Host.KeySound)   BEEP = 0;  
//#endif 
//                
//                return keyNum+1;
//            }
//        }
//        else
//            keyTimeCnt=0;
//   
//    }
//    return 0;
//}
