#include <stdint.h>
#define SBOX_INPUT_SIZE 48
#define SBOX_OUTPUT_SIZE 32
#define NUM_OF_BLOCKS 8
#define SIZE_OF_S_BLOCK_INPUT 6
#define SIZE_OF_S_BLOCK_OUTPUT 4
uint32_t sbox(uint64_t sbox_input);