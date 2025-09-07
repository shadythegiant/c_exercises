#include <unistd.h>


#define SIZE 5
void ft_putstr(char *string) {
	while(*string) { 
		ft_putchar(string); 
		string++; 
	}
}
void ft_putchar(char c) { 
	write(1,&c,1); 
}

void ft_punbr(int num) {
	char c; 
	long int nbr = num;  
	if(nbr < 0) { 
		ft_putchar('-'); 
		nbr = -nbr; 
	}
	if( nbr  >= 10) { 
		nbr = nbr / 10; 
	}
	c = (nbr % 10) + '0';
	ft_putchar(c);  
}

void ft_swap(int *num1, int *num2) { 
	int temp = *num1; 
	*num1 = *num2; 
	*num2 = temp; 
}

void swap_array(int *arr1, int *arr2) { 
	int i = 0; 
	while(i < SIZE) { 
		ft_swap(&arr1[i], &arr2[i]); 
		i++; 
	}
}

void printArray(int *arr) { 
	int i = 0; 
	while( i < SIZE) { 
		ft_punbr(arr[i]);
		
		i++; 
	}
}


int main() { 

int array1[SIZE] = {1,2,3,4,5}; 
int array2[SIZE] = {5,4,3,2,1}; 
   swap_array(array1, array2);
   ft_putchar('\n'); 

   printArray(array1); 
   ft_putchar('\n'); 
   printArray(array2); 
   ft_putchar('\n'); 

   return 0; 
}