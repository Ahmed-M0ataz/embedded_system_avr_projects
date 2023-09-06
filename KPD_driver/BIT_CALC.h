
#ifndef BIT_CALC
#define BIT_CALC
#define set_bit(var,bit_no) ((var) |= ((1<<bit_no)))  //set_bit to make number equal = 1
#define clear_bit(var,bit_no) ((var) &= ~(1<<bit_no))   // make number 1 to be zero
#define toggle_bit(var,bit_no) ((var) ^= ((1<<(bit_no)))    // تشقلب البيت لو 0 يبقي 1 لو 1 يبقي 1
#define  get_bit(var,bit_no) ((var>>bit_no)&(1))             // to know if bit = 1 or 0 = 1
#define assign_bit(var,bit_no,value) do{if(value==1) set_bit(var,bit_no); \
										else clear_bit(var,bit_no);}while(0)
#endif
