/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:09:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output a character with optional padding.
 *
 * This function outputs the character `c` and supports optional padding based
 * on the provided flags and padding amount. The character can be either printed
 * before or after the padding, depending on the state of the flags. If the
 * `flags` array indicates the presence of padding, spaces are printed after the
 * character. The number of spaces is determined by the `ammount` field in the
 * `sc` structure.
 * If padding is not specified, the character is printed directly.
 *
 * @param c      The character to be output.
 * @param flags  An array of integer flags that control the behavior of the
 * function.
 * @param sc     A pointer to a structure that contains additional control data.
 */
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
