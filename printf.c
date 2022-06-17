#include <unistd.h>
#include <stdarg.h>

int	g_var = 0;

void	ft_putnbr(long dig, int len, char *sign)
{
	if (dig >= len)
		ft_putnbr(dig / len, len, sign);
	write(1, sign[dig % len], 1);
	g_var++;
}

void	ft_puthex(unsigned dig, unsigned len, char *sign)
{
	if (dig >= len)
		ft_puthex(dig / len, len, sign);
	write(1, sign[dig % len], 1);
	g_var++;
}

int	ft_printf(const char *format, ...)
{
	g_var = 0;
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format = '%')
		{
			format++;
			if (*format == 's')
			{
				int	len = 0;
				char	*str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				g_var += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long d = va_arg(ap, int);
				if (d < 0)
				{
					write(1, "-", 1);
					g_var++;
					d = -d;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*format == "x")
			{
				int x = va_arg(ap, int);
				ft_puthex(x, 16, "0123456789abcdef");
			}
			*format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}