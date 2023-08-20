/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:17 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:13:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Handle hexadecimal formatting with specified flags.
 *
 * This function handles the formatting of hexadecimal numbers based on the
 * provided flags and settings. It delegates the formatting task to other
 * functions based on the presence of certain flags. Specifically, if the minus
 * flag is set, it calls the `ft_hex_minus` function to handle formatting.
 *
 * @param nbr     The hexadecimal number to be formatted.
 * @param f       The specific formatting option for the hexadecimal conversion.
 * @param flags   An array of integer flags controlling formatting options.
 * @param sc      A pointer to a structure that contains additional control data
 */
void	ft_hflags(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	if (flags[5])
		ft_hex_minus(nbr, f, flags, sc);
}

/**
 * @brief Handle hexadecimal formatting with minus flag.
 *
 * This function handles the formatting of hexadecimal numbers when the minus
 * flag is set. It formats the hexadecimal number and handles the alignment
 * based on the specified width. The width and alignment are controlled by
 * the `ammount` field in the `sc` structure. The function uses `ft_puthex`
 * to perform the actual formatting.
 *
 * @param nbr     The hexadecimal number to be formatted.
 * @param f       The specific formatting option for the hexadecimal conversion.
 * @param flags   An array of integer flags controlling formatting options.
 * @param sc      A pointer to a structure that contains additional control data
 */
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
