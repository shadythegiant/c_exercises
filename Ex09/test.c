#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main()
{
    char *src = "aoub";
    char dest[10] = "hola\n";
    
    // Using strncpy (standard C)
    strlcpy(dest, src, 1);
    
    printf("Copied: %s\n", dest);
    return 0;
}