#include <unistd.h>

#define SIZE 5


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *string)
{
	while (*string)
	{
		ft_putchar(*string);
		string++;
	}
}

void	ft_punbr(int num)
{
	char		c;
	long int	nbr;

	nbr = num;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		nbr = nbr / 10;
	}
	c = (nbr % 10) + '0';
	ft_putchar(c);
}

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void	swap_array(int *arr1, int *arr2)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_swap(&arr1[i], &arr2[i]);
		i++;
	}
}

void	printArray(int *arr)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_punbr(arr[i]);
		i++;
	}
}

int	main(void)
{
	int array1[SIZE] = {1, 2, 3, 4, 5};
	int array2[SIZE] = {5, 4, 3, 2, 1};
	swap_array(array1, array2);
	ft_putchar('\n');
	ft_putstr("this is array 1");
	printArray(array1);
	ft_putchar('\n');
	ft_putstr("this is array 2");
	printArray(array2);
	ft_putchar('\n');

	return (0);
}