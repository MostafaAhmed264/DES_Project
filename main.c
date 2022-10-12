#include "file_reading.h"
#include "key1.h"
#include "sbox.h"
#include "rotate.h"
#include "tables.h"
#include "per.h"



int main(int argc,char *argv[]){
    char buffer [16]; 
    u_int64_t data; 
    /*
        reading file name from command line and opening file in read binary mode
    */
    char *file_name = argv[1]; 
    FILE *fp = fopen("test.txt", "rb"); 
    char *key_file = argv[2]; 
    FILE *fp_key = fopen("key.txt", "rb"); 
    uint64_t main_key; 
    uint64 key_array[16]; 
    /*check file is oppened successfully*/
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    } 

    /*read key from file*/
    fread(buffer, 16, 1, fp_key); 
    main_key = string_to_hex(buffer); 
    memset(buffer, '\0', 16);


    /*KEY Permutiation*/
    uint64_t key_permute_56; 
    key_permute_56 = permute(56, keyp, 64, main_key); 
    /*Divide Key into two halfs*/
    uint32 key_left_28; 
    uint32 key_right_28; 

    divideValue56(key_permute_56, &key_left_28, &key_right_28); 
    /*shift left key according to table and generate 16 keys*/
    gen_keys(key_array, key_left_28, key_right_28, shift_table); 


    /*loop for reading the input file and ENCRYPTION*/

    while(fread(buffer, 16, 1, fp) != 0)
    {
        uint64_t encrypted_data; 
        int rounds = 0; 
        /*
            read data into buffer 
            convert string into hexadecimal value 
            clear buffer
        */
        data = string_to_hex(buffer); 
        memset(buffer, '\0', 16);
        uint32 data_left; 
        uint32 data_right; 
        
        /*Initial permutiation*/
        data = permute(64, initial_perm, 64, data);

        /*Divide data into two parts*/
        divideValue64(data, &data_left, &data_right); 

        for (rounds; rounds < 16; rounds++)
        {
            uint64 temp_key; 
            uint64 temp_data; 
            /*compress key into 48 bits from 56 bits*/
            temp_key = permute(48, key_comp, 56, key_array[rounds]);
            /*Expand right portion of the data into 48 bits from 32*/
            temp_data = permute(48, exp_d, 32, data_right); 
            /*XOR Expanded data and compressed key*/ 
            temp_data ^= temp_key; 
            /*SBOX the 48 bit temp_data*/
            temp_data = sbox(temp_data); 
            /*Permute data for 32 bit*/
            temp_data = permute(32, per, 32, temp_data); 
            /*XOR with left portion of the data*/
            temp_data ^= data_left; 
            /*swap the 2 values*/
            data_left = data_right; 
            data_right = temp_data; 
        }

        encrypted_data = ((uint64) data_right << 32) | data_left; 
        encrypted_data = permute(64, final_perm, 64, encrypted_data); 
        printf ("%lx", encrypted_data); 
    }

    


}