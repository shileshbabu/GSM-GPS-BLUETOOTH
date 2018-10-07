/* this code is only for sending SMS to a predefined number
 * send_sms.c
 *
 *  Created on: Apr 24, 2014
 *      Author: shilesh
 */
#include<avr/io.h>
#include<uart_lib.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{
      set_uartbaud(9600);
      while(1){
            sendstring_uart("AT+CMGF=1\r\n");
                        _delay_ms(2000);
                  sendstring_uart("AT+CMGS=\"9023454253\"\r\n");
                        _delay_ms(500);
                  //sendstring_uart(“kumar”);
                  _delay_ms(500);
                  sendchar_uart(0x1A);
                  _delay_ms(3000);
                  _delay_ms(3000);
                  _delay_ms(3000);
                  _delay_ms(3000);
      }
 
}
#include<uart_lib.h>
#include<avr/io.h>
#include<util/delay.h>
#define FOSC 4000000
void set_uartbaud(int BAUD)
{
      UBRRH = (unsigned char)((FOSC/16/BAUD-1)>>8);
      UBRRL = (unsigned char)(FOSC/16/BAUD-1);
      UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
      UCSRB|=(1<<RXEN)|(1<<TXEN);
}
void enable_uart_txcint()
{
      UCSRB|=(1<<TXCIE);
}
 
void enable_uart_rxcint()
{
      UCSRB|=(1<<RXCIE);
}
 
void enable_uart_udreint()
{
      UCSRB|=(1<<UDRIE);
}
 
void sendchar_uart(char data)
{
      int temp;
      temp=UCSRA&(1<<UDRE);
      temp=temp>>UDRE;
      while(!temp)
      {
 
      }
      UDR=data;
}
 
char getchar_uart()
{
      // Wait until a byte has been received
 
      while((UCSRA&(1<<RXC)) == 0);
 
      // Return received data
 
      return UDR;
 
}
 
void sendstring_uart(char v[])
{
      int i;
      for(i=0;i<strlen(v);i++)
      {
            sendchar_uart(v[i]);
            _delay_ms(10);
      }













