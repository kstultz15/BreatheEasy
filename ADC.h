/*
 * ADC.h
 *
 * Created: 10/29/16 12:03:26 PM
 *  Author: ianmcdoom
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>

float voltage;
float celsius;
float fahrenheit;
float sensorRH;
float trueRH;
float MICS5524_value;

char str_temp[4];
char str_humidity[];
char str_CO[];

void adc_init(void);
void read_HIH4030(void);
void read_MICS5524(void);


void adc_init(void){
	DDRA = 0x00;
	ADCSRA|=(1<<ADEN); //Enables ADC
	//ADCSRA |= (1<<ADPS2)|(1<<ADPS1);
}

void read_TMP36(void){	
//Enable ADC
	adc_init();
	
//Multiplexer Selection Register:
	//Reference Selection - AVCC with external capacitor at AREF pin
	//Analog Channel - ADC0
	ADMUX = 0x40;
	_delay_ms(10);

//Start single conversion
	ADCSRA |=(1<<ADSC);

//Wait for conversion to be complete
	while(!(ADCSRA & (1<<ADIF)));

//Clear ADC interrupt flag
	ADCSRA|=(1<<ADIF);
	
	voltage = (ADC*5.00)/1024.00;
	celsius = 100.0*voltage - 50.0;
	fahrenheit = celsius*(9.0/5.0) + 32.0;
	
	sprintf(str_temp,"%.2f",fahrenheit);
}

void read_HIH4030(void){
//Enable ADC
	adc_init();
	
//Multiplexer Selection Register:
	//Reference Selection - AVCC with external capacitor at AREF pin
	//Analog Channel - ADC1
	ADMUX = 0x41;
	_delay_ms(10);
	
//Start single conversion
	ADCSRA |=(1<<ADSC);
	
//Wait for conversion to be complete
	while(!(ADCSRA & (1<<ADIF)));
	
//Clear ADC interrupt flag
	ADCSRA|=(1<<ADIF);
	
	voltage = (ADC*5.00)/1024.00;
	sensorRH = (161.0 * voltage /5.0) - 25.8;
	trueRH = sensorRH / (1.0546 - 0.0026 * celsius);
	
	sprintf(str_humidity,"%.2f",trueRH);
}

void read_MICS5524(void){
//Enable ADC
	adc_init();

//Multiplexer Selection Register:
	//Reference Selection - AVCC with external capacitor at AREF pin
	//Analog Channel - ADC2
	ADMUX = 0x42;
	_delay_ms(10);

//Start single conversion
	ADCSRA |=(1<<ADSC);

//Wait for conversion to be complete
	while(!(ADCSRA & (1<<ADIF)));

//Clear ADC interrupt flag
	ADCSRA|=(1<<ADIF);
	
	float MICS5524_value = ADC;
	MICS5524_value = MICS5524_value - 75.0;
	
	if (MICS5524_value < 0){
		MICS5524_value = 0;
	}
	
	sprintf(str_CO,"%.1f",MICS5524_value);
}


#endif /* ADC_H_ */