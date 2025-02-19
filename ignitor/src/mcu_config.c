#include <mcu_config.h>
/*
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

volatile uint32_t counter_ms = 0;  // Contador que incrementa a cada 1ms
volatile uint16_t counter_sec = 0xFFFF;  // Contador que decrementa a cada 1s
*/
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

}

void GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SINAL_RELE_Pin|SINAL_BUZZER_Pin|DISPLAY_DIO_Pin|DISPLAY_CLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ATIVA_SISTEMA_Pin GATILHO_Pin */
  GPIO_InitStruct.Pin = ATIVA_SISTEMA_Pin|GATILHO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BOTAO_DECREMENTA_Pin BOTAO_INCREMENTA_Pin */
  GPIO_InitStruct.Pin = BOTAO_DECREMENTA_Pin|BOTAO_INCREMENTA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : SINAL_RELE_Pin SINAL_BUZZER_Pin DISPLAY_DIO_Pin DISPLAY_CLK_Pin */
  GPIO_InitStruct.Pin = SINAL_RELE_Pin|SINAL_BUZZER_Pin|DISPLAY_DIO_Pin|DISPLAY_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/*
void MX_TIM2_Init(void) {
    __HAL_RCC_TIM2_CLK_ENABLE();

    htim2.Instance = TIM2;
    htim2.Init.Prescaler = (SystemCoreClock / 1000000) - 1; // 1us
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 999; // Conta 1000us (1 ms)
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_RegisterCallback(&htim2, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM2_Callback);
    HAL_TIM_Base_Init(&htim2);
    HAL_TIM_Base_Start_IT(&htim2);
}

void MX_TIM3_Init(void) {
    __HAL_RCC_TIM3_CLK_ENABLE();

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = (SystemCoreClock / 1000) - 1; // Para contar em ms
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 999; // Conta 1000ms (1 segundo)
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_RegisterCallback(&htim3, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM3_Callback);
    HAL_TIM_Base_Init(&htim3);
    HAL_TIM_Base_Start_IT(&htim3);
}

void TIM2_Callback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        // Incrementa e reseta se ultrapassar 32 bits
        counter_ms++;
        if (counter_ms > 0xFFFFFFFF) {
            counter_ms = 0;
        }
    }
}

void TIM3_Callback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        // Decrementa até 0 e reseta para valor máximo
        if (counter_sec > 0) {
            counter_sec--;
        } else {
            counter_sec = 0xFFFF;  // Reinicia no valor máximo
        }
    }
}

uint32_t milliseconds_elapsed(void) 
{
    uint32_t ms;
    __disable_irq();  // Desativa interrupções para evitar leitura inconsistente
    ms = counter_ms;  // Lê o valor atual
    __enable_irq();   // Reativa interrupções
    return ms;
}

uint16_t seconds_elapsed(void) 
{
    uint16_t sec;
    __disable_irq();  // Desativa interrupções para evitar leitura inconsistente
    sec = counter_sec;  // Lê o valor atual
    __enable_irq();   // Reativa interrupções
    return sec;
}
*/