/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:17:51 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:40:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Compares two strings for equality up to a specified number of characters.
 *
 * This function compares the first `n` characters of the strings `s1` and `s2`.
 * If the characters are equal, the comparison continues. The function returns
 * a value less than, equal to, or greater than zero if `s1` is found to be
 * respectively less than, equal to, or greater than `s2`.
 *
 * @param s1 Pointer to the first string for comparison.
 * @param s2 Pointer to the second string for comparison.
 * @param n Number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if `s1` is found
 *         to be respectively less than, equal to, or greater than `s2`.
 */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
