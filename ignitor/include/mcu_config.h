#ifndef MCU_CONFIG_H
#define	MCU_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <stm32f103x6.h>
#include <stm32f1xx.h>
#include <stm32f1xx_hal.h>
#include <stm32f1xx_hal_gpio.h>

#define ATIVA_SISTEMA_Pin GPIO_PIN_12
#define ATIVA_SISTEMA_GPIO_Port GPIOB
#define GATILHO_Pin GPIO_PIN_13
#define GATILHO_GPIO_Port GPIOB
#define BOTAO_DECREMENTA_Pin GPIO_PIN_14
#define BOTAO_DECREMENTA_GPIO_Port GPIOB
#define BOTAO_INCREMENTA_Pin GPIO_PIN_15
#define BOTAO_INCREMENTA_GPIO_Port GPIOB
#define SINAL_RELE_Pin GPIO_PIN_3
#define SINAL_RELE_GPIO_Port GPIOB
#define SINAL_BUZZER_Pin GPIO_PIN_4
#define SINAL_BUZZER_GPIO_Port GPIOB
#define DISPLAY_DIO_Pin GPIO_PIN_8
#define DISPLAY_DIO_GPIO_Port GPIOB
#define DISPLAY_CLK_Pin GPIO_PIN_9
#define DISPLAY_CLK_GPIO_Port GPIOB
#define DISPLAY_DIO PB8
#define DISPLAY_CLK PB9

void SystemClock_Config(void);
void GPIO_Init(void);

#ifdef __cplusplus
}
#endif

#endif