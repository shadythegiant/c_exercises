// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s) { 
    size_t len = 0; 
    while(*s) { 
        len++; 
        s++; 
    }
    return (len); 
}

char *ft_strchr(char const *s1, int c) {
    
    while(*s1 && *s1 != (char) c) {
     
        s1++;  
    }
    if(*s1 == (char ) c)
        return((char *)s1); 
    return NULL;
} 

void *ft_memcpy(void  *dest, const void *src, size_t len) { 
    unsigned char *dest_ptr; 
    const unsigned char *src_ptr; 
    
    if(dest == src || len == 0)
        return(dest); 
    dest_ptr = (unsigned char *)dest;
    src_ptr = (const unsigned char *)src; 
    while( len--) { 
        *dest_ptr++ = *src_ptr++; 
       
    } 
    return(dest);
} 

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	char	*start;

	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
	{
		return (NULL);
	}
	start = copy;
	while (*s)
	{
		*copy++ = *s++;
	}
	*copy = '\0';
	return (start);
}

char *ft_substr(char const *s, unsigned int start,
size_t len) {  
    size_t s_len; 
    size_t sub_len;
    char *sub; 
    if(!s)
        return NULL; 
    s_len = ft_strlen(s); 
    if(start >= s_len) { 
        sub = malloc(1); 
        sub[0] = '\0'; 
        return sub; 
    } 
    if(s_len - start < len) 
        sub_len = s_len - start; 
    else 
        sub_len = len;
    sub = malloc((sub_len + 1));
    if(!sub)
        return NULL; 
        ft_memcpy(sub, s + start, sub_len);
       sub[sub_len] = '\0'; 
    return (sub); 
        
} 
char *ft_strjoin(char const *s1, char const *s2) { 
    char *result; 
    char *s; 
    
    result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1); 
    if(!result)
        return NULL; 
    s = result; 
    while(*s1) 
        *result++ = *s1++; 
    while(*s2) 
        *result++ = *s2++; 
    *result = '\0'; 
    return(s); 
} 
char *ft_strtrim(char const *s1, char const *set) { 
    size_t  start; 
    size_t  end; 
    char *trimmed; 
    if(!s1)
        return NULL; 
    if(!set || !*s1)
        return (ft_strdup(s1)); 
    start = 0; 
    while(s1[start] && ft_strchr(set, s1[start]))
        start++; 
    if(!s1[start])
        return(ft_strdup("")); 
    end = ft_strlen(s1) - 1; 
    while(ft_strchr(set, s1[end]) && end > 0)
        end--; 
    trimmed = ft_substr(s1, start, (end - start) + 1); 
    return (trimmed); 
} 
int main() {
    char *src = "hello";
    char *s = ""; 
    char *sub = ft_substr(src, 1, 4); 
    char *result = ft_strjoin(src, sub); 
    char *set = " -"; 
    char *trimmed = ft_strtrim(s, set); 
    printf(" substring ->  %s  joined string -> %s  trimmed str -> %s", sub, result, trimmed); 

    return 0;
}
