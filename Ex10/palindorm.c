#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	checkPalindrom(char *string)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(string) - 1;
	while (start < end)
	{
		while ((string[start] >= 9 && string[start] <= 13)
			|| string[start] == 32)
			start++;
		while ((string[end] >= 9 && string[end] <= 13) || string[end] == 32)
			end--;
		if (string[start] != string[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}
int	main(void)
{
	printf("%d\n", checkPalindrom("   madam")); // 1
	printf("%d\n", checkPalindrom("racecar"));  // 1
	printf("%d\n", checkPalindrom("hello"));    // 0
	return (0);
}