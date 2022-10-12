#include "key1.h"
#include "rotate.h"
#include <stdio.h>

void divideValue64(uint64 input, uint32 *leftOutput, uint32 *rightOutput)
{
    *leftOutput = (uint32)((input & 0xFFFFFFFF00000000LL) >> 32);
    *rightOutput = (uint32)(input & 0xFFFFFFFFLL);
}
void divideValue56(uint64 input, uint32 *leftOutput1, uint32 *rightOutput1)
{
    *leftOutput1 = (uint32)((input & 0xFFFFFFF0000000LL) >> 28);
    *rightOutput1 = (uint32)(input & 0x0000000FFFFFFFLL);
}

void gen_keys (uint64 * key_arr, uint32 key_left_28, uint32 key_right_28, int * rotate_table)
{
    for (int i = 0; i < 16; ++i){
        uint64 key_conca; 
        key_left_28 = rotate(&key_left_28, 28, rotate_table[i]); 
        key_right_28 = rotate(&key_right_28, 28, rotate_table[i]);
        key_conca = ((uint64) key_left_28 << 28) | key_right_28;
        key_arr[i] = key_conca; 
    }
}

// int main(void)
// {
//     uint64 x = 0xFFFFFFFF300330FF;
//     uint64 y = 0xFFFFF0F1FFFFFF;

//     uint32 read1;
//     uint32 read2;
//     uint32 key1;
//     uint32 key2;
//     divideValue64(x, &read1, &read2);
//     divideValue56(y, &key1, &key2);

//     printf("%x\n", read1);
//     printf("%x\n", read2);
//     printf("%x\n", key1);
//     printf("%x\n", key2);
// }