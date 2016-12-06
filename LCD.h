/*
 * LCD.h
 *
 * Created: 10/29/16 12:11:04 PM
 *  Author: ianmcdoom
 */ 


#ifndef LCD_H_
#define LCD_H_

void lcd_init()
{
	DDRB |= 0xCF;					//Change DDRA --> DDRB and PORTD --> PORTB if LCD attached to port B and so forth
	lcd_command(0x33);				//Initialize LCD Driver
	lcd_command(0x32);				//Four bit mode
	lcd_command(0x2C);				//2 Line Mode
	lcd_command(0x0C);				//Display On, Cursor Off, Blink Off  Change to 0x0F if cursor is desired
	lcd_command(0x01);				//Clear Screen, Cursor Home
}

void lcd_command(char cmd)
{
	char temp = cmd;
	PORTB=0;

	_delay_ms(5);

	cmd = ( (cmd & 0xF0) >> 4) | 0x80;		//Write Upper Nibble (RS=0) E --> 1
	PORTB = cmd;
	_delay_ms(5);
	cmd ^= 0x80;							//E --> 0
	PORTB = cmd;

	_delay_ms(5);

	cmd = temp;
	cmd = ( (cmd & 0x0F) ) | 0x80;			//Write Lower Nibble (RS=0) E --> 1
	PORTB = cmd;
	_delay_ms(5);
	cmd ^= 0x80;							//E --> 0
	PORTB = cmd;

	_delay_ms(7);
}

void lcd_char(char data)
{
	char temp = data;
	PORTB = 0x40;

	_delay_ms(5);

	data = ( (data & 0xF0) >> 4) | 0xC0;	//Write Upper Nibble (RS=1) E --> 1
	PORTB = data;
	_delay_ms(5);
	data ^= 0x80;							//  E --> 0
	PORTB = data;

	_delay_ms(5);
	data = temp;

	data = ( (data & 0x0F) ) | 0xC0;		//Write Lower Nibble (RS=1) E --> 1
	PORTB = data;
	_delay_ms(5);
	data ^= 0x80;							//E --> 0
	PORTB = data;

	_delay_ms(7);
}

void lcd_string(char *s){
	for(int b=0; s[b] !='\0'; b++){					//check for null character if not output character and then increment cursor
		lcd_char(s[b]);
	}

}

void lcd_output(char *s, char *t){
	lcd_init();
	
	lcd_string(s);
	lcd_command(0xC0);
	lcd_string(t);
	
	_delay_ms(1000);	
}


#endif /* LCD_H_ */