/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:51:53 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:28:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print an integer number with formatting options.
 *
 * This function prints the integer number `n` using recursion. It handles
 * special cases for the minimum integer value (-2147483648) and negative
 * numbers. It breaks down the number into its digits and prints them one by
 * one. The printing is done according to the formatting options stored in the
 * `t_sc` structure.
 *
 * @param n    The integer number to be printed.
 * @param sc   A pointer to a structure that contains additional control data.
 */
void	ft_putnbr(int n, t_sc *sc)
{
	if (n == -2147483648)
	{
		ft_putchar('-', sc);
		ft_putchar('2', sc);
		ft_putnbr(147483648, sc);
	}
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-', sc);
		ft_putnbr(n, sc);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, sc);
		ft_putnbr(n % 10, sc);
	}
	else
		ft_putchar(n + '0', sc);
}

/**
 * @brief Handle decimal number formatting, flags, and printing.
 *
 * This function handles the formatting, flags, and printing for a decimal
 * number. It applies various formatting options based on the provided flags,
 * such as minus, zero, plus, space, and width. It delegates specific flag
 * processing to helper functions according to the flag configuration. It
 * prints the formatted number and updates the length counter in the
 * `t_sc` structure.
 *
 * @param sc       A pointer to a structure that contains additional control
 * data.
 * @param flags    An array of integer flags controlling formatting options.
 * @param number   A pointer to the buffer containing the formatted number.
 */
static void	ft_putdecimal2(t_sc *sc, int *flags, char *number)
{
	if (flags[5])
		number = ft_process_minus_flag(nbr, number, flags, sc->ammount);
	if (flags[1])
		number = ft_process_zero_flag(sc->ammount, number, aux, flags[3]);
	if (flags[4])
		number = ft_process_plus_flag(nbr, number, flags, sc->ammount);
	if (flags[3] && !flags[1])
		number = ft_process_space_flag(number, nbr, sc->ammount);
	if (!flags[1] && !flags[2] && !flags[3] && !flags[4] && !flags[5])
		number = ft_no_num_flags(number, aux, sc->ammount);
	ft_putstr(number);
	sc->len += ft_strlen(number);
	free(number);
	free(aux);
}

/**
 * @brief Print a decimal integer with formatting options.
 *
 * This function prints a decimal integer `nbr` with various formatting options.
 * It takes into account flags like minus, zero, plus, space, and width. It
 * calculates the size of the buffer needed for the formatted number and handles
 * memory allocation. It delegates formatting, flag handling, and printing to
 * other functions based on the flag configuration.
 *
 * @param nbr      The decimal integer to be printed.
 * @param flags    An array of integer flags controlling formatting options.
 * @param sc       A pointer to a structure that contains additional control
 * data.
 */
void	ft_putdecimal(int nbr, int *flags, t_sc *sc)
{
	char	*number;
	char	*aux;
	int		i;
	int		size;

	i = 0;
	ft_valid_flags_nbr(flags);
	aux = ft_itoa(nbr);
	if (ft_nbrlen(nbr) > sc->ammount)
		size = ft_nbrlen(nbr);
	else
		size = sc->ammount;
	number = (char *)malloc(sizeof(char) * (size + 1));
	if (!number)
		return (free(number), );
	if(!sc->ammount)
	{
		ft_putnbr(nbr, sc);
		free(number);
		free(aux);
		return ;
	}
	ft_putdecimal2(sc, flags, number);
}
