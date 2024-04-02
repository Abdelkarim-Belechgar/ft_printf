/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelechg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:41:48 by abelechg          #+#    #+#             */
/*   Updated: 2024/04/02 02:44:14 by abelechg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, int c)
{
	char	*hexa_a;
	char	*hexa_z;
	int		z;

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
