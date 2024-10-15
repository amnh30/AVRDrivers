/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer Include */
#include "MADC_Private.h"
#include "MADC_Config.h"
#include "MADC_Interface.h"

static u8 PRIVATE_u8BusyFlag = PRIVATE_NOT_BUSY;
static void (*PRIVATE_Pf)(u16) = POINTER_NULL;

/* Set Initial ADC Function */
void MADC_voidInit(void)
{

    PRIVATE_ADCMUX = MADC_ADJUST_VALUE & MADC_V_REFERENC_MODE;

    PRIVATE_ADCSRA = MADC_TRIGGER_MODE & MADC_PRESCALER & MADC_ADC_ENABLE;
}

u8 MADC_u8ADCEnable(u8 Copy_u8ChannelNum)
{
    /* 1- Enable ADC Peripheral */
    SET_BIT(PRIVATE_ADCSRA, 7);

    return STD_TYPE_OK; // Missing return type for function
}

u8 MADC_u8GetADCValueSync(u8 Copy_u8ChannelNum, u16 *Copy_Pu16ADCValue)
{
    u8 Local_u8ErrorState = STD_TYPE_NOK;

    /* Validate channel number and pointer */
    if ((Copy_u8ChannelNum < 32) &&
        (Copy_Pu16ADCValue != POINTER_NULL))

    {
        u32 Local_u32DelayCounter = 0;
        Local_u8ErrorState = STD_TYPE_OK;

        /* Clear Channel Number Bits */
        PRIVATE_ADCMUX &= 0b11100000;

        /* Set Channel Number */
        PRIVATE_ADCMUX |= Copy_u8ChannelNum;

        /* Start Conversion */
        SET_BIT(PRIVATE_ADCSRA, 6);

        /* Wait for ADC Flag */
        while (!(GET_BIT(PRIVATE_ADCSRA, 4)) && (Local_u32DelayCounter < PRIVATE_TIMEOUT_MAX_VALUE))
        {
            Local_u32DelayCounter++;
        }

        if ((GET_BIT(PRIVATE_ADCSRA, 4)))
        {
            Local_u8ErrorState = STD_TYPE_OK;
        }
        else
        {
            Local_u8ErrorState = STD_TYPE_NOK;
        }

        /* Read ADC Value */
        *Copy_Pu16ADCValue = PRIVATE_U16_ADC;

        /* Clear Flag */
        SET_BIT(PRIVATE_ADCSRA, 4);
    }

    return Local_u8ErrorState;
}

u8 MADC_u8GetADCValueAsync(u8 Copy_u8ChannelNum, void (*Copy_Pf)(u16))
{
    u8 Local_u8ErrorState = STD_TYPE_NOK;

    /* Validate channel number and pointer */
    if ((Copy_u8ChannelNum < 32) &&
        (Copy_Pf != POINTER_NULL) &&
        (PRIVATE_u8BusyFlag == PRIVATE_NOT_BUSY))
    {
        /* The error State is Ok*/
        Local_u8ErrorState = STD_TYPE_OK;

        /* ADC is Busy Now*/
        PRIVATE_u8BusyFlag = PRIVATE_BUSY;

        /* Set Call back Funtion*/
        PRIVATE_Pf = Copy_Pf;

        /* Clear Channel Number Bits */
        PRIVATE_ADCMUX &= 0b11100000;

        /* Set Channel Number */
        PRIVATE_ADCMUX |= Copy_u8ChannelNum;

        /* Enable ADC Interrupt*/
        SET_BIT(PRIVATE_ADCSRA, 3);

        /* Start Conversion */
        SET_BIT(PRIVATE_ADCSRA, 6);
    }

    return Local_u8ErrorState;
}

/* ADC ISR */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    if (PRIVATE_Pf != POINTER_NULL)
    {
        PRIVATE_Pf(PRIVATE_U16_ADC);
        PRIVATE_u8BusyFlag = PRIVATE_NOT_BUSY;
    }
    /* Disable ADC Interrupt */
    CLEAR_BIT(PRIVATE_ADCSRA, 3);
}