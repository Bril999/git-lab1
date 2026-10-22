#include "uart.h"
#include <stdio.h>

static uint32_t uart_baudrate = 0;

void UART_Init(uint32_t baudrate)
{
    uart_baudrate = baudrate;
    printf("[DEV1] UART configured: %u baud\n", (unsigned)uart_baudrate);
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

uint8_t UART_ReceiveByte(void)
{
    uint8_t data = 'R';
    printf("UART received: %c\n", data);
    return data;
}

void UART_SendBuffer(const uint8_t *buffer, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        UART_SendByte(buffer[i]);
    }
}

void UART_SendNumber(int number)
{
    printf("%d", number);
}

void UART_SendLine(const char *str)
{
    UART_SendString(str);
    UART_SendByte('\n');
}

void UART_SendHex(uint8_t data)
{
    printf("0x%02X", (unsigned int)data);
}