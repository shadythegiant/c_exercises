#include <unistd.h>

void ft_putchar (char c) {
    write(1, &c, 1); 
}

void ft_putstr(char *s) { 
    while(*s) {
        ft_putchar(*s); 
        s++; 
    }
}

void ft_putnbr(int n){
    long int nbr = n; 
    int i = 0; 
    char digits[1000]; 

    if(nbr < 0) { 
        ft_putchar('-'); 
        nbr = - nbr; 
    }

    if (nbr == 0) {
        ft_putchar('0'); 
        return; 
    }
    while(nbr) { 
        digits[i] = (nbr  % 10) + '0'; 
        nbr = nbr / 10; 
        i++; 
    }
    i = i - 1;
    while(i >= 0) { 
        ft_putchar(digits[i]); 
        i--; 
    } 
} 


int mnt_absdiff(int n) {
    int abs =  52 - n; 
    if( abs < 0) {
        abs = abs * -1; 
    }

    return (abs > 52 ? (abs * 3) : abs); 
}

int main() { 
    ft_putnbr(mnt_absdiff(105)); 
}