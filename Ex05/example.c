#include <stdlib.h>

char * ft_strdup(char *Str) {
    int i = 0;
    while (str[i])
        i++;

    char *buf = malloc(sizeof(int) * (i + 1))
    if (buf == NULL)
        return NULL;
    i = 0;
    while (str[i]) {
        buf[i] = str[i];
        i++;
    }
    buf[i] = '\0';
    return buf;
}

char *ft_strjoin(char *str1, char *str2) {
    return (NULL);
}

int main() {
    char *dup = ft_strjoin("Hello World", "my name is mint");
    if (dup == NULL)
        return 0;
    printf("%s\n", dup);
    free(dup);
}