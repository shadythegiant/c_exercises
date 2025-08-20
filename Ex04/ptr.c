#include <stdio.h>

int my_arrary[] = {1,2,3,4}; 
int *ptr; 
int size; 


int main(void) {

    int i; 
    size = sizeof(my_arrary) / sizeof(my_arrary[0]); 
    
    ptr = &my_arrary[0]; 

    for(i = 0; i < size; i++ ) { 
        printf("my_array[%d] = %3d\t",i,my_arrary[i]);
         printf("ptr + %d = %3d\n",i, *(ptr + i));
    }
}