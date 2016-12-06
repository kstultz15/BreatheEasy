/*
 * UART.h
 *
 * Created: 11/4/16 2:53:47 PM
 *  Author: ianmcdoom
 */ 


#ifndef UART_H_
#define UART_H_

#define BUAD 9600
#define F_CPU 8000000
#define UBBR0 ((F_CPU/16/BUAD)-1) // calc USART baud rate in normal Asyc mode

void uart_init (void){
	//OSCCAL = 0x98;
	OSCCAL = 0xA8;
	UBRR0H = (unsigned char) (UBBR0>>8); // setting the high 8 bits of he USART baud rate
	UBRR0L = (unsigned char)  UBBR0;    // setting lower bit of the USART baud rate
	UCSR0B = (1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // set 8 bit data frame format
}

unsigned char uart_recieve(void){
	while ( !(UCSR0A & (1 << RXC0)) ); //Wait for the RXC to not have 0 (for data to be received)
	
	return UDR0; //return received data from buffer
}

void uart_transmit( unsigned char data )
{
	while (!( UCSR0A & (1<<UDRE0))) ; //  Wait for empty transmit buffer
	
	UDR0 = data; // Put data into buffer, sends the data
	
}

void uart_transmit_string( unsigned char data [] )
{
	int temp_count = 0;
	
	while(data [temp_count] != 0){
		uart_transmit(data[temp_count++]);
	}
	
}


#endif /* UART_H_ */