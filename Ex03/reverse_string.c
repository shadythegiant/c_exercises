#include <unistd.h>

void revers_str(char *str) { 

    if(!str) return; //NULL check
    // get str len 
    int length = 0; 

    while(str[length]) length++; 

    if(length == 0) return; // empty string

    while(length - 1 >= 0) { 

        write(1,&str[length],1); 
        length--; 
    }

    write(1,"\n", 1); 
}