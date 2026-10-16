#include "uart.h"

int main(void)
{
    UART_Init(115200);

    UART_SendString("Hello, UART!\n");
    UART_SendByte('A');
    UART_SendByte('\n');

    return 0;
}
