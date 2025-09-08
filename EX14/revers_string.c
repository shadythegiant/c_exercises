#include <unistd.h>

void reverse(char *str){
	char *end = str; 

	while(*end) end++;
	end--; 
	
	while(end >= str) {
		write(1,end,1); 
		end--; 
	}
}


void swap_strings(char **a, char **b){ 

	char *temp;
	temp = *a; 
	*a = *b; 
	*b = temp;  
}



int ft_strlen(char *str){ 
	char *start = str; 
	while(*str) { 
		str++; 
	}

	return(str - start); 
}

void advance_to_char(char ***str, char c) { 

	while(***str && ***str != c) {
		(**str)++; 
	}

	if(**str){ 
		write(1, **str, ft_strlen(**str)); 
	}
}

void rotate_left(int *arr, int size) { 
	
}
