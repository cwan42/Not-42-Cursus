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
		if ((*str == '%') && ((*(str + 1) == 's') || \
			(*(str + 1) == 'd') || (*(str + 1) == 'x')))
		{
			str++;
			if (*str == 's')
				len += ft_putstr(va_arg(args, char *));				
			else if (*str == 'd')
			else if (*str == 'x')
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
