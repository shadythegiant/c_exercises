#include <stdlib.h>
int     *ft_rrange(int start, int end) { 
	int i; 
	int size; 
	int *range; 

	if(start == end) { 
		range = malloc(sizeof(int)); 
		if(!range) 
			return NULL; 
		range[0] = start; 
		return (range); 
	}

	if(start > end) { 
		size = (start - end) + 1; 
	}
	if(start < end) { 
		size = (end - start) + 1; 
	}
	range = malloc(sizeof(int) * size); 
	if(!range) return NULL; 
	i = 0; 
	while (i < size ) { 
		if(start < end ) { 
			range[i] = end  - i; 
		} else {
			range[i] = end + i; 
		}
		i++; 
	}
	
	return(range); 
}

// #include <stdio.h>

// int main() { 
// 	int min = -1; 
// 	int max = 3; 
// 	int size = (min > max) ? (min - max + 1) : (max - min + 1); 

// 	int *range = ft_rrange(min , max); 

// 	// printf("%d \n", range[0]); 
// 	// printf("%d \n", size); 
// 	for(int i = 0; i < size;  i ++) { 

// 		printf("%d\n", range[i]); 
// 	}

// 	return 0; 
// }
