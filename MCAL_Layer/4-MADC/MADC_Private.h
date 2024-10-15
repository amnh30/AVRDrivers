#ifndef MADC_PRIVATE_H
#define MADC_PRIVATE_H

/*Define ADC Registers*/
#define PRIVATE_ADCMUX 		 *((volatile u8 *)0x27)
#define PRIVATE_ADCSRA   	 *((volatile u8 *)0x26)

#define PRIVATE_SFIOR 		 *((volatile u8 *)0x50)

#define PRIVATE_ADCH   		 *((volatile u8 *)0x25)
#define PRIVATE_ADCL   		 *((volatile u8 *)0x24)
#define PRIVATE_U16_ADC		*((volatile u16 *)0x24)

/* Timeout Max Value for ADC delay to get the Value*/
#define PRIVATE_TIMEOUT_MAX_VALUE  1000000UL

/* ADC Flag State Busy Or Not*/ 
#define PRIVATE_BUSY     1
#define PRIVATE_NOT_BUSY 0


#endif
