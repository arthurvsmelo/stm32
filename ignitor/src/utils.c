#include <utils.h>

#define HIGH true
#define LOW  false

bool debounce(GPIO_TypeDef* port, uint16_t pin) 
{
    static uint32_t lastPressTime = 0;
    static bool lastButtonState = HIGH;  // HIGH porque a entrada tem pull-up

    bool currentState = HAL_GPIO_ReadPin(port, pin);

    if (currentState == LOW && lastButtonState == HIGH) {
        if (milliseconds_elapsed() - lastPressTime > DEBOUNCE_DELAY) {
            lastPressTime = milliseconds_elapsed();
            lastButtonState = currentState;
            return true;
        }
    }
    
    lastButtonState = currentState;
    return false;
}

void delay_ms(uint32_t delay) 
{
	uint32_t start_time = milliseconds_elapsed();
	while ((milliseconds_elapsed() - start_time) < delay);
	return;
}