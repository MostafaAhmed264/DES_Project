#include "file_reading.h"

int main(int argc,char *argv[]){
    char buffer [16]; 
    u_int64_t data; 
    int i = 0;
    /*
        reading file name from command line and opening file in read binary mode
    */
    char *file_name = argv[1]; 
    FILE *fp = fopen("test.txt", "rb"); 
    /*check file is oppened successfully*/
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    } 


    /*loop for reading the input file*/

    while(fread(buffer, 16, 1, fp) != 0)
    {
        /*
            read data into buffer 
            convert string into hexadecimal value 
            clear buffer
        */
        data = string_to_hex(buffer); 
        memset(buffer, '\0', 16);
        printf("%lx", data); 
        i++;
    }

}