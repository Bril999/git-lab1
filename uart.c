#include "uart.h"
#include <stdio.h>

static uint32_t uart_baudrate = 0;

void UART_Init(uint32_t baudrate)
{
    uart_baudrate = baudrate;
    printf("UART initialized: %u baud\n", (unsigned)uart_baudrate);
}

void UART_SendByte(uint8_t data)
{
    putchar(data);
}

void UART_SendString(const char *str)
{
    while (*str)
    {
        UART_SendByte((uint8_t)*str++);
    }
}
