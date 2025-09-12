
#include <unistd.h>


void ft_putchar(char c) { 
 
     write(1,&c,1);    
    
}

char ft_rot13(char c) { 

    if(c >= 'a' && c <= 'z') { 
      c = (((c - 'a') + 13)  % 26 + 'a');    
    }
    
    if(c >= 'A' && c <= 'Z') { 
        c = (((c - 'A') + 13)  % 26 + 'A'); 
    }
    return c; 
}

void rotate_string(char *string) { 
     int i = 0;
     while(string[i]) { 
    
      ft_putchar(ft_rot13(string[i])); 
      i++; 
   }  
         
}

int main() {
char *string = "Rnpu cebwrpg va gur 42 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, jvgu n svany cevmr sbe bar fghqrag. Fgnss zrzoref znl cnegvpvcngr ohg ner abg ryvtvoyr sbe n cevmr. Ner lbh nzbat gur irel svefg gb fbyir n pvepyr? Fraq gur uvagf jvgu rkcynangvbaf gb by@42.se gb or nqqrq gb gur yrnqreobneq. Gur uvag sbe guvf svefg cebwrpg, juvpu znl pbagnva nantenzzrq jbeqf, vf: Jbys bs ntragvir cnegvpyrf gung qvfcebir terral gb lbhe ubzrf qan gung cebjfr lbhe fgbby" ;
   rotate_string(string);  
    return 0;
}