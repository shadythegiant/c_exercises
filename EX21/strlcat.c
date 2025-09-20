#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size) {
	size_t counter;
	size_t src_len; 
	size_t dest_len; 

	src_len = ft_strlen(src); 
	dest_len = ft_strlen(dest); 
	counter = 0; 
	if( size <= dest_len) 
		return (size + src_len); 
	
	while(src[j] && (dest_len + j) < size - 1) {
		dest[dest_len + j ] = src[j]; 
		j++;  
	}
	dest[dest_len + j ] = '\0'; 
	return( src_len + dest_len); 
}

