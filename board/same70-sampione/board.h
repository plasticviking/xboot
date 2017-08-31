#ifndef __BOARD_H__
#define __BOARD_H__

#include "samv7.h"

/* options */
//#define CONFIG_WATCHDOG_DISABLE

#define CONFIG_KERNEL_FILENAME		"uImage"
#define CONFIG_DTB_FILENAME		"same70-sampione.dtb"
#define CONFIG_KERNEL_LOAD_ADDRESS	0x70007fc0
#define CONFIG_DTB_LOAD_ADDRESS		0x71000000
#define CONFIG_KERNEL_QSPI_ADDRESS	0x0
#define CONFIG_DTB_QSPI_ADDRESS		0x400000

#define CONFIG_BOOTSEL_PIN_QSPI		0
#define CONFIG_BOOTSEL_PIN_SDCARD	1

/* cpu settings 
 *  12Mhz ext crystal, 600Mhz PLLA, 300MHz HCLK, 150MHz MCK, PRESC = 2, MDIV = 2 
 */
#define CONFIG_CPU_OSCOUNT   			(CKGR_MOR_MOSCXTST(0x8U))
#define CONFIG_CPU_PLLAR     			(CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(49) | CKGR_PLLAR_PLLACOUNT(0x3fU) | CKGR_PLLAR_DIVA(0x1U))
#define CONFIG_CPU_MCKR_MDIV 			(PMC_MCKR_MDIV_PCK_DIV2)
#define CONFIG_CPU_MCKR      			(PMC_MCKR_PRES_CLK_2 | PMC_MCKR_CSS_PLLA_CLK | CONFIG_CPU_MCKR_MDIV)
#define CONFIG_MAIN_OSC				12000000
#define CONFIG_MCK_HZ				150000000
#define CONFIG_CPU_HZ				300000000
#define CONFIG_QSPIFLASH_BAUDRATE		75000000
#define CONFIG_FLASH_WAIT_STATES		7

/* debug options */
#define CONFIG_USART_BASE			AT91C_BASE_USART1
#define CONFIG_USART_ID				ID_USART1
#define CONFIG_USART_BAUDRATE			115200
#define CONFIG_TRACE_LEVEL			TRACE_LEVEL_DEBUG

void board_init(void);
unsigned int board_bootsel_pin_state(void);

#endif