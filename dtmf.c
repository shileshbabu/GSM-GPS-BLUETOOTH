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
