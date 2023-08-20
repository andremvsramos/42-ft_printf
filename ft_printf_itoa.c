/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:34:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Convert an integer to a string representation.
 *
 * This function converts the integer `nbr` into a string representation.
 * The resulting string is dynamically allocated and must be freed after use.
 * The function handles negative and zero values appropriately.
 *
 * @param nbr   The integer to be converted to a string.
 * @return      A dynamically allocated string representation of the integer.
 *              It must be freed by the caller when no longer needed.
 */
char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = ft_abs(nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

/**
 * @brief Convert an unsigned integer to a string representation.
 *
 * This function converts the unsigned integer `nbr` into a string
 * representation. The resulting string is dynamically allocated and must be
 * freed after use. The function handles zero values appropriately.
 *
 * @param nbr   The unsigned integer to be converted to a string.
 * @return      A dynamically allocated string representation of the unsigned
 * integer. It must be freed by the caller when no longer needed.
 */
char	*ft_uitoa(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ft_ui_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = ft_abs(nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

/**
 * @brief Calculate the length of a string representation for an unsigned
 * integer.
 *
 * This function calculates the length of the string representation that an
 * unsigned integer `n` would have when converted to a string. It handles zero
 * values appropriately by returning a length of 1.
 *
 * @param n     The unsigned integer for which to calculate the string length.
 * @return      The length of the string representation.
 */
int	ft_ui_nbrlen(unsigned int n)
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
