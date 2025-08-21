#include <unistd.h>
#include <stdio.h>


void ft_putchar(char c) {
    write(1,&c, 1); 
}


int main(int argc, char *argv[]) { 
    int outer; 
    int inner; 


    

    outer = argc - 1; //3

    while(outer > 0 ) { 

        inner = 0; 

        while (argv[outer][inner]) { 
            ft_putchar(argv[outer][inner]); 
            inner++; 
        }

        outer--; 
        ft_putchar('\n'); 
    }

}