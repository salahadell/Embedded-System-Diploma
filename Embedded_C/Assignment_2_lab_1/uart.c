#include <uart.h>
#define UART0 *((volatile unsigned int*)((unsigned int*)0x101F1000)) 

void uart_send_string(unsigned char* string)
{
while(*string!='\0')
{
UART0=(unsigned int)*string;
string++; 
}


}