// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c) { 
    write(1,&c,1); 
}    

void *ft_memset(void *buffer, int c , size_t size) { 
    size_t counter = 0; 
    unsigned low_8 = c & 0xFF; 
    char *bptr = (char *)buffer;
    while(counter < size) { 
        bptr[counter] = low_8; 
        counter++; 
    }
}

void *ft_memcpy(void *dest, const void *src, size_t size) {
    char *dest_ptr = (char *)dest; 
    const char  *src_ptr = (const char*)src; 
    size_t i = 0; 
    
    while(i < size) { 
        dest_ptr[i] = src_ptr[i]; 
        i++; 
    }
    return (dest); 
}

void *ft_memmove(void *dest, const void *src, size_t size) {
    char *dest_ptr = (char *)dest; 
    const char *src_ptr = (const char*)src; 
    size_t i = 0; 
    if(size == 0 || src == dest) return (dest);
    if( dest < src ) { 
        while(i < size ) { 
            dest_ptr[i] = src_ptr[i]; 
            i++; 
        }
    } else {
        i = size - 1; 
        while(i <= 0) {
            dest_ptr[i] = src_ptr[i]; 
            i--; 
        }
    }
    return (dest); 
}


int main() {
    size_t i = 0;  
    char buffer[5]; 
    char dest_buffer[5]; 
    size_t size = 5; 
    char c = 'H'; 
    ft_memset(buffer, c,size); 
    ft_memmove(dest_buffer, buffer, size);
    
    while(i < size) {
        ft_putchar(dest_buffer[i]); 
        i++; 
    }
    return 0;
}
