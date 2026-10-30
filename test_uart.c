
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "uart.h"

static void test_uart_initialization(void)
{
    UART_Init(115200);

    assert(UART_IsInitialized() == 1);
    assert(UART_GetBaudrate() == 115200);

    printf("[PASS] UART initialization\n");
}

static void test_uart_reinitialization(void)
{
    UART_Init(9600);

    assert(UART_GetBaudrate() == 9600);

    printf("[PASS] UART reinitialization\n");
}

static void test_uart_transmission(void)
{
    const uint8_t buffer[] = {'T', 'E', 'S', 'T'};

    UART_SendBuffer(buffer, sizeof(buffer));
    UART_SendString("\n");

    printf("[PASS] UART transmission smoke test\n");
}

static void test_uart_hex_buffer(void)
{
    const uint8_t data[] = {0x55, 0xAA, 0x10};

    UART_SendHexBuffer(data, sizeof(data));

    printf("[PASS] UART hexadecimal buffer transmission\n");
}

int main(void)
{
    test_uart_initialization();
    test_uart_reinitialization();
    test_uart_transmission();
    test_uart_hex_buffer();

    printf("All UART tests passed!\n");

    return 0;
}
