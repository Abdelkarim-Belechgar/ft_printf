#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>

// Helper function to print numbers in different bases
int ft_putnbr(ssize_t nbr, int base, int is_hex)
{
    int res = 0;
    const char *digits = is_hex ? "0123456789abcdef" : "0123456789";

    if (base == 10 && nbr < 0)
	{
		res += write(1, "-", 1);
		nbr = -nbr;
    }
    if (nbr >= base)
        res += ft_putnbr(nbr / base, base, is_hex);
    res += write(1, &digits[nbr % base], 1);
    return res;
}

// Function to print strings and handle format specifiers
int ft_putstr(const char *str, va_list ap)
{
	int res;

	res = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			if (*str == 's')
			{
				char *arg = va_arg(ap, char *);
				if (arg == NULL)
					arg = "(null)";
				res += write(1, arg, strlen(arg));
            }
			else if (*str == 'd')
				res += ft_putnbr(va_arg(ap, int), 10, 0);
            else if (*str == 'x')
				res += ft_putnbr(va_arg(ap, unsigned int), 16, 1);
            else if (*str == '%')
				res += write(1, "%", 1);
        }
		else
            res += write(1, str, 1);
        str++;
    }
    return res;
}

// Main printf function
int ft_printf(const char *str, ...)
{
    va_list ap;
    int res;

    va_start(ap, str);
    res = ft_putstr(str, ap);
    va_end(ap);
    return res;
}
