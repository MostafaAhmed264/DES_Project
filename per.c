#include "per.h"
    uint64 permute(int size_of_output,const int* arr,int size_of_input,uint64 input_number){
        uint64 mask=0x1;
        uint64 read_bit=0;
        uint64 output_number=0;
        for(int i=0;i<size_of_output;i++){
            // arr[i]-1 because the numbers are ordered from 1 to size of input number
            read_bit=(input_number  & (mask<<size_of_input-arr[i]))? 1: 0;   
            output_number|=(read_bit<<((size_of_output-1)-i));
        }
        return output_number;
    }