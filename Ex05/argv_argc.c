#include <stdio.h>
#include <unistd.h>

/* 
1. argc - Argument Count
Type: int (integer)

Meaning: The number of arguments passed to the program.

Key Point: The program name itself counts as the first argument. So, argc is always at least 1.


2. argv - Argument Vector
Type: char *argv[] (Array of strings / array of character pointers)

Meaning: An array where each element is a string containing one of the command-line arguments.

Key Points:

argv[0] always contains the name of the program.

argv[1] is the first real argument you typed.

argv[argc - 1] is the last argument.

argv[argc] is guaranteed to be NULL (a special pointer meaning "nothing").

*/


int main(int argc,  char *argv[], char *env[] ) { 

    

    printf("env of argumen is %s\n ", env[1]);
    // char explorer = '@'; 
    // char *explorerPointer = &explorer; 

    // while(1) { 

    //     if(*explorerPointer == '\0') write(1,"\n", 1); 
    //     write(1, explorerPointer++, 1); 
    // }


}