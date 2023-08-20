/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:05 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:12:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Process and format negative numbers with a minus flag.
 *
 * This function processes negative numbers with the minus flag. It handles
 * formatting and alignment of the number string within the specified width.
 * If the width `n` is greater than the length of the numeric string, the
 * function pads the string with spaces to ensure proper alignment.
 *
 * @param nbr     The negative number to be formatted.
 * @param number  The resulting formatted number string.
 * @param flags   An array of integer flags controlling formatting options.
 * @param n       The specified width for formatting.
 * @return        The formatted number string.
 */
char	*ft_process_minus_flag(int nbr, char *number, int *flags, int n)
{
	int		i;
	int		j;
	int		x;
	char	*aux;

	aux = ft_itoa(nbr);
	i = 0;
	x = 0;
	j = 0;
	if (nbr < 0)
	{
		number[i++] = '-';
		j++;
	}
	flags[3] = 0;
	if (!n)
		return (aux);
	if (n < ft_strlen(aux))
		while (aux[j])
			number[i++] = aux[j++];
	else
		while (aux[j])
			number[i++] = aux[j++];
		while (i < n)
			number[i++] = ' ';
	flags[1] = 0;
	number[i] = '\0';
	free(aux);
	return (number);
}

/**
 * @brief Process and format numbers with a zero flag.
 *
 * This function processes numbers with a zero flag. It formats the numeric
 * string by padding zeros or spaces as required by the specified width. The
 * numeric string is copied from the `aux` buffer to the `number` buffer, and
 * formatting is applied based on the length and flags.
 *
 * @param n       The specified width for formatting.
 * @param number  The resulting formatted number string.
 * @param aux     The original numeric string to be formatted.
 * @param flag3   Flag indicating whether a space flag is set.
 * @return        The formatted number string.
 */
char	*ft_process_zero_flag(int n, char *number, char *aux, int flag3)
{
	int	i;

	i = 0;
	n -= ft_strlen(aux);
	ft_memset(number, '0', n);
	if (aux[i] == '-')
	{
		number[i] = '-';
		i++;
		n++;
	}
	else if (flag3)
		number[i] = ' ';
	while (aux[i])
		number[n++] = aux[i++];
	number[n] = '\0';
	if (*number)
		return (number);
	return (0);
}

/**
 * @brief Process and format numbers with a plus flag.
 *
 * This function processes numbers with a plus flag. It formats the numeric
 * string by aligning it within the specified width `n`, and optionally
 * prepends a plus sign or the original sign character. The result is a
 * formatted number string.
 *
 * @param nbr     The number to be formatted.
 * @param number  The resulting formatted number string.
 * @param flags   An array of integer flags controlling formatting options.
 * @param n       The specified width for formatting.
 * @return        The formatted number string.
 */
char	*ft_process_plus_flag(int nbr, char *number, int *flags, int n)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_itoa(nbr);
	if (!flags[1])
		ft_memset(number, ' ', n);
	if (flags[1])
	{
		if (nbr > 0)
			number[0] = '+';
		else
			number[0] = aux[0];
	}
	else if (!flags[1])
	{
		while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	}
	number[n] = '\0';
	flags[3] = 0;
	return (number);
}

/**
 * @brief Process and format numbers with a space flag.
 *
 * This function processes numbers with a space flag. It formats the numeric
 * string by aligning it within the specified width `n`, and optionally prepends
 * a space character. The result is a formatted number string.
 *
 * @param number  The resulting formatted number string.
 * @param nbr     The number to be formatted.
 * @param n       The specified width for formatting.
 * @return        The formatted number string.
 */
char	*ft_process_space_flag(char *number, int nbr, int n)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_itoa(nbr);
	ft_memset(number, ' ', n);
	while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	return (number);
}

/**
 * @brief Format and align strings without numeric flags.
 *
 * This function handles the formatting of numeric strings without any numeric
 * flags. It formats and aligns the given string `aux` within the specified
 * width `n`. The result is a formatted string that can include padding spaces
 * or be truncated based on the specified width and length of `aux`.
 *
 * @param number  The resulting formatted string.
 * @param aux     The original string to be formatted.
 * @param n       The specified width for formatting.
 * @return        The formatted string.
 */
char	*ft_no_num_flags(char *number, char *aux, int n)
{
	int	i;

	i = 0;
	if (ft_strlen(aux) > n)
	{
		while (aux[i])
		{
			number[i] = aux[i];
			i++;
		}
	}
	else if (n)
	{
		ft_memset(number, ' ', n);
		while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	}
	else
	{
		while (aux[i])
			number[n++] = aux[i++];
	}
	number[n] = '\0';
	return (number);
}
