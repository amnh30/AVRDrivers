#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

/* Define Interrupt Number*/
#define MEXTI_INT0  0
#define MEXTI_INT1  1
#define MEXTI_INT2	2

/* Define Interrupt Source*/
#define MEXTI_FALLING_EDGE  		0
#define MEXTI_RAISING_EDGE  		1
#define MEXTI_ANY_LOGICAL_CHANGE	2
#define MEXTI_LOW_LEVEL				3







u8 MEXTI_u8Enable(u8 Copy_u8ExtINum,u8 Copy_u8ExtISrc);
u8 MEXTI_u8Disable(u8 Copy_u8ExtINum);
u8 MEXTI_u8Callback(u8 Copy_u8ExtINum,void(*Copy_Pf)(void));

#endif
