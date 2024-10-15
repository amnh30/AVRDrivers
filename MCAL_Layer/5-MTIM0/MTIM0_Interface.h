#ifndef MADC_INTERFACE_H
#define MADC_INTERFACE_H



/* Vreference for ADC */
#define MADC_EXTERNAL_V_REFERENCE        0b00111111  /* External reference voltage */
#define MADC_AVCC                        0b01111111  /* AVCC with external capacitor */
#define MADC_INTERNAL_V_REFERENCE_256MV  0b11111111  /* Internal 2.56V reference */

/* Adjustment Mode */
#define MADC_ADJUST_RIGHT                0b11011111  /* Right adjustment */
#define MADC_ADJUST_LEFT                 0b11111111  /* Left adjustment */

/* Trigger Mode */
#define MADC_SINGLE_TRIGGER_MODE         0b11011111  /* Single trigger mode */
#define MADC_AUTO_TRIGGER_MODE           0b11111111  /* Auto trigger mode */

/* Prescaler Options */
#define MADC_PRESCALER_2                 0b11111001       /* Prescaler value 2 */
#define MADC_PRESCALER_4                 0b11111010       /* Prescaler value 4 */
#define MADC_PRESCALER_8                 0b11111011       /* Prescaler value 8 */
#define MADC_PRESCALER_16                0b11111100       /* Prescaler value 16 */
#define MADC_PRESCALER_32                0b11111101       /* Prescaler value 32 */
#define MADC_PRESCALER_64                0b11111110       /* Prescaler value 64 */
#define MADC_PRESCALER_128               0b11111111       /* Prescaler value 128 */

/* ADC Enable Options */
#define MADC_ENABLE                      0b11111111         /* ADC enable */
#define MADC_DISABLE                     0b01111111         /* ADC disable */

/* Start Conversion Options */
#define MADC_START_CONVERSION            0b11111111         /* Start conversion */
#define MADC_NO_CONVERSION               0b10111111         /* No conversion */




/* Intial Configuration*/

void MADC_voidInit(void);
u8 MADC_u8ADCEnable(u8 Copy_u8ChannelNum);

u8 MADC_u8GetADCValueSync(u8 Copy_u8ChannelNum, u16 *Copy_Pu16ADCValue);
u8 MADC_u8GetADCValueAsync(u8 Copy_u8ChannelNum, void (*Copy_Pf)(u16));


#endif
