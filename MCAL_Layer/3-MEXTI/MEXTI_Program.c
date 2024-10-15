/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer Include */
#include "MEXTI_Private.h"
#include "MEXTI_Config.h"
#include "MEXTI_Interface.h"

/* Array of Pointer to function to be called from ISRs */
static void(*MEXTI_APfEXTI[3])(void) = {POINTER_NULL, POINTER_NULL, POINTER_NULL};

/* Define additional interrupt trigger modes */
#define MEXTI_ANY_LOGICAL_CHANGE    2
#define MEXTI_LOW_LEVEL             3

/* Enable Interrupt Function */
u8 MEXTI_u8Enable(u8 Copy_u8ExtINum, u8 Copy_u8ExtISrc) {
    u8 Local_u8ErrorState = STD_TYPE_OK;

    switch (Copy_u8ExtINum) {
        case MEXTI_INT0:
            switch (Copy_u8ExtISrc) {
                case MEXTI_FALLING_EDGE:
                    /* Activate EXTI0 as Falling Edge */
                    CLEAR_BIT(PRIVATE_MCUCR, 0);
                    SET_BIT(PRIVATE_MCUCR, 1);
                    break;

                case MEXTI_RAISING_EDGE:
                    /* Activate EXTI0 as Rising Edge */
                    SET_BIT(PRIVATE_MCUCR, 0);
                    SET_BIT(PRIVATE_MCUCR, 1);
                    break;

                case MEXTI_ANY_LOGICAL_CHANGE:
                    /* Activate EXTI0 for Any Logical Change */
                    SET_BIT(PRIVATE_MCUCR, 0);
                    CLEAR_BIT(PRIVATE_MCUCR, 1);
                    break;

                case MEXTI_LOW_LEVEL:
                    /* Activate EXTI0 as Low Level */
                    CLEAR_BIT(PRIVATE_MCUCR, 0);
                    CLEAR_BIT(PRIVATE_MCUCR, 1);
                    break;

                default:
                    Local_u8ErrorState = STD_TYPE_NOK;
                    break;
            }
            /* Enable Interrupt for EXTI0 */
            SET_BIT(PRIVATE_GICR, 6);
            break;

        case MEXTI_INT1:
            switch (Copy_u8ExtISrc) {
                case MEXTI_FALLING_EDGE:
                    /* Activate EXTI1 as Falling Edge */
                    CLEAR_BIT(PRIVATE_MCUCR, 2);
                    SET_BIT(PRIVATE_MCUCR, 3);
                    break;

                case MEXTI_RAISING_EDGE:
                    /* Activate EXTI1 as Rising Edge */
                    SET_BIT(PRIVATE_MCUCR, 2);
                    SET_BIT(PRIVATE_MCUCR, 3);
                    break;

                case MEXTI_ANY_LOGICAL_CHANGE:
                    /* Activate EXTI1 for Any Logical Change */
                    SET_BIT(PRIVATE_MCUCR, 2);
                    CLEAR_BIT(PRIVATE_MCUCR, 3);
                    break;

                case MEXTI_LOW_LEVEL:
                    /* Activate EXTI1 as Low Level */
                    CLEAR_BIT(PRIVATE_MCUCR, 2);
                    CLEAR_BIT(PRIVATE_MCUCR, 3);
                    break;

                default:
                    Local_u8ErrorState = STD_TYPE_NOK;
                    break;
            }
            /* Enable Interrupt for EXTI1 */
            SET_BIT(PRIVATE_GICR, 7);
            break;

        case MEXTI_INT2:
            if (Copy_u8ExtISrc == MEXTI_FALLING_EDGE) {
                /* Activate EXTI2 as Falling Edge */
                CLEAR_BIT(PRIVATE_MCUCSR, 6);
            } else if (Copy_u8ExtISrc == MEXTI_RAISING_EDGE) {
                /* Activate EXTI2 as Rising Edge */
                SET_BIT(PRIVATE_MCUCSR, 6);
            } else {
                Local_u8ErrorState = STD_TYPE_NOK;
            }
            /* Enable Interrupt for EXTI2 */
            SET_BIT(PRIVATE_GICR, 5);
            break;

        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
    }

    return Local_u8ErrorState;
}

/* Disable Interrupt Function */
u8 MEXTI_u8Disable(u8 Copy_u8ExtINum) {
    u8 Local_u8ErrorState = STD_TYPE_OK;

    switch (Copy_u8ExtINum) {
        case MEXTI_INT0:
            /* Disable Interrupt for EXTI0 */
            CLEAR_BIT(PRIVATE_GICR, 6);
            break;

        case MEXTI_INT1:
            /* Disable Interrupt for EXTI1 */
            CLEAR_BIT(PRIVATE_GICR, 7);
            break;

        case MEXTI_INT2:
            /* Disable Interrupt for EXTI2 */
            CLEAR_BIT(PRIVATE_GICR, 5);
            break;

        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
    }

    return Local_u8ErrorState;
}

/* Set Callback Function */
u8 MEXTI_u8Callback(u8 Copy_u8ExtINum, void(*Copy_Pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (POINTER_NULL != Copy_Pf && Copy_u8ExtINum <= 2) {
        MEXTI_APfEXTI[Copy_u8ExtINum] = Copy_Pf;
    } else {
        Local_u8ErrorState = STD_TYPE_NOK;
    }

    return Local_u8ErrorState;
}

/* ISR Implementations */
void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
    if (POINTER_NULL != MEXTI_APfEXTI[0]) {
        MEXTI_APfEXTI[0]();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
    if (POINTER_NULL != MEXTI_APfEXTI[1]) {
        MEXTI_APfEXTI[1]();
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void) {
    if (POINTER_NULL != MEXTI_APfEXTI[2]) {
        MEXTI_APfEXTI[2]();
    }
}
