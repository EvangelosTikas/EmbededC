#include <avr/io.h>
#include <util/delay.h>

unsigned char i1;
unsigned char line;
unsigned char data;

void Keyb (void)											//Keyboard rutine
{
	line = 1;
	for (i1 = 0; i1 < 4; i1++)
	{
		PORTA = ~line;
		line = line << 1;
		while (PINA < 0b11101111)
		{
			_delay_ms (5);
			switch (PINA)
			{
				case 0b11101110:							//Button 1 pressed
				data = 1;
				while (PINA == 0b11101110);					//Wait if button is still pressed
				break;

				case 0b11101101:							//Button 4 pressed
				data = 4;
				while (PINA == 0b11101101);					//Wait if button is still pressed
				break;

				case 0b11101011:							//Button 7 pressed
				data = 7;
				while (PINA == 0b11101011);					//Wait if button is still pressed
				break;

				case 0b11100111:							//Button * pressed
				data = 14;
				while (PINA == 0b11100111);					//Wait if button is still pressed
				break;

				case 0b11011110:							//Button 2 pressed
				data = 2;
				while (PINA == 0b11011110);					//Wait if button is still pressed
				break;

				case 0b11011101:							//Button 5 pressed
				data = 5;
				while (PINA == 0b11011101);					//Wait if button is still pressed
				break;

				case 0b11011011:							//Button 8 pressed
				data = 8;
				while (PINA == 0b11011011);					//Wait if button is still pressed
				break;

				case 0b11010111:							//Button 0 pressed
				data = 0;
				while (PINA == 0b11010111);					//Wait if button is still pressed
				break;

				case 0b10111110:							//Button 3 pressed
				data = 3;
				while (PINA == 0b10111110);					//Wait if button is still pressed
				break;

				case 0b10111101:							//Button 6 pressed
				data = 6;
				while (PINA == 0b10111101);					//Wait if button is still pressed
				break;

				case 0b10111011:							//Button 9 pressed
				data = 9;
				while (PINA == 0b10111011);					//Wait if button is still pressed
				break;

				case 0b10110111:							//Button # pressed
				data = 15;
				while (PINA == 0b10110111);					//Wait if button is still pressed
				break;

				case 0b01111110:							//Button A pressed
				data = 10;
				while (PINA == 0b01111110);					//Wait if button is still pressed
				break;

				case 0b01111101:							//Button B pressed
				data = 11;
				while (PINA == 0b01111101);					//Wait if button is still pressed
				break;

				case 0b01111011:							//Button C pressed
				data = 12;
				while (PINA == 0b01111011);					//Wait if button is still pressed
				break;

				case 0b01110111:							//Button D pressed
				data = 13;
				while (PINA == 0b01110111);					//Wait if button is still pressed
				break;
			}
		}
	}
}

int main(void)
{
    DDRA = 0b00001111;										//Port A upper inputs, lower outputs (keyboard)
    PORTA = 0b11111111;										//Enable pull up resistors on inputs, send 1 to outputs (keyboard)
    DDRC = 0b11111111;                                      //Port C outputs (LEDs)
    while (1) 
    {
		Keyb ();											//Check keyboard
		PORTC = ~data;
    }
}
