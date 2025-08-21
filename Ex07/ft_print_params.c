#include <unistd.h>

void ft_putchar(char c) {
    write(1,&c, 1); 
}



int main(int argc, char *argv[]) {
    
    int i , j; 

    i = 1; 


    while(argv[i] != NULL) { 
       j = 0; 
       while (argv[i][j] != '\0') { 
        ft_putchar(argv[i][j]);
        j++; 
       }
       ft_putchar('\n');
       i++; 
    }


}