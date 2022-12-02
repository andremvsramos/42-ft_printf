/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:45:46 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/30 14:59:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_flags(int *flags, int n, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5])
		if (n < sc->ammount)
			while (i++ < sc->ammount - n - 2)
				ft_putchar(' ', sc);
}
