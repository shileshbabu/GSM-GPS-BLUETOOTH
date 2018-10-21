/*
 * gps1.c
 *
 *  Created on: May 26, 2014
 *      Author: Shilesh
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include "lcd_lib.c"
#include <avr/interrupt.h>
#define FOSC 4000000
char uart_data[70]=" ";
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
if(uart_index==10)uart_index=0;
else uart_index++;
}
int main()
    {
	DDRD=0xf0;;
	LCDinit();
	LCDclr();
	uart_init(9600);
	enable_uart_rxcint();
	sei();
	while(1)
	      {
		LCDGotoXY(0,0);
			LCDdisplay("SHILESH");
			PORTD=0X55;
		LCDdisplay(uart_data);
		_delay_ms(100);
	      }
     }

 #include<avr/io.h>
  #include<util/delay.h>
  void main()
  {
  DDRB=0XFF;
  DDRC=0;
  PORTC=0x00;
       while(1){
                   if(PINC==(2<<0))
			           {
                        PORTB=0b00010100; //forward
			              }
				          else if(PINC==(4<<0))
				           {
                           PORTB=0b00001100;//left
					         }
					        else if(PINC==(6<<0))
					           {
                               PORTB=0b00010010; //right
						        }
                         	   
}
}



