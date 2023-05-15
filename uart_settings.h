/*
 *     uart_settings.h
 *
 *          Project:  UART for ATmega4808
 *          Author:   Hans-Henrik Fuxelius   
 *          Date:     2023-05-08           
 */


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
// DEFINE RING BUFFER SIZE; must be 2, 4, 8, 16, 32, 64 or 128  
#define RBUFFER_SIZE 32  

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
// ENABLE USART UNITS
// #define USART0_ENABLE
// #define USART1_ENABLE
// #define USART2_ENABLE
#define USART3_ENABLE
// #define USART4_ENABLE
// #define USART5_ENABLE

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
// PORTMUX & PINOUT
#ifdef USART0_ENABLE
void usart0_port_init(void);
#endif

#ifdef USART1_ENABLE
void usart1_port_init(void);
#endif

#ifdef USART2_ENABLE
void usart2_port_init(void);
#endif

#ifdef USART3_ENABLE
void usart3_port_init(void);
#endif

#ifdef USART4_ENABLE
void usart4_port_init(void);
#endif

#ifdef USART5_ENABLE
void usart5_port_init(void);
#endif