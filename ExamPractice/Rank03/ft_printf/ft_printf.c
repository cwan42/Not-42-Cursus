#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
			i += write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(long num, int base)
{
	char	*str;
	int		i;

	str = "0123456789abcdef";
	i = 0;
	if (num < 0)
	{
		i += write(1, "-", 1);
		num = -num;
	}
	if (num >= base)
		i += ft_putnbr(num / base, base);
	i += write(1, &str[num % base], 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i = 0;
	int		len = 0;
	va_list	args;

	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				len += ft_putstr(va_arg(args, char *));
			if (str[i] == 'd')
				len += ft_putnbr(va_arg(args, int), 10);
			if (str[i] == 'x')
				len += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[200];
	int		nbr;
	int		len = 0;

	while (1)
	{
		printf("Enter a string or number, or type END to end the program: ");
		scanf("%199s", str);
		if (strncmp(str, "END", 4) == 0)
			break ;
		len = ft_printf("str: %s, ", str);
		printf("len is: %d\n", len - 7);
		nbr = atoi(str);
		printf("Real:%s\n", str);
		ft_printf("Decimal\t%d", nbr);
		printf(" : %d\n", nbr);
		ft_printf("Hex:\t%x", nbr);
		printf(" : %x\n", nbr);
	}
}*/
