// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


void *ft_memcpy(void *dest, const void *src, size_t size) { 
    size_t i; 
    char *dest_ptr = (char *)dest; 
    char *src_ptr = (const char *)src; 
   i = 0; 
   while (i < size) { 
       *dest_ptr[i] = *src_ptr[i]; 
       i++; 
   } 
   return(dest); 
}
size_t ft_strlen(char *s) { 
    size_t i = 0; 
    while (s[i]) { 
        i++; 
    }
    return(i); 
}

// 
char *ft_substr(char const *s, unsigned int start,
size_t len) { 
    size_t s_len = ft_strlen(s); 
    
    if(start > (len - 1) || len < 0 || !s) { 
        return NULL; 
    }
    
    char *sub = malloc(sizeof(char) * len); 
    if(!sub) { 
        return NULL; 
    }
    
    ft_memcpy(sub, s, len); 
    return (sub); 
    
}
int main() {
    // Write C code here
    

    return 0;
}
