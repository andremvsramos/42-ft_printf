/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:04:23 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:39:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Safely copies a source string to a destination buffer, ensuring null-termination.
 *
 * This function copies the contents of the source string `src` into the destination
 * buffer `dest`, up to a maximum of `size - 1` characters, and ensures that the
 * destination buffer is null-terminated. The total length of the source string is returned.
 *
 * @param dest Pointer to the destination buffer where the string will be copied.
 * @param src Pointer to the source string to be copied.
 * @param size Maximum number of characters to be copied, including the null-terminator.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = ft_strlen((char *)src);
	if (!size)
		return (c);
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}
