#ifndef UTILS_H
#define	UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Arduino.h>
#include <mcu_config.h>
#include <stdbool.h>
#include <stdint.h>

#define DEBOUNCE_DELAY 30

bool debounce_falling_edge(GPIO_TypeDef* port, uint16_t pin); 
bool debounce_rising_edge(GPIO_TypeDef* port, uint16_t pin); 
//void delay_ms(uint32_t delay);

#ifdef __cplusplus
}
#endif

#endif