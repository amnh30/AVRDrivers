/* LIB Layer */
#include "STD_TYPES.h"

#include "BIT_MATH.h"

/* MCAL Layer Include*/
#include "MGIE_Private.h"
#include "MGIE_Config.h"
#include "MGIE_Interface.h"
#include "STD_TYPES.h"



/* Enable Global Interrupt */
void MGIE_voidEnable(void) {
    /* Set the I-bit (7th bit) in the Status Register (SREG) to 1 */
    SET_BIT(PRIVATE_SREG, PRIVATE_INTERRUPT_BIT);
}

/* Disable Global Interrupt */
void MGIE_voidDisable(void) {
    /* Clear the I-bit (7th bit) in the Status Register (SREG) to 0 */
    CLEAR_BIT(PRIVATE_SREG, PRIVATE_INTERRUPT_BIT);
}
