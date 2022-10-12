typedef unsigned long int uint64;
typedef unsigned int uint32;
#include <iostream>

void divideValue64(uint64 input, uint32 &leftOutput, uint32 &rightOutput)
{
    leftOutput = (uint32)((input & 0xFFFFFFFF00000000LL) >> 32);
    rightOutput = (uint32)(input & 0xFFFFFFFFLL);
}
void divideValue56(uint64 input, uint32 &leftOutput1, uint32 &rightOutput1)
{
    leftOutput1 = (uint32)((input & 0xFFFFFFF0000000LL) >> 28);
    rightOutput1 = (uint32)(input & 0x0000000FFFFFFFLL);
}

int main(void)
{
    uint64 x = 0xFFFFFFFF300330FF;
    uint64 y = 0xFFFFF0F1FFFFFF;

    uint32 read1;
    uint32 read2;
    uint32 key1;
    uint32 key2;
    divideValue64(x, read1, read2);
    divideValue56(y, key1, key2);

    printf("%x\n", read1);
    printf("%x\n", read2);
    printf("%x\n", key1);
    printf("%x\n", key2);
}