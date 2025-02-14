#include <Arduino.h>
#include <mcu_config.h>
#include <utils.h>
#include <TM1637TinyDisplay.h>

volatile uint16_t contador;
volatile uint16_t valor_max;
TM1637TinyDisplay display(DISPLAY_CLK, DISPLAY_DIO);
uint8_t dots = 0b01000000;               /* DISPLAY SÓ TEM DOIS PONTOS NO MEIO */

void setup() 
{
	SystemClock_Config();
	GPIO_Init();
	MX_TIM2_Init();
	MX_TIM3_Init();
	display.begin(true);
	display.setBrightness(4);
	display.setScrolldelay(500);
	display.showString("ASA BrAnCA AErOSPACE", 4, 0, dots);
	delay_ms(300);
	display.showString(" OFF");
	delay_ms(1000);
}

void loop() 
{
	for (contador = 1; contador < 11; contador++)
	{
		display.showNumberDec(contador, 0, false, 4, 0);
		delay_ms(1000);
	}
	display.showString("FirE");
	delay_ms(1000);
	display.showString("ASA BrAnCA AErOSPACE", 4, 0, dots);
	delay_ms(1000);
}