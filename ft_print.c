/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelechg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:43:08 by abelechg          #+#    #+#             */
/*   Updated: 2024/04/02 02:43:31 by abelechg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char str, va_list ap)
{
	int	len;

	len = 0;
	if (str == '%')
		len += ft_putchar('%');
	else if (str == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		len += ft_putstr(va_arg(ap, char *));
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
	return (len);
}
