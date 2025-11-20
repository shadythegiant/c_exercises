#include "gnl.h"

static char	*ft_extract_line(char **buffer, size_t index)
{
	char	*buffer_cpy;
	char	*tmp;
	size_t	i;

	buffer_cpy = *buffer;
	i = 0;
	tmp = ft_strndup(buffer_cpy, index);
	if (!tmp)
		return (ft_cleanup(buffer));
	while (buffer_cpy[index])
		buffer_cpy[i++] = buffer_cpy[index++];
	buffer_cpy[i] = '\0'; 
	return (tmp);
}

static char	*ft_realloc_buffer(char **buffer, size_t occupied_size)
{
	char			*new_buffer;
	unsigned long	converted_bufsize;
	size_t			i;

	converted_bufsize = (unsigned long)BUFFER_SIZE;
	i = 0;
	new_buffer = (char *)malloc(converted_bufsize + occupied_size + 1);
	if (!new_buffer)
		return (ft_cleanup(buffer));
	while ((*buffer)[i])
	{
		new_buffer[i] = (*buffer)[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(*buffer);
	*buffer = new_buffer;
	return (new_buffer);
}

static char	*ft_read_until_newline(int fd, char **buffer)
{
	size_t		occupied_size;
	ssize_t		newline_index;
	ssize_t		bytes; 

	if((*buffer)[0] == '\0' ) {
		bytes = read(fd, *buffer, BUFFER_SIZE); 
		if(bytes <= 0)
			return ft_cleanup(buffer); 
		(*buffer)[bytes] = '\0'; 	
	}
	newline_index = ft_strchr(*buffer, '\n');
	while (newline_index == -1)
	{
		occupied_size = ft_strlen(*buffer);
		if (!ft_realloc_buffer(buffer, occupied_size))
			return (ft_cleanup(buffer));
		bytes = read(fd, *buffer + occupied_size, BUFFER_SIZE);
		(*buffer)[occupied_size + bytes] = '\0';
		if (bytes == 0)
			return (ft_extract_line(buffer, occupied_size));
		if (bytes == -1)
			return (ft_cleanup(buffer));
		newline_index = ft_strchr(*buffer, '\n');
	}
	return (ft_extract_line(buffer, newline_index + 1));
}

char	*gnl(int fd)
{
	static char *buffer;
	unsigned long converted_bufsize;
	int bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	converted_bufsize = (unsigned long)BUFFER_SIZE;
	bytes = 0;
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (converted_bufsize + 1));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	
	return (ft_read_until_newline(fd, &buffer));
}