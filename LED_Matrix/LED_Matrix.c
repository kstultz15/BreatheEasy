/**********
*/
//LED Matrix to blink LED's

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int colPin1 = PINA4;	//Pin 13
int colPin2 = PINB2;	//Pin 3
int colPin3 = PINB3;	//Pin 4
int colPin4 = PINA1;	//Pin 10
int colPin5 = PINB5;	//Pin 6
int colPin6 = PINA2;	//Pin 11
int colPin7 = PINA6;	//Pin 15
int colPin8 = PINA7;	//Pin 16

int rowPin1 = PINA0;	//Pin 9
int rowPin2 = PINA5;	//Pin 14
int rowPin3 = PINB7;	//Pin 8
int rowPin4 = PINA3;	//Pin 12
int rowPin5 = PINB0;	//Pin 1
int rowPin6 = PINB6;	//Pin 7
int rowPin7 = PINB1;	//Pin 2
int rowPin8 = PINB4;	//Pin 5

int main(void)
{

		DDRA = 0xFF;	//Row
		DDRB = 0XFF;	//Column
	
	while (1)
	{
		smiley();
	}
}

void smiley(){
	//ROW1
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);	
    
 //Row High turns LED on
	PORTA |= (1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW2
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA |= (1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW3
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB |= (1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW4
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA |= (1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW5
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB |= (1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW6
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB |= (1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);	

//ROW7
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB |= (1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW8
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB |= (1<<rowPin8);  

    _delay_us(2000);
}

void Neutral(){
	//ROW1
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);	
    
 //Row High turns LED on
	PORTA |= (1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW2
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA |= (1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW3
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB |= (1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW4
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA |= (1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW5
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB |= (1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW6
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB |= (1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);	

//ROW7
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB |= (1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW8
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB |= (1<<rowPin8);  

    _delay_us(2000);
}

void Sad(){
	//ROW1
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);	
    
 //Row High turns LED on
	PORTA |= (1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW2
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA |= (1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW3
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB |= (1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW4
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA |= (1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);
	
//ROW5
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB |= (1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW6
 //Col Low turns LED on
	PORTA &= ~(1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA &= ~(1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB |= (1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);	

//ROW7
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB &= ~(1<<colPin2);
	PORTB |= (1<<colPin3);
	PORTA |= (1<<colPin4);
	PORTB |= (1<<colPin5);
	PORTA |= (1<<colPin6);
	PORTA &= ~(1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB |= (1<<rowPin7);
	PORTB &= ~(1<<rowPin8);  

    _delay_us(2000);

//ROW8
 //Col Low turns LED on
	PORTA |= (1<<colPin1);
	PORTB |= (1<<colPin2);
	PORTB &= ~(1<<colPin3);
	PORTA &= ~(1<<colPin4);
	PORTB &= ~(1<<colPin5);
	PORTA &= ~(1<<colPin6);
	PORTA |= (1<<colPin7);
	PORTA |= (1<<colPin8);
    
 //Row High turns LED on
	PORTA &= ~(1<<rowPin1);
	PORTA &= ~(1<<rowPin2);
	PORTB &= ~(1<<rowPin3);
	PORTA &= ~(1<<rowPin4);
	PORTB &= ~(1<<rowPin5);
	PORTB &= ~(1<<rowPin6);
	PORTB &= ~(1<<rowPin7);
	PORTB |= (1<<rowPin8);  

    _delay_us(2000);
}