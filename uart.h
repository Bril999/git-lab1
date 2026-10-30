
#ifndef UART_H
#define UART_H

#include <stdint.h>

/**
 * @file uart.h
 * @brief Software UART simulation interface.
 *
 * Provides UART initialization, data transmission,
 * diagnostics and hexadecimal output utilities.
 */

/**
 * @brief Initializes UART with the specified baudrate.
 * @param baudrate Communication speed in baud.
 */
void UART_Init(uint32_t baudrate);

/**
 * @brief Sends a single byte.
 * @param data Byte to transmit.
 */
void UART_SendByte(uint8_t data);

/**
 * @brief Sends a null-terminated string.
 * @param str Pointer to the string.
 */
void UART_SendString(const char *str);

/**
 * @brief Simulates receiving one UART byte.
 * @return Received byte.
 */
uint8_t UART_ReceiveByte(void);

/**
 * @brief Sends a buffer of bytes.
 * @param buffer Pointer to the data buffer.
 * @param size Number of bytes.
 */
void UART_SendBuffer(const uint8_t *buffer, uint32_t size);

/**
 * @brief Prints a decimal integer.
 * @param number Integer value.
 */
void UART_SendNumber(int number);

/**
 * @brief Sends a string followed by a newline.
 * @param str Pointer to the string.
 */
void UART_SendLine(const char *str);

/**
 * @brief Prints a byte in hexadecimal format.
 * @param data Byte value.
 */
void UART_SendHex(uint8_t data);

/** @brief Sends a predefined test message. */
void UART_SendTestMessage(void);

/** @brief Sends a separator line. */
void UART_SendSeparator(void);

/** @brief Sends an OK status message. */
void UART_SendOK(void);

/**
 * @brief Checks whether UART is initialized.
 * @return 1 if initialized, otherwise 0.
 */
int UART_IsInitialized(void);

/**
 * @brief Returns the configured UART baudrate.
 * @return Current baudrate.
 */
uint32_t UART_GetBaudrate(void);

/**
 * @brief Prints a buffer as hexadecimal bytes.
 * @param buffer Pointer to the byte buffer.
 * @param size Number of bytes.
 */
void UART_SendHexBuffer(const uint8_t *buffer, uint32_t size);

#endif
