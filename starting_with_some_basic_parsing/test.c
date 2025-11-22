// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


int ft_strlen(const char *s) { 
    int len =0; 
    while(*s++)
        len++; 
    return (len);     
} 

int ft_isspace(int c) { 
    return (c >= 9 && c <= 13 || c == 32); 
}
char *ft_strchr(char *s, int c) { 
    while(*s && *s != (char)c)
        s++; 
    if(*s == (char)c)
        return((char *)s); 
    return (NULL);     
} 


char *ft_strjoin(const char *s1, const char *s2) { 
    char *conctaed = malloc(ft_strlen(s1) + ft_strlen(s2) + 1); 
    int i = 0; 
    while(s1[i]) 
    {  
        conctaed[i] = s1[i]; 
        i++; 
    } 
    int j = 0; 
    while(s2[j]) { 
        conctaed[i] = s2[j]; 
        j++; 
        i++; 
    } 
    conctaed[i] ='\0'; 
    return (conctaed); 
} 
// /
char *ft_topath(char *str) { 
    int c = '/'; 
    int i = 0; 
    int j = 0; 
    char *start = ft_strchr(str, c) + 1;
    char  *path = "/index.html"; 
    char *cpy = start; 
    
    while(cpy[i] && !ft_isspace(cpy[i]))
        { 
            i++; 
        }
    char *end = malloc(i + 1); 
    while(j < i  && start[j] )
    { 
        end[j] = start[j]; 
        j++; 
    } 
    end[j] = '\0'; 
    return (ft_strjoin(end, path)); 
} 

int main() {
    // Write C code here
    char *start = ft_topath("HTTP /hello word"); 
    printf("%s \n", start); 
    return 0;
}