#include <avr/io.h>
#include <util/delay.h>

//#define F_CPU 8000000UL

unsigned char i1;											//set up register i1
unsigned char i2;											//set up register i2

int main(void)												//starts main program
{
    DDRA = 0b11111111;										//port A all outputs
	DDRB = 0b00000000;										//port B all inputs
	PORTB = 0b11111111;										//enable pull up resistors to port B
	
    while (1)												//starts main loop
    {
		i2 = 0b00000001;									//set up initial value to i2
		PORTA = 0b11111110;									//set up initial value to PORTA
		_delay_ms(100);										//delay 100ms
		if (bit_is_set(PINB,0))								//if bit 0 of PORTB is 1 (switch 1 not pressed) execute loop
		{
			for (i1=0; i1<8; i1++)							//register i1 counts from 0 to 7 in order to execute loop 8 times
			{
				i2=i2<<1;									//i2 shift left
				PORTA =~i2;									//PORTA not i2
				_delay_ms(100);								//delay 100ms
			}
		}
			
		while ((PINB == 0b11111100) || (PINB == 0b11111101) || (PINB == 0b11111011) || (PINB == 0b11110111))	//switch 1-4 loop
		{
			PORTA = 0b01111110;								//set up initial value to PORTA
			_delay_ms(1);									//delay 100ms
			while (PINB == 0b11111100);						//switch 1 & 2 pressed -> stay in this loop
			
			while (PINB == 0b11111101)						//switch 2 pressed
				PORTA = (3<<PORTA2);						//set up decimal No 3 to PORTA bit2 (00001100)
			
			while (PINB == 0b11111011)						//switch 3 pressed
				PORTA = (PORTA & 0b11110000);				//clear 4 LSB (filter with AND)
							
			while (PINB == 0b11110111)						//switch 4 pressed
				PORTA = (PORTA | 0b11111111);				//set PORTA (filter with OR)
		}		
    }
}
