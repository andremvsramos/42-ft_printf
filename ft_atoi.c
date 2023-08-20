/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:38 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:08:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Convert a string representation of an integer to an integer value.
 *
 * This function takes a string `str` and converts it into an integer value.
 * It skips leading whitespace characters, handles the sign (+/-) of the number,
 * and processes valid digit characters to calculate the integer value.
 * The ASCII digit characters are converted to their corresponding integer
 * values using a simple calculation. The function uses a loop to iterate over
 * the characters of the string until a non-digit character is encountered.
 * The final integer result is then multiplied by the determined sign and
 * returned.
 *
 * @param str Pointer to the input string to be converted.
 * @return The integer value represented by the input string.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
