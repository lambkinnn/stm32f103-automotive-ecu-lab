#include "stm32f1xx.h"

int main(void)
{
    // Blue Pill onboard LED: PC13, active low.
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    (void)RCC->APB2ENR;
    GPIOC->BSRR = 1U << 13;
    GPIOC->CRH = (GPIOC->CRH & ~(0xFU << 20)) | (0x2U << 20);

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 2U);

    while (1) {
        __WFI();
    }
}

void SysTick_Handler(void)
{
    GPIOC->ODR ^= 1U << 13;
}
