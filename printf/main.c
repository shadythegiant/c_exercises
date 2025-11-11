// Online C compiler to run C program online
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ft_strlen()

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

//
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

//
int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

//

int	ft_putnbr(int n)
{
	char	buffer[25];
	long	nbr;
	int		count;
	int		i;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr == 0)
		return (count += ft_putchar('0'));
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

//

int	ft_putunbr(unsigned int n)
{
	char	buffer[10];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (n == 0)
		return (count += ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i > 0)
	{
		count += ft_putchar(buffer[--i]);
	}
	return (count);
}

//

int	ft_print_hex(unsigned long n, int uppecase)
{
	char	buffer[25];
	char	*symbols;
	int		count;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	if (uppecase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	i = 0;
	count = 0;
	while (n > 0)
	{
		buffer[i++] = symbols[n % 16];
		n = n / 16;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

//
int	ft_putptr(void *p)
{
	if (p == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_print_hex((unsigned long)p, 0));
}

//
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


int	ft_print_format(va_list ap, char **format, char specifier)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), specifier == 'X');
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	// We've processed % and the specifier, so advance past both
	(*format) += 2;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*specifier;
	char	*s;

	if (!format)
		return (-1);
	s = (char *)format;
	va_start(ap, format);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '\0')
				count += write(1, s++, 1);
			else
			{
				specifier = ft_strchr("cspdiuxX%", *(s + 1));
				if (specifier)
					count += ft_print_format(ap, &s, *specifier);
				else
					count += write(1, s++, 1);
			}
		}
		else
			count += write(1, s++, 1);
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	// Write C code here
	ft_printf("hello %d \n", 1000);
	return (0);
}