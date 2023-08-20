/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:45:46 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:17:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Handle formatting flags for printing pointers.
 *
 * This function handles formatting flags for printing pointers in a formatted
 * manner. It specifically manages the case where the minus flag is set
 * (`flags[5]`) and the width `n` is less than the specified amount
 * `sc->ammount`. In this case, the function adds padding spaces before the
 * pointer output to ensure alignment.
 *
 * @param flags  An array of integer flags controlling formatting options.
 * @param n      The specified width for formatting.
 * @param sc     A pointer to a structure that contains additional control data.
 */
void	ft_pointer_flags(int *flags, int n, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5])
		if (n < sc->ammount)
			while (i++ < sc->ammount - n - 2)
				ft_putchar(' ', sc);
}
