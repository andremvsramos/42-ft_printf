/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:41:45 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 12:06:10 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	char	*base;
	int		n;

	n = 0;
	if (f == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (flags[2])
	{
		ft_printf("%c%c", base[0], (base[10] + 23));
		sc->len += 2;
	}
	flags[2] = 0;
	if (nbr >= 16)
	{
		n += ft_puthex(nbr / 16, f, flags, sc);
		n += ft_puthex(nbr % 16, f, flags, sc);
	}
	else
	{
		n += ft_putchar(base[nbr], sc);
		sc->hex_size++;
	}
	return (n);
}

void	ft_putptr(unsigned long long ptr, int *flags, t_sc *sc)
{
	char	*base;
	int		n;

	flags[2] = 1;
	base = "0123456789abcdef";
	if(!ptr)
	{
		write(1, "(nil)", 5);
		sc->len += 5;
		return ;
	}
	else
		n = ft_puthex(ptr, 0, flags, sc);
	ft_pointer_flags(flags, n, sc);
}

void	ft_print_0x(int *f, int str_len, t_sc *sc)
{
	*f = 1;
	ft_print_ammount(str_len, sc);
	write(1, "0x", 2);
	sc->len += 2;
}

void	ft_print_ammount(int n, t_sc *sc)
{
	while (n-- > 1)
	{
		ft_putchar(' ', sc);
	}
}

void	ft_print_spaces_before(int min, int max, t_sc *sc)
{
	while (min < max)
	{
		ft_putchar(' ', sc);
		min++;
	}
}
