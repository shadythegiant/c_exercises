#include <stdio.h>
#include <stdlib.h>


size_t ft_strlen(char const *s) {
    size_t len; 
    while(*s)
        len++; 
    return (len);     
}

size_t ft_strlcpy(char *dest, char const *src, size_t size) { 
    size_t i = 0;
    if(!src) {
        return 0; 
    }
   if(size > 0) {
       while(i < size - 1 && *src) {
           dest[i] = src[i]; 
           i++; 
       }
       dest[i] = '\0'; 
       return(ft_strlen(src)); 
   }    
}  


// step 1; 

size_t ft_wordcount(char const *s, char delimeter) {
    size_t word_count  = 0; 
    while(*s) { 
        while(*s && *s == delimeter)
            s++; 
        if(*s)
            word_count++; 
   
        while(*s && *s != delimeter)
            s++; 
    }
    return (word_count); 
} 

// step 2 
// return 1 if allocations fails 
// 0 if it  goes well! 

size_t ft_free(char **strings, size_t position, size_t len) {
    size_t i = 0; 
    strings[position] = malloc(len); 
    if(!strings[position]) {
        while(i < position) {
            free(strings[i++]); 
        }
        free(strings); 
        return 1; 
    }
    return 0; 
}  
size_t ft_fillarr(char ** strings, char const *s, char delimeter ) {
    size_t len; 
    size_t position; 
    while(*s) {
        len = 0;
        while(*s == delimeter && *s)
            s++; 
        while(*s && *s != delimeter) {
            len++; 
            s++; 
        }     
        if(len) {
            if(ft_free(strings, position,len+1 ))
                return 1; 
        }
        ft_strlcpy(strings[position], s- len, len + 1); 
        position++; 
    } 
    
    return 0; 
} 


char **split(char const *s, char c) {
    
    //count tokens 
    // allocate mem for the array of strs
    //cpy the token in the correct position
    size_t word_count; 
    char **strings; 
    
    if(!s)
        return NULL; 
    
    word_count = ft_wordcount(s, c); 
    strings = malloc((word_count + 1) * sizeof(char *)); 
    if(!strings)
        return NULL; 
    strings[word_count] = NULL;    
    if(ft_fillarr(strings, s, c)) 
        return NULL; 
    return strings;     
    
}

int main() {
    // Write C code here
   char *s = "hello-world-are-there";
   char c = '-'; 
   char **strings = split(s, c); 
   char space = ' '; 
   printf("%d", ft_wordcount(s, space )); 

    return 0;
}