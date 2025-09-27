#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c) {
	write(1,&c,1); 
}
void ft_putstr(char *s) { 
	while(*s) { 
		ft_putchar(*s); 
		s++; 
	}
}

int ft_isalpha(int c) { 
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')); 
}

int ft_isspace(int c ) { 
	return((c >= 9 && c <= 13) || c == 32); 
}

int ft_countwords(char *s) { 
	int in_word = 0;
	int wordcount = 0;  
	int i = 0; 
	while(s[i]) { 
		if(ft_isalpha(s[i]) && !in_word) { 
			wordcount++; 
			in_word = 1; 
		 }
		 else if(ft_isspace(s[i]) ) { 
			in_word = 0; 
		 }
		 i++; 
	}
	return wordcount; 	
}