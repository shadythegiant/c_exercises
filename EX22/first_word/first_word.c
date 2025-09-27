#include <unistd.h>


int ft_isspace(int c) { 
	if((c >= 9 && c <= 13) || c == 32 ) { 
		return 1; 
	}
	return 0; 
 }

 int isalpha(int c ) { 
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) return 1;
	return 0; 
 }
void ft_putchar(char c) { 
	write(1, &c , 1); 
}


int main( int argc, char **argv) { 
	if(argc == 2) {
	int i = 0;  
	char *s = argv[1]; 
	while(s[i] && ft_isspace(s[i]) ) { 
		i++; 
	}
	while(s[i] && !ft_isspace(s[i])) {
		ft_putchar(s[i]); 
		i++; 
	}
	
	}
	ft_putchar('\n'); 
}