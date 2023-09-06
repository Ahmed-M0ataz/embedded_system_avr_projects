
#ifndef BIT_CALC
#define BIT_CALC


#define set_bit(var,Bit_No) ((var) |= (1<<Bit_No)) //Ø¨ØªØ®Ù„ÙŠ Ø§Ù„Ø¨Øª Ø¨ ÙˆØ§Ø­Ø¯
#define clear_bit(var,Bit_No) ((var) &= (~(1<<Bit_No))) //Ø¨ØªØ®Ù„ÙŠ Ø§Ù„Ø¨Øª Ø¨ ØµÙ�Ø± //~ meaning 2 complement
#define toogle_bit(var,Bit_No) ((var) ^= (1<<(Bit_No)))//Ø¨ØªØ´Ù‚Ù„Ø¨ Ø§Ù„ Ø¨Øª // ^ xor
#define get_bit(var,Bit_No) ((var>>Bit_No)&(1))//Ø¨Ø¹Ø±Ù� Ù…Ù†Ù‡Ø§ Ø§Ù„Ø¨Øª Ø¯ÙŠ Ø¨ 0 ÙˆØ§Ù„Ø§ Ø¨ 1

 #endif

