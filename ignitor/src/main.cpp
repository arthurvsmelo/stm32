#include <Arduino.h>
#include <mcu_config.h>
#include <utils.h>
#include <TM1637TinyDisplay.h>

volatile uint8_t contador = 0;
TM1637TinyDisplay display(DISPLAY_CLK, DISPLAY_DIO);
uint8_t dots = 0b01000000;               /* DISPLAY SÓ TEM DOIS PONTOS NO MEIO */

void setup() 
{
	SystemClock_Config();
	GPIO_Init();
	display.begin(true);
	display.setBrightness(4);
	display.setScrolldelay(200);
	display.showString("ASA BrAnCA AErOSPACE", 4, 0, dots);
	delay(300);
	display.showString("IdLE");
	delay(1000);
}

void loop() 
{
	if (debounce_rising_edge(BOTAO_INCREMENTA_GPIO_Port, BOTAO_INCREMENTA_Pin))
	{
		if((contador++) > 254)
		{
			contador = 0;
		}
	}
	display.showNumberDec(contador, 0, false, 4, 0);
}