#include <unistd.h>

void ft_putchar(char c ) { 
	write(1, &c , 1); 
}

int ft_isdigit(int c) { 
	if( c >= '0' && c <= '9') 
		return 1; 

	return 0; 
}

int ft_is_prime(int nb) { 
	if( nb < 2) 
		return 0; 

	int i = 2; 
	while(i < nb / 2) { 
		if(nb % i  == 0) 
			return 0; 
		
		i++; 	
	}	
	return 1; 
}

void ft_putnb(int nb) { 
	int i = 0; 
	char buffer[200]; 
	long int nbr = nb; 
	if(nbr < 0) { 
		ft_putchar('-'); 
		nbr = -nbr; 
		
	}

	if(nbr == 0) { 
		ft_putchar('0'); 
		return; 
	}

	while(nbr) { 
		buffer[i] = (nbr % 10) + '0';
		nbr = nbr / 10; 
		i++;  
	}

	i = i - 1; 
	while(i >=  0) { 
		ft_putchar(buffer[i]); 
		i--; 
	}
}

void add_prim_sum_print(int nb) {
	int results = 0; 
	
	while (nb >= 2) { 
		if(ft_is_prime(nb)) { 
			results += nb; 
		}
		nb--; 
	}
	ft_putnb(results); 
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

int main(int argc , char *argv[]) { 
	if(argc == 2) { 
	char *s = argv[1]; 
	int nbr = ft_atoi(s); 
	add_prim_sum_print(nbr); 
	}

	ft_putchar('\n'); 
}