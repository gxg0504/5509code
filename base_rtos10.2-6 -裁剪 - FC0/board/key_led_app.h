#ifndef _KEY_LED_APP_H_
#define _KEY_LED_APP_H_

#define KEY_TIME_MAX 					3
//#define IOCON_PIO_DIGITAL_EN        0x0100u   /*!< Enables digital function */
//#define IOCON_PIO_FUNC0               0x00u   /*!< Selects pin function 0 */
//#define IOCON_PIO_FUNC1               0x01u   /*!< Selects pin function 1 */
//#define IOCON_PIO_FUNC6               0x06u   /*!< Selects pin function 6 */
//#define IOCON_PIO_I2CDRIVE_HIGH     0x0400u   /*!< High drive: 20 mA */
//#define IOCON_PIO_I2CFILTER_EN        0x00u   /*!< I2C 50 ns glitch filter enabled */
//#define IOCON_PIO_I2CSLEW_I2C         0x00u   /*!< I2C mode */
//#define IOCON_PIO_INPFILT_OFF       0x0200u   /*!< Input filter disabled */
//#define IOCON_PIO_INV_DI              0x00u   /*!< Input function is not inverted */
//#define IOCON_PIO_MODE_INACT          0x00u   /*!< No addition pin function */
//#define IOCON_PIO_MODE_PULLUP         0x20u   /*!< Selects pull-up function */
//#define IOCON_PIO_OPENDRAIN_DI        0x00u   /*!< Open drain is disabled */
//#define IOCON_PIO_SLEW_FAST         0x0400u   /*!< Fast mode, slew rate control is disabled */
//#define IOCON_PIO_SLEW_STANDARD       0x00u   /*!< Standard mode, output slew rate control is enabled */


void GPIO_Config(void);
void board_led_init(void);
void board_key_init(void);
int keyScan(void);
void keyClearValueV(void);
void vLedTask(void *pvParameters);
void vKeyTask(void *pvParameters);



#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
