// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c ) { 
  write(1, &c, 1);    
}

void ft_putnbr(int num) { 
    long int nbr = num; 
    char digits[255]; 
    int counter = 0; 
    
    if( nbr < 0) { 
        ft_putchar('-'); 
        nbr = -nbr; 
    }
    
    if(nbr == 0) {
        ft_putchar('0'); 
        return; 
    }
    
    while (nbr > 0) { 
     
     digits[counter] = (nbr % 10) + '0'; 
     nbr /= 10; 
     counter++; 
    }
    
    counter = counter - 1; 
    while(counter >= 0) { 
        ft_putchar(digits[counter]);    
        counter--; 
    }
    
}

void printfre(char *word) { 

     int frquency[26][2]; 
     int printed[26] = {0}; 
     int counter = 0; 
    
    //initializing the array
    
    while(counter < 26) { 
        frquency[counter][0] = 'a' + counter; 
        frquency[counter][1] = 0; 
        counter++; 
    }
    
    // count frequencie 
    
    counter = 0;
    
    while(word[counter]) { 
        char c = word[counter]; 
        if(c >= 'A' && c <= 'Z') c = c + 32; 
        if(c >= 'a' && c <= 'z') { 
         frquency[c - 'a'][1]++;     
        }
        counter++; 
    }
    
    // print frequencies
    counter = 0; 
    while(word[counter]) { 
    char c = word[counter]; 
     
    
      if(c >= 'A' && c <= 'Z' ) c += 32; 
      if(c>= 'a' && c <= 'z') {
         int  index = c - 'a'; 
        if(!printed[index]) { 
         if(frquency[index][1] > 1) ft_putnbr(frquency[index][1]) ; 
          ft_putchar(c); 
         frquency[index][1] = 1; 
         printed[index] = 1;  }  
      }
      
     counter++; 
     }
      
}

int main() {
   
    char *string = "AAA"; 
    printfre(string); 
    return 0;
}

// hello 
