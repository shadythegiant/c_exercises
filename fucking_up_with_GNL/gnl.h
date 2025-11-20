#ifndef GNL_H
#define GNL_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 69
#endif 

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s); 
ssize_t	ft_strchr(const char *s, int c); 
char *ft_strndup(const char *s, size_t n); 
void *ft_cleanup(char **buffer); 

#endif