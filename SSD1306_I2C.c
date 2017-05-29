/* !!!!!!!!!!!!! INCOMPLETE - WORK IN PROGRESS !!!!!!!!!!!!! */

/****************************************************************
* SSD1306 BASED OLED MODULE (128 x 64)
* I2C MODE
*
* NOTE: THE OLED CONTROLLER SUPPORTS BOTH I2C AND SPI, BUT THE
* 		MODULES BOUGHT USUALLY HARDWIRE TO SELECT A PARTICULAR
* 		MODE
*
* 		THE ORIGINAL ADAFRUIT ONES USE THE SSD1306 CONTROLLER,
* 		BUT THE CHEAPER ONES BOUGHT FROM ALIEXPRESS N ALL USE
* 		THE CHEAPER SH1306 CONTROLLER, WHICH IS SIMILAR BUT
* 		NOT EXACTLY THE SAME TO THIS ONE !
*
* MAY 26 2017
*
* ANKIT BHATNAGAR
* ANKIT.BHATNAGARINDIA@GMAIL.COM
*
* REFERENCES
* ------------
*   (1) http://robotcantalk.blogspot.in/2015/03/interfacing-arduino-with-ssd1306-driven.html
*   (2)	http://robotcantalk.blogspot.in/2015/03/interfacing-arduino-with-ssd1306-driven_9.html
****************************************************************/

#include "SSD1306_I2C.h"

//LOCAL LIBRARY VARIABLES////////////////////////////////
//DEBUG RELATED
static uint8_t _ssd1306_i2c_debug;

//DEVICE RELATED
static uint8_t _ssd1306_i2c_slave_address;

//REQUIRED FUNCTION POINTERS
//END LOCAL LIBRARY VARIABLES/////////////////////////////

void PUT_FUNCTION_IN_FLASH SSD1306_I2C_SetDebug(uint8_t debug_on)
{
	//SET DEBUG PRINTF ON(1) OR OFF(0)

	_ssd1306_i2c_debug = debug_on;
}

void PUT_FUNCTION_IN_FLASH SSD1306_I2C_SetDeviceAddress(uint8_t address)
{
	//SET THE I2C MODULE SLAVE ADDRESS
	//NOTE THIS IS THE 7 BIT ADDRESS (WITHOUT THE R/W BIT)

	_ssd1306_i2c_slave_address = address;

	if(_ssd1306_i2c_debug)
	{
		debug_printf("SSD1306 : I2C : Address set to %d\n", _ssd1306_i2c_slave_address);
	}

	//INITIALIZE BACKEND I2C
	_ssd1306_i2c_backend_init(_ssd1306_i2c_slave_address);
}

void PUT_FUNCTION_IN_FLASH SSD1306_I2C_Init(void)
{
	//INITIALIZE THE OLED MODULE AS PER THE DEFAULT PARAMETERS

	_ssd1306_i2c_send_start_function();

	_ssd1306_i2c_send_byte_function((_ssd1306_i2c_slave_address << 1));

	//SET TYPE TO COMMAND STREAM
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CONTROL_BYTE_CMD_STREAM);

	/*
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_MUX_RATIO);
	_ssd1306_i2c_send_byte_function(0x3F);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_DISPLAY_OFFSET);
	_ssd1306_i2c_send_byte_function(0x00);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_DISPLAY_START_LINE);
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_SEGMENT_REMAP);
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_COM_SCAN_MODE);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_COM_PIN_MAP);
	_ssd1306_i2c_send_byte_function(0x00);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_CONTRAST);
	_ssd1306_i2c_send_byte_function(0x7F);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_DISPLAY_RAM);
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_DISPLAY_NORMAL);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_DISPLAY_CLK_DIV);
	_ssd1306_i2c_send_byte_function(0x80);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_CHARGE_PUMP);
	_ssd1306_i2c_send_byte_function(0x14);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_DISPLAY_ON);

	//SET PAGE ADDRESSING MODE
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_MEMORY_ADD_MODE);
	_ssd1306_i2c_send_byte_function(0x20);
	*/


	_ssd1306_i2c_send_byte_function(0xAE);
	_ssd1306_i2c_send_byte_function(0x20);
	_ssd1306_i2c_send_byte_function(0x10);
	_ssd1306_i2c_send_byte_function(0xB0);
	_ssd1306_i2c_send_byte_function(0xC8);

	_ssd1306_i2c_send_byte_function(0x00);
	_ssd1306_i2c_send_byte_function(0x10);
	_ssd1306_i2c_send_byte_function(0x40);

	_ssd1306_i2c_send_byte_function(0x81);
	_ssd1306_i2c_send_byte_function(0x7F);
	_ssd1306_i2c_send_byte_function(0xA1);
	_ssd1306_i2c_send_byte_function(0xA6);
	_ssd1306_i2c_send_byte_function(0xA8);
	_ssd1306_i2c_send_byte_function(0x3F);
	_ssd1306_i2c_send_byte_function(0xA4);
	_ssd1306_i2c_send_byte_function(0xD3);
	_ssd1306_i2c_send_byte_function(0x00);
	_ssd1306_i2c_send_byte_function(0xD5);
	_ssd1306_i2c_send_byte_function(0xF0);
	_ssd1306_i2c_send_byte_function(0xD9);
	_ssd1306_i2c_send_byte_function(0x22);
	_ssd1306_i2c_send_byte_function(0xDA);
	_ssd1306_i2c_send_byte_function(0x12);
	_ssd1306_i2c_send_byte_function(0xDB);
	_ssd1306_i2c_send_byte_function(0x20);
	_ssd1306_i2c_send_byte_function(0x8D);
	_ssd1306_i2c_send_byte_function(0x14);
	_ssd1306_i2c_send_byte_function(0xAF);

	_ssd1306_i2c_send_stop_function();

	if(_ssd1306_i2c_debug)
	{
		debug_printf("SSD1306 : I2C : Initialized\n");
	}
}

void PUT_FUNCTION_IN_FLASH SSD1306_I2C_SetContrast(uint8_t contrast_val)
{
	//SET DISPLAY CONTRAST


}

void PUT_FUNCTION_IN_FLASH SSD1306_I2C_ResetAndClearScreen(uint8_t screen_fill)
{
	//RESET THE CURSOR TO DEFAULT LOCATION AND CLEAR THE SCREEN TO EITHER FILLED
	//OR EMPTY DEPENDING ON screen_fill PARAMETER

	_ssd1306_i2c_send_start_function();

	_ssd1306_i2c_send_byte_function((_ssd1306_i2c_slave_address << 1));

	//SET TYPE TO COMMAND STREAM
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CONTROL_BYTE_CMD_STREAM);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_COLUMN_RANGE);
	_ssd1306_i2c_send_byte_function(0x00);
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_OLED_MAX_COLUMN);

	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CMD_SET_PAGE_RANGE);
	_ssd1306_i2c_send_byte_function(0x00);
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_OLED_MAX_PAGE);

	_ssd1306_i2c_send_stop_function();

	uint8_t data = 0;
	uint16_t x = 0;
	uint16_t y = 0;

	if(screen_fill)
	{
		data = 0xFF;
	}

	_ssd1306_i2c_send_start_function();
	_ssd1306_i2c_send_byte_function((_ssd1306_i2c_slave_address << 1));
	_ssd1306_i2c_send_byte_function(SSD1306_I2C_CONTROL_BYTE_DATA_STREAM);
	for(y = 0; y < (SSD1306_I2C_OLED_MAX_PAGE + 1); y++)
	{
		for(x = 0; x < (SSD1306_I2C_OLED_MAX_COLUMN + 1); x ++)
		{
			_ssd1306_i2c_send_byte_function(data);
		}

	}
	_ssd1306_i2c_send_stop_function();

	if(_ssd1306_i2c_debug)
	{
		debug_printf("SSD1306 : I2C : Screen reset + filled = %d\n", screen_fill);
	}
}
