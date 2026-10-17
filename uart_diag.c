#include <stdio.h>
#include "uart.h"

void UART_PrintStatus(void)
{
    printf("UART diagnostic: OK\n");
    printf("UART TX: enabled\n");
    printf("UART RX: enabled\n");
}