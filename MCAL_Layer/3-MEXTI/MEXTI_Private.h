#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

#define PRIVATE_MCUCR  	*((volatile u8 *)0x55)
#define PRIVATE_MCUCSR  *((volatile u8 *)0x54)
#define PRIVATE_GICR  	*((volatile u8 *)0x5B)
#define PRIVATE_GIFR  	*((volatile u8 *)0x5A)

#endif
