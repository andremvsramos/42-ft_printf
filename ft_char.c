/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:30 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/30 11:27:24 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5])
		ft_putchar(c, sc);
	if (sc->ammount)
		while (++i < sc->ammount)
			ft_putchar(' ', sc);
	if (!flags[5])
		ft_putchar(c, sc);
}
