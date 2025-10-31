static char	*ft_concat(size_t size, char const **strings, char *result)
{
	size_t		count;
	size_t		result_index;
	size_t		inner_c;
	char const	*str;

	count = 0;
	result_index = 0;
	while (count < size)
	{
		inner_c = 0;
		str = strings[count];
		while (str[inner_c])
		{
			result[result_index++] = str[inner_c++];
		}
		count++;
	}
	result[result_index] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	size_t		arr_size;
	char		*result_s;
	char const	*strings[2];

	size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
	{
		result_s = malloc(sizeof(char) * 1);
		result_s[0] = '\0';
		return (result_s);
	}
	strings[0] = s1;
	strings[1] = s2;
	arr_size = sizeof(strings) / sizeof(strings[0]);
	result_s = malloc(sizeof(char) * (size + 1));
	if (!result_s)
		return (NULL);
	result_s = ft_concat(arr_size, strings, result_s);
	return (result_s);
}
