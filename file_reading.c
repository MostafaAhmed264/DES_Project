#include "file_reading.h"

u_int64_t string_to_hex(char * buffer){ 
    u_int64_t data = 0;
    int i = 0;  
    u_int64_t value; 
    for (i ; i < 16; ++i){
        if (buffer [i] <= 57)
        {
            value = (buffer[i] - 48); 
            data |= (value << ((16-i)*4)-4);
        }
        else if (buffer [i] <= 70)
        {
            value = (buffer[i] - 55); 
            data |= (value << ((16-i)*4)-4);
        }
        else
        {
            value = (buffer[i] - 87); 
            data |= (value << ((16-i)*4)-4);
        }
    }
    return data; 
}
