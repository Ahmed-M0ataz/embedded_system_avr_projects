
#ifndef BIT_CALC
#define BIT_CALC


#define set_bit(var,Bit_No) (var) |= (1<<Bit_No)
#define clear_bit(var,Bit_No) (var) &= ~(1<<Bit_No)
#define toogle_bit(var,Bit_No) (var) ^= (1<<(Bit_No))
#define get_bit(var,Bit_No) (var>>Bit_No)&(1)

 #endif
