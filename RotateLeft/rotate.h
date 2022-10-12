typedef unsigned long uint64;
typedef unsigned int uint32;
#define KEY_32_BITS             //full size of the key passed to the function 
#ifdef KEY_64_BITS
#define KEY_FULL_SIZE 64
#endif
#ifdef KEY_32_BITS
#define KEY_FULL_SIZE 32
#endif
uint64 rotate(uint64 *  key, int sizeOfKey, int rotationAmount);
uint32 rotate(uint32 *  key, int sizeOfKey, int rotationAmount);