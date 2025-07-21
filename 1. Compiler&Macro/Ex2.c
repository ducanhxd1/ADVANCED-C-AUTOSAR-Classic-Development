#include <stdio.h>

// Định nghĩa các loại MCU
#define STM32    1
#define ESP32    2
#define ATMEGA   3

// Chọn loại MCU
#define MCU STM32

// Cấu hình GPIO phù hợp với MCU
#if MCU == STM32
    void gpio()
    {
        printf("GPIO initialized for STM32\n");
    }

#elif MCU == ESP32
    void gpio()
    {
        printf("GPIO initialized for ESP32\n");
    }

#else MCU == ATMEGA

    void gpio()
    {
        printf("GPIO initialized for ATmega\n");
    }

#endif

int main()
{
    gpio_init();
    return 0;
}