#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define FOSC 4000000
char uart_data[7]=" ";
unsigned char uart_index=0;
void uart_init(int baud)
{
	UBRRH=(unsigned char)((FOSC/16/baud-1)>>8);
	UBRRL=(unsigned char)(FOSC/16/baud-1);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB|=(1<<RXEN);
}
void enable_uart_rxcint()
{
	UCSRB|=(1<<RXCIE);
}

ISR(USART_RXC_vect)
{
uart_data[uart_index]=UDR;
      if(uart_data[uart_index]=='a')
        {
    	  PORTB=0xaa;
		  _delay_ms(100);
        }
		else
		{
		PORTB=0x55;
		_delay_ms(100);
		}

if(uart_index==2)
	uart_index=0;
else
	uart_index++;
}
int main()
    {
	DDRB=0XFF;
	uart_init(9600);
	enable_uart_rxcint();
	sei();
	while(1)
	      {
               if(uart_data[0]=='a')
                   {
                    PORTB=0xff;
                   }
                else
                   {
                     PORTB=0x88;
                   }
	      }
     }

