#include "rotate.h"
#ifdef KEY_64_BITS
uint64 rotate(uint64 *  key, int sizeOfKey, int rotationAmount)
{
    // putting bits on the left
    uint64 x = *key << (KEY_FULL_SIZE - sizeOfKey);
    // putting the bits rotated on the right
    uint64 y = x >> (KEY_FULL_SIZE - rotationAmount);
    // putting the key shifted with the rotation amount
    uint64 z = (x << rotationAmount) >> (KEY_FULL_SIZE - sizeOfKey );
    return z | y;
}
#endif
#ifdef KEY_32_BITS
uint32 rotate(uint32 *  key, int sizeOfKey, int rotationAmount)
{
    // putting bits on the left
    uint32 x = *key << (KEY_FULL_SIZE - sizeOfKey);
    // putting the bits rotated on the right
    uint32 y = x >> (KEY_FULL_SIZE - rotationAmount);
    // putting the key shifted with the rotation amount
    uint32 z = (x << rotationAmount) >> (KEY_FULL_SIZE - sizeOfKey );
    return z | y;
}
#endif