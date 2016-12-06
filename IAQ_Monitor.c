/*
 * Sensor_Test.c
 *
 * Created: 9/22/16 4:26:15 PM
 *  Author: ianmcdoom
 */ 


#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <compat/twi.h>
#include <avr/interrupt.h>
#include <math.h>

#include "LCD.h"
#include "ADC.h"
#include "I2C.h"
#include "UART.h"
#include "SPI.h"

int temp_enable = 1;
int hum_enable = 1;
int CO_enable = 1;
int I2C_enable = 1;

int temp_display = 0;
int hum_display = 0;
int CO_display = 0;
int CO2_display = 0;
int VOC_display = 0;

int sensor_warm = 0;

unsigned char sensor_name = 0;
unsigned char check_value;
unsigned int skip_value;

int main(void)
{
	lcd_init();
	i2c_init();
	uart_init();
	spi_init();
	DDRC |= (1<<PINC7);
	
	sei();
	
	_delay_ms(100);
	i2c_data();
	_delay_ms(100);
	
	lcd_output("Hello","Please Wait...");
	_delay_ms(100);
	
    while(1)
    {
		while (stat_value == 16){
			lcd_output("Sensors warming", "Please Wait...");
			_delay_ms(3000);
			i2c_data();
			_delay_ms(50);
		}
		
		function_temperature();
		function_humidity();
		function_CO();
		function_CO2();
		function_VOC();
		sensor_health();
		//lcd_output("Status",str_1);
    }
}

void sensor_health(void){
	if (temp_enable == 0 && hum_enable == 0 && CO_enable == 0 && I2C_enable == 0){
		lcd_output("Air Quality:", "Sensors Off");
	}
	else if ( trueRH <= 60.0 && trueRH >= 30.0 && MICS5524_value <= 5.0 && prediction_value <= 1000.0 && tvoc_value <= 500.0){
		lcd_output("Air Quality:", "Good");
		PORTC |= (1 << PINC7);
	}
	else if (MICS5524_value < 5.0 && prediction_value < 1500.0 && tvoc_value < 1000.0){
		lcd_output("Air Quality:", "OK");
	}
	else if (trueRH > 60.0 || MICS5524_value > 5.0 || prediction_value > 1500.0 || tvoc_value > 1000.0){
		lcd_output("Air Quality:", "Poor");
		PORTC &= ~(1 << PINC7);
		
		for (int i=0; i < 5; i++){
			send_wave();
		}
	}
	else{
		lcd_string("Error");
	}
}
void function_temperature(void){
	if (temp_enable == 1) {
		read_TMP36();
		
		if (temp_display == 1){
			lcd_output(str_temp, "Fahrenheit");
			_delay_ms(1000);
		}
		
		uart_transmit_string("Temp:");
		_delay_ms(10);
		uart_transmit_string(str_temp);
		uart_transmit(13);
		_delay_ms(1000);
	}
	
	_delay_ms(3000);
}

void function_humidity(void){
	if (hum_enable == 1){
		read_HIH4030();
		
		if (hum_display == 1){
			lcd_output(str_humidity, "RH (%)");
			_delay_ms(1000);
		}
		
		uart_transmit_string("Hum:");
		_delay_ms(10);
		uart_transmit_string(str_humidity);
		uart_transmit(13);
		_delay_ms(1000);
	}
	_delay_ms(3000);
}

void function_CO(void){
	if (CO_enable == 1){
		read_MICS5524();
	
		if (CO_display == 1){
			lcd_output(str_CO, "CO (PPM)");
			_delay_ms(1000);
		}

		uart_transmit_string("CO:");
		_delay_ms(10);
		uart_transmit_string(str_CO);
		uart_transmit(13);
		_delay_ms(1000);
	}
	_delay_ms(3000);
}

void function_CO2(void){
	if (I2C_enable == 1){
		i2c_data();
		
		if (CO2_display == 1){
			lcd_output(str, "CO2 (PPM)");
			_delay_ms(1000);
		}
		
		uart_transmit_string("CO2:");
		_delay_ms(10);
		uart_transmit_string(str);
		uart_transmit(13);
		_delay_ms(1000);
	}
	_delay_ms(3000);
}

void function_VOC(void){
	if (I2C_enable == 1){
		
		if (VOC_display == 1){
			lcd_output(str_4, "VOC (PPB)");
			_delay_ms(1000);
		}
			
		uart_transmit_string("VOC:");
		_delay_ms(10);
		uart_transmit_string(str_4);
		uart_transmit(13);
		_delay_ms(1000);
	}
	_delay_ms(3000);
}

ISR(USART0_RX_vect){
unsigned char c = UDR0;

if (c == '1'){
	temp_enable = 0;
	lcd_output("Temperature", "Disabled!");
	_delay_ms(1000);
}
else if (c == '2'){
	temp_enable = 1;
}
else if (c == '3'){
	hum_enable = 0;	
	lcd_output("Humidity", "Disabled!");
	_delay_ms(1000);
}
else if (c == '4'){
	hum_enable = 1;
}
else if (c == '5'){
	CO_enable = 0;
	lcd_output("CO", "Disabled!");
	_delay_ms(1000);
}
else if (c == '6'){
	CO_enable = 1;
}
else if (c == '7'){
	I2C_enable = 0;
	lcd_output("CO2/VOC", "Disabled!");
	_delay_ms(1000);
}
else if (c == '8'){
	I2C_enable = 1;
}
/////////////////////////////
else if (c == 'a'){
	temp_display = 0;
}
else if (c == 'b'){
	temp_display = 1;
}
else if (c == 'c'){
	hum_display = 0;
}
else if (c == 'd'){
	hum_display = 1;
}
else if (c == 'e'){
	CO_display = 0;
}
else if (c == 'f'){
	CO_display = 1;
}
else if (c == 'g'){
	CO2_display = 0;
}
else if (c == 'h'){
	CO2_display = 1;
}
else if (c == 'i'){
	VOC_display = 0;
}
else if (c == 'j'){
	VOC_display = 1;
}
}


//for (int i=0; i < 20; i++){
//send_wave();
//}