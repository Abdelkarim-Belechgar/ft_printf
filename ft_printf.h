/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelechg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:49:54 by abelechg          #+#    #+#             */
/*   Updated: 2024/04/02 02:54:42 by abelechg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putnbr(long nbr);
int	ft_puthexa(unsigned long nbr, int c);
int	ft_putchar(int c);
int	ft_printf(const char *str, ...);
int	ft_print(char str, va_list ap);

#endif
