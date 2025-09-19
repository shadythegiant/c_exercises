// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void ft_putchar(char c) {
    write(1,&c,1); 
}
void ft_memset(void *buffer, int c , size_t size) {
    size_t  i = 0; 
    char *ptbuffer = (char *)buffer; 
    unsigned  c_lowbits = c & 0xFF; 
    
    while(i < size) { 
        ptbuffer[i] = c_lowbits; 
        i++; 
    }
}

void ft_bzero(void *s, size_t n ) { 
    size_t i; 
    char c; 
    unsigned low_c; 
    char *ptr_s; 
    
    i = 0; 
    c = '\0'; 
    low_c = c & 0xFF; 
    ptr_s = (char *)s; 
    
    while( i < n) {
        ptr_s[i] = low_c; 
        i++; 
    }
}

int main() {
    // Write C code here
    char buffer[5]; 
    size_t i = 0; 
    size_t size = 5; 
    char c = 'H'; 
    /*ft_memset(buffer, c, size);*/ 
    ft_bzero(buffer, size); 
    while(i < size) {
        ft_putchar(buffer[i]); 
        i++; 
    }
    return 0;
}
