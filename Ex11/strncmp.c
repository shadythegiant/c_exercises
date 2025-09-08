int ft_strcmp(char *string1, char *string2) {

    int i; 
    i = 0; 

    while(string1[i] && string1[i] == string2[i]) {

        i++; 

    }

    return (string1[i] -string2[i]);
}


int st_strncmp(char *string1, char *string2, unsigned int n) {

    unsigned int i  = 0; 


    while( i < n && string1[i] && string1[i] == string2[i]) { 
        i++; 
    }

    if (n == i) return 0; 
    return(string1[i] - string2[i]); 
}


char ft_strcat(char *dest, char *src) { 

     int i = 0; 
     while(dest[i] != '\0') {

        i++; 
     }

     int j = 0; 

     while(src[j] != '\0') { 

        dest[i] = src[j]; 
        i++; 
        j++; 
     } 

     dest[i] = '\0'; 
     return (dest); 
}


char ft_strncat(char *dest, char *src, unsigned int size) { 
     int i = 0; 
     while(dest[i] != '\0') {

        i++; 
     }

     int j = 0; 

     while(src[j] != '\0' && j < size ) { 

        dest[i] = src[j]; 
        i++; 
        j++; 
     } 

     dest[i] = '\0'; 
     return (dest); 
}


 int ft_strlen(char *string) { 
        char *start = string; 
        while(*string) { 
            string++; 
        }

        return(string - start); 
    }

char	*ft_strstr(char *str, char *to_find)
{   
    int i; 
    int j; 

    if(!to_find || *str =='\0' ) { 
        return str; 
    }

    int len = ft_strlen(to_find); 
    i = 0; 
    while(str[i]) {

        j = 0; 
        while (str[i + j] && to_find[j] && str[i + j] == to_find[j]) 
        {
            j++; 
        }
        if(j == len) 
        {
            return (&str); 
        }
        i++; 
    }
    return (0);   
}


