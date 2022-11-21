/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:41:45 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/21 10:24:50 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(int nbr, int f)
{
	char	*base;

	if (f == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
			ft_puthex(nbr / 16, f);
			ft_puthex(nbr % 16, f);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putptr(unsigned long long int ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (!ptr && ptr != 0)
		write(1, "(nil)", 5);
	else
	{
		if (ptr >= 16)
		{
			ft_putptr(ptr / 16);
			ft_putptr(ptr % 16);
		}
		else
			ft_putchar(base[ptr]);
	}
}
