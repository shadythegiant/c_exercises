
#include <unistd.h>
int ft_strlen(char *string){
    int i = 0; 
    while(string[i]){ 
        i++; 
    }
    return (i); 
}

void fn(char ***string , int c) { 
    while(***string && ***string != c) {
        (**string)++; 
    }

    if(**string) { 
        write(1, **string, ft_strlen(**string)); 
    }
}


int main() { 
    char *string = "hello"; 
    char **pp =  &string; 
    char ***ppp = &pp; 

    fn(ppp, 'e'); 
    return 0; 
}