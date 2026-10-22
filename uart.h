#ifndef UART_H
#define UART_H

#include <stdint.h>

void UART_Init(uint32_t baudrate);
void UART_SendByte(uint8_t data);
void UART_SendString(const char *str);
uint8_t UART_ReceiveByte(void);
void UART_SendBuffer(const uint8_t *buffer, uint32_t size);
void UART_SendNumber(int number);
void UART_SendLine(const char *str);

#endif
