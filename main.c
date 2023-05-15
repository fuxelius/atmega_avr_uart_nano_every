/*
 *     test.c
 *
 *          Project:  Test of USART for ATmega4808
 *          Author:   Hans-Henrik Fuxelius   
 *          Date:     2023-05-08           
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"

int main(void) {

    uint16_t c;
    uint8_t j=0;

    while (1) {

        // (1) - Init USART
        usart3_init((uint16_t)BAUD_RATE(9600));

        // (2) - Enable global interrupts
        sei(); 

        // (3) - Send string to USART
        usart3_send_string("\r\n\r\nPEACE BRO!\r\n\r\n", 18);

        // (4) - Use fprintf to write to stream
        fprintf(&USART3_stream, "Hello world!\r\n");

        for(uint8_t i=0; i<5; i++) {
            // (5) - Use formatted fprintf to write to stream
            fprintf(&USART3_stream, "\r\nCounter value is: 0x%02X ", j++);
            _delay_ms(500);

            // (6) - Get USART input by polling ringbuffer
            while(!((c = usart3_read_char()) & USART_NO_DATA)) {

                if (c & USART_PARITY_ERROR) {
                    fprintf(&USART3_stream, "USART PARITY ERROR: ");
                }
                if (c & USART_FRAME_ERROR) {
                    fprintf(&USART3_stream, "USART FRAME ERROR: ");
                }
                if (c & USART_BUFFER_OVERFLOW) {
                    fprintf(&USART3_stream, "USART BUFFER OVERFLOW ERROR: ");
                }

                // (7) - Send single character to USART
                usart3_send_char((char)c);
            }
        }

        // (8) - Check that everything is printed before closing USART
        fprintf(&USART3_stream, "\r\n\r\n<-<->->");

        // (9) - Close USART0
        usart3_close();    

        // (10) - Clear global interrupts
        cli();

    }
}