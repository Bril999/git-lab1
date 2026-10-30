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
    printf("[DEV2] Sending string: ");

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

void UART_SendTestMessage(void)
{
    UART_SendString("Cherry-pick test successful!\n");
}

void UART_SendSeparator(void)
{
    UART_SendString("----------------\n");
}

void UART_SendOK(void)
{
    UART_SendString("UART: OK\n");
}

int UART_IsInitialized(void)
{
    return uart_baudrate != 0;
}

uint32_t UART_GetBaudrate(void)
{
    return uart_baudrate;
}

void UART_SendHexBuffer(const uint8_t *buffer, uint32_t size)
{
    if (buffer == NULL)
    {
        return;
    }

    for (uint32_t i = 0; i < size; i++)
    {
        printf("%02X", (unsigned int)buffer[i]);

        if (i + 1 < size)
        {
            printf(" ");
        }
    }

    printf("\n");
}