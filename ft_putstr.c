/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelechg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:39:42 by abelechg          #+#    #+#             */
/*   Updated: 2024/04/02 02:40:03 by abelechg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	z;

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
