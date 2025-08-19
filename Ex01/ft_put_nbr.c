#include <unistd.h>


void ft_putchar(char c) { 
    write(1, &c, 1); 
}

void ft_putnbr(int nb) { 

    // if nb is negative 

    if(nb < 0) { 
        
        nb = -nb; 
        ft_putchar('-'); 
    }

    if (nb == 0) { 
        ft_putchar('0'); 
        return; 
    }

    if(nb <= 9) { 
        ft_putchar('0' + nb); 
        return; 
    }

    //

    char digits[10]; 
    int temp = nb; 
    int count = 0; 

    while (temp > 0) { 

        digits[count] = '0' + temp % 10; //extracting last num 
        temp = temp / 10;  // removing last num; 
        count++; 
    }

    int i = count - 1; 
   

    while (i  >=  0) { 
        //
        

        ft_putchar(digits[i--]); 
        
    } 


}


#include <limits.h>
#include <stdio.h>


int main() { 
    
    // ft_putnbr(1); 
    // ft_putchar('\n');
    printf("%d\n", INT_MAX);
        printf("%d\n", INT_MIN);

    return 0; 
}