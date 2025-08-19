#include <unistd.h>



void ft_putchar(char c) { 
    write(1, &c, 1); 
}

void print_num() { 

   int i = 99; 

   while (i >= 9) { 
    char num; 
    char units; 
    if(i >= 10) { 

        num = '0' + i / 10; 
        units = '0' + i % 10; 

        write(1, &num, 1); 
        write(1, &units, 1); 
    } 
    
    else if(i < 10) { 

        num = '0' + i; 
        write(1, &num, 1); 
    }
    ft_putchar(','); 
    

    i--; 
   }
    
}


int main() { 

    print_num(); 
    return 0; 
}