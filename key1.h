typedef unsigned long int uint64;
typedef unsigned int uint32;

void divideValue64(uint64 input, uint32 *leftOutput, uint32 *rightOutput);
void divideValue56(uint64 input, uint32 *leftOutput1, uint32 *rightOutput1);
void gen_keys (uint64 * key_arr, uint32 key_left_28, uint32 key_right_28, int * rotate_table);