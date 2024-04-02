#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	int	z;

	z = 0;
	if (c != '\0')
	{
		write(1, &c, 1);
		z++;
	}
	return (z);
}

int	ft_putstr(char *str)
{
	int z;

	z = 0;
	if (!str)
		str = "(null)";
	while (str && str[z])
	{
		ft_putchar(str[z]);
		z++;
	}
	return (z);
}

int	ft_putnbr(long nbr)
{
	int	z;

	z = 0;
	if (nbr < 0)
	{
		z += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		z += ft_putnbr(nbr / 10);
	z += ft_putchar((nbr % 10) + 48);
	return (z);
}

int	ft_puthexa(unsigned long nbr, int c)
{
	char	*hexa_a;
	char	*hexa_z;
	int	z;

	z = 0;
	hexa_a = "0123456789abcdef";
	hexa_z = "0123456789ABCDEF";
	if (c == 'X')
		hexa_a = hexa_z;
	if (nbr >= 16)
		z += ft_puthexa(nbr / 16, c);
	z += ft_putchar(hexa_a[nbr % 16]);
	return (z);
}

int	ft_print(char str, va_list ap)
{
	int	len;

	len = 0;
	if (str == '%')
		len += ft_putchar('%');
	else if (str == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		len += ft_putstr(va_arg(ap, char*));
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (str == 'u')
		len += ft_putnbr(va_arg(ap, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_puthexa(va_arg(ap, unsigned int), str);
	else if (str == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexa(va_arg(ap, unsigned long), str);
	}
	else
        len += ft_putchar(str);
	if (str)
		len += 1;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	z;
	int len;

	z = 0;
	len = 0;
	va_start(ap, str);
	while (str[z])
	{
		if (str[z] == '%')
		{
			if (str[z + 1])
				len += ft_print(*(str + z + 1), ap);
			z++;
		}
		else
			len += ft_putchar(str[z]);
		z++;
	}
	va_end(ap);
	return (len);
}

int main(void)
{
	char	*str;

	str = "dshhfdsghsdhf";
	ft_printf("hello = %zk\n", str);
	printf("hello = %zk\n", str);
}
