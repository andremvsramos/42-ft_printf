/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:12:52 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print a single character and update the length counter.
 *
 * This function prints the character `c` using the write function and updates
 * the length counter in the `t_sc` structure to track the number of characters
 * printed.
 *
 * @param c    The character to be printed.
 * @param sc   A pointer to a structure that contains additional control data.
 * @return     The number of characters printed (always 1 for a single
 * character).
 */
int	ft_putchar(char c, t_sc *sc)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	sc->len++;
	return (1);
}

/**
 * @brief Calculate the absolute value of an integer.
 *
 * This function calculates and returns the absolute value of the integer `nbr`.
 *
 * @param nbr   The integer for which to calculate the absolute value.
 * @return      The absolute value of the input integer.
 */
int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

/**
 * @brief Calculate the length of a string representation for an integer.
 *
 * This function calculates the length of the string representation that an
 * integer `n` would have when converted to a string. It handles zero and
 * negative values appropriately by returning a length of 1 for such cases.
 *
 * @param n     The integer for which to calculate the string length.
 * @return      The length of the string representation.
 */
int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

/**
 * @brief Print a string and return the number of characters printed.
 *
 * This function prints the string `str` using the write function and returns
 * the number of characters printed. The string length is determined using a
 * loop.
 *
 * @param str   The string to be printed.
 * @return      The number of characters printed.
 */
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

/**
 * @brief Print an unsigned integer with formatting options.
 *
 * This function prints an unsigned integer `nbr` with various formatting
 * options. It takes into account flags like minus, width, and precision. It
 * calculates the size of the buffer needed for the formatted number and handles
 * memory allocation. It prints the formatted number and updates the length
 * counter in the `t_sc` structure.
 *
 * @param nbr      The unsigned integer to be printed.
 * @param flags    An array of integer flags controlling formatting options.
 * @param sc       A pointer to a structure that contains additional control
 * data.
 */
void	ft_putunsigned(unsigned int nbr, int *flags, t_sc *sc)
{
	char	*uns_int;
	int		i;

	i = 0;
	uns_int = ft_uitoa(nbr);
	if (!flags[5])
		ft_putstr(uns_int);
	else
	{
		ft_putstr(uns_int);
		while (i++ < sc->ammount - ft_strlen(uns_int))
			ft_putchar(' ', sc);
	}
	sc->len += ft_strlen(uns_int);
	free(uns_int);
}
