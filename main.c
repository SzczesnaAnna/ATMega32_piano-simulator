#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000
//projekt
/*
ISR(INT0_vect)
{
	PORTC &= ~(0xFF);
	PORTB=0xFF;
}
ISR(INT1_vect)
{
	PORTC &= ~(0xFF);
	PORTB=0xFF;
}*/
int main(void)
{ 
	DDRB=0xff;//wyjscie do brzęczyka
	DDRC=0xff;//diody wyjścia
	
	
	PORTC &= ~(0xFF);
	PORTD=0xFF; //właczanie rezystorow podciagajcych
	
	// Mode: CTC
	TCCR0=(1<<WGM01);
	// CLK/64
	TCCR0|=(1<<CS01);
	TCCR0|=(1<<CS00);
	// toggle OC0 on compare match    62500
	TCCR0|=(1<<COM00);
	//OCR0=249 f=8000000/(2*64*250)=2KHz
	
	
	
	//sei(); //właczamy główny bit przwerwań
	while(1)
	{ 
		if(!(PIND&(1<<0)))
		{		
			DDRB =0xFF;
			OCR0=0X1D; //c4
			PORTC &= ~(1<<0);
		}
		if(!(PIND&(1<<1)))
		{		
			DDRB =0xFF;
			OCR0=0x1a; //d4
			PORTC &= ~(1<<0);
		}
		if(!(PIND&(1<<2)))
		{		
			DDRB =0xFF;
			OCR0=0x17; //e4
			PORTC &= ~(1<<0);
		}
		if(!(PIND&(1<<3)))
		{		
			DDRB =0xFF;
			OCR0=0X16;//f4
			PORTC &= ~(1<<0);
		}
		if(!(PIND&(1<<4)))
		{		
			DDRB =0xFF;
			OCR0=0x13; //g4
			PORTC &= ~(1<<0);
		}
		if(!(PIND&(1<5)))
		{		
			DDRB =0xFF;
			OCR0=0x11; //a
			PORTC &= ~(1<<0);
		}
		else
		{
			PORTC=0xFF;
			DDRB &= ~(0xFF);
		}	
		//PORTC |=0xFF;
		//PORTB &= ~(0xFF);
	}
	return 1;
}
	

