/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:17 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 12:06:38 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hflags(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	if (flags[5])
		ft_hex_minus(nbr, f, flags, sc);
}

void	ft_hex_minus(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	int		i;
	char	*aux;

	i = 0;
	aux = ft_uitoa(nbr);
	if (!flags[5])
		ft_puthex(nbr, f, flags, sc);
	else
	{
		ft_puthex(nbr, f, flags, sc);
		while (i++ < sc->ammount - sc->hex_size)
			ft_putchar(' ', sc);
	}
	free(aux);
}
