char	*ft_strjoin(int size, char **strs, char *sep)
{
    char *empty_string;
	int		total_size;
	int		i;
	char	*result;
	int		result_index;
	char	*str;
	int		j;

	if (size == 0)
	{
		empty_string = malloc(sizeof(char) * 1);
		empty_string[0] = '\0';
		return (empty_string);
	}
	total_size = 0;
	i = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		i++;
	}
	total_size += ft_strlen(sep) * (size - 1);
	result = malloc(sizeof(char) * (total_size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	result_index = 0;
	while (i < size)
	{
		str = strs[i];
		j = 0;
		while (str[j])
		{
			result[result_index++] = str[j++];
		}
		j = 0;
		while (i < size - 1 && sep[j])
		{
			result[result_index++] = sep[j++];
		}
		i++;
	}
	result[result_index] = '\0';
	return (result);  } 
