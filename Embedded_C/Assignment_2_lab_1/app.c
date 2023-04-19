#include <uart.h>
unsigned char string[100]="learn-in-depth:SALAH";
unsigned const char string2[100]="learn-in-depth:SALAH";
int main()
{
uart_send_string(string);
return 0;
}