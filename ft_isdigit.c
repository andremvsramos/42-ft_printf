/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:09:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:15:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Check if a character represents a digit.
 *
 * This function determines whether the given character `c` represents a digit
 * in the ASCII character set. It returns a non-zero value (true) if the
 * character is a digit (0-9), and 0 (false) otherwise.
 *
 * @param c   The character to be checked.
 * @return    Non-zero if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
