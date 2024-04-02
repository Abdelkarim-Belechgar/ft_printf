/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelechg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:47:50 by abelechg          #+#    #+#             */
/*   Updated: 2024/04/02 02:48:14 by abelechg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		z;
	int		len;

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
