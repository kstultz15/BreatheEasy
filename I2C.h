/*
 * I2C.h
 *
 * Created: 10/29/16 12:33:44 PM
 *  Author: ianmcdoom
 */

#ifndef I2C_H_
#define I2C_H_

#include <compat/twi.h>

/* define CPU frequency in hz here if not defined in Makefile */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/* I2C clock in Hz */
#define SCL_CLOCK  200000L

uint8_t byt0;
uint8_t byt1;
uint8_t byt2;
uint8_t byt3;
uint8_t byt4;
uint8_t byt5;
uint8_t byt6;
uint8_t byt7;
uint8_t byt8;

unsigned char ret;

char str_1[];
uint8_t stat_value;

char str[];
uint16_t prediction_value;

char str_3[];
uint32_t resis_value;

char str_4[];
uint16_t tvoc_value;

unsigned char i2c_start(unsigned char addr);
unsigned char i2c_readAck(void);
unsigned char i2c_readNak(void);
void i2c_data(void);

void i2c_data(){
	
	ret = i2c_start(0xB5);       // set device address and write mode
	
	if (ret) {
		/* failed to issue start condition, possibly no device found */
		i2c_stop();
		
		lcd_string("Error: No status returned");
		_delay_ms(1000);
		lcd_init();
	}
	else {
		byt0 = i2c_readAck();                       // read one byte form address 0
		byt1 = i2c_readAck();                       //  "    "    "    "     "    1
		byt2 = i2c_readAck();                       //  "    "    "    "     "    2
		byt3 = i2c_readAck();                       //  "    "    "    "     "    3
		byt4 = i2c_readAck();                       //  "    "    "    "     "    4
		byt5 = i2c_readAck();                       //  "    "    "    "     "    5
		byt6 = i2c_readAck();                       //  "    "    "    "     "    6
		byt7 = i2c_readAck();                       //  "    "    "    "     "    7
		byt8 = i2c_readNak();                       //  "    "    "    "     "    8
		
		
	}
	
	i2c_stop();				 // set stop condition = release bus
	
	prediction_value = ((byt0 << 8) | byt1);
	stat_value = byt2;
	resis_value = ((byt3 & 0x00) | (byt4 << 16) | (byt5 << 8) | byt6);
	tvoc_value = ((byt7 << 8) | byt8);
	
	sprintf(str_1,"%u",stat_value);
	//lcd_output(str_1, "Status");
	
	prediction_value = prediction_value + 362;
	sprintf(str,"%u",prediction_value);
	//lcd_output(str_2, "CO2");
	
	sprintf(str_3,"%u",resis_value);
	//lcd_output(str_3, "Resistance");
	
	sprintf(str_4,"%u",tvoc_value);
	//lcd_output(str_4, "VOC");

}

void i2c_init(){
	/* initialize TWI clock: 100 kHz clock, TWPS = 0 => prescaler = 1 */
	TWSR = 0;                         /* no prescaler */
	TWBR = ((F_CPU/SCL_CLOCK)-16)/2;  /* must be > 10 for stable operation */
}

unsigned char i2c_start(unsigned char address)
{
	uint8_t   twst;

	// send START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));

	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_START) && (twst != TW_REP_START)) return 1;

	// send device address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT)));

	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) return 1;

	return 0;

}

unsigned char i2c_readAck(void){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));
	
	uint8_t r_test = TWDR;
	return TWDR;
}

unsigned char i2c_readNak(void){
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	
	return TWDR;
}

void i2c_stop(void){
	/* send stop condition */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	// wait until stop condition is executed and bus released
	while(TWCR & (1<<TWSTO));
}

void i2c_start_wait(unsigned char address){
	uint8_t   twst;


	while ( 1 )
	{
		// send START condition
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
		// wait until transmission completed
		while(!(TWCR & (1<<TWINT)));
		
		// check value of TWI Status Register. Mask prescaler bits.
		twst = TW_STATUS & 0xF8;
		if ( (twst != TW_START) && (twst != TW_REP_START)) continue;
		
		// send device address
		TWDR = address;
		TWCR = (1<<TWINT) | (1<<TWEN);
		
		// wail until transmission completed
		while(!(TWCR & (1<<TWINT)));
		
		// check value of TWI Status Register. Mask prescaler bits.
		twst = TW_STATUS & 0xF8;
		if ( (twst == TW_MT_SLA_NACK )||(twst ==TW_MR_DATA_NACK) )
		{
			/* device busy, send stop condition to terminate write operation */
			TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
			
			// wait until stop condition is executed and bus released
			while(TWCR & (1<<TWSTO));
			
			continue;
		}
		//if( twst != TW_MT_SLA_ACK) return 1;
		break;
	}
}

#endif /* I2C_H_ */