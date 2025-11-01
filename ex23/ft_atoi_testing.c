// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char const *s) { 
    size_t len = 0; 
    while(*s++) 
        len++; 
    return (len);     
}

size_t ft_strlcpy(char *dest, char const *src , size_t size) { 
    size_t src_len = ft_strlen(src); 
    size_t i = 0; 
    if( size == 0) 
        return (src_len); 
    if (size > 0) { 
        while(i < size - 1 && *src) { 
            dest[i] = src[i]; 
            i++; 
        }  
        dest[i] = '\0'; 
        return (src_len); 
    }     
} 



size_t ft_countdigits(int n) { 
    size_t counter; 
    long nb; 
    nb = n; 
    counter = 0; 
    if(nb < 0) { 
        counter++; 
        nb =  -nb; 
    } 
    if(nb == 0) 
        return (1);
    while(nb) { 
        counter++; 
        nb = nb / 10; 
    } 
    return (counter);     
} 
char *ft_fillstr(char *s, int n) { 
    size_t size = ft_countdigits(n); 
    int start; 
    int counter = size - 1; 
    long nb = n; 
    if(nb < 0) { 
        start = 1; 
        nb = - nb; 
        s[0] = '-'; 
    }  else 
        start = 0; 
    while(counter >= start ) { 
        s[counter] = nb % 10 + '0'; 
        nb = nb / 10; 
        counter--; 
    } 
    return (s); 
} 
char *ft_itoa(int n) { 
    size_t digit_count = ft_countdigits(n); 
    char *str = malloc(digit_count + 1); 
    if(!str)
        return NULL; 
    str = ft_fillstr(str, n); 
    return(str); 
} 

int main() {
    // Write C code here
   int n = 2147483647; 
  
  printf("%s", ft_itoa(n)); 
   
    return 0;
}
