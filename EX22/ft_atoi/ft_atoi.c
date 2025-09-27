#include <stdio.h>

int ft_isdigit(int c) { 
	if(c >= '0' && c <= '9' )
		return 1; 
	return 0; 	
}
int ft_atoi(char *s) {
	int num = 0; 
	int i = 0;  
	short sign = 1; 
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)) { 
			i++;
	}
	
	while(s[i] == '+' || s[i] == '-') { 
		if(s[i] == '-') sign = - 1; 
		i++; 
	}

	while(s[i]&& ft_isdigit(s[i])) { 
		num = (num * 10) + (s[i] - '0'); 
		i++; 
	}
	return (num * sign); 
}

