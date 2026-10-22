#include "uart.h"

int main(void)
{
    UART_Init(115200);

    UART_SendString("Hello, UART!\n");
    UART_SendByte('A');
    UART_SendByte('\n');

    const uint8_t message[] = {'U', 'A', 'R', 'T', '\n'};
    UART_SendBuffer(message, sizeof(message));

    UART_SendString("Number: ");
    UART_SendNumber(123);
    UART_SendString("\n");
    return 0;
}
