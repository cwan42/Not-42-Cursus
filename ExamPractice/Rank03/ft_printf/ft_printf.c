#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i = 0;

	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		len = 0;
	va_list	args;

	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				len += ft_putstr(va_arg(args, char *));
			if (*str == 'd')
				len += ft_putnbr(va_arg(args, int), 10);
			if (*str == 'x')
				len += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			len += write(1, &*str, 1);
		str++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[200];
	int		nbr;
	int		i;
	int		i2;
	int		len = 0;

	while (1)
	{
		printf("Enter a string or number, or type END to end the program: ");
		scanf("%199s", str);
		if (strncmp(str, "END", 4) == 0)
			break ;
		ft_printf("Whole str: %s\n"
		nbr = atoi(str);
		ft_printf("Char:%c\tString:%s\n", *str, str);
		printf("Real:%c\tReal: %s\n", *str, str);
		ft_printf("Pointer\t%p", str);
		printf(" : %p\n", str);
		ft_printf("Decimal\t%d", nbr);
		printf(" : %d\n", nbr);
		ft_printf("Integer\t%i", nbr);
		printf(" : %i\n", nbr);
		ft_printf("Unsign\t%u", ((unsigned int)nbr));
		printf(" : %u\n", ((unsigned int)nbr));
		ft_printf("Hex x:%x\t X: %X\n", nbr, nbr);
		printf("Real: %x\t X: %X\n", nbr, nbr);
		ft_printf("%%\t%%");
		printf(" : %%\n\n");
	}
}
