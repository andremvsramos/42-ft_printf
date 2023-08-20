/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:16:02 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:35:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Duplicate a null-terminated string.
 *
 * This function duplicates a null-terminated string `src` by allocating memory
 * for a new string and copying the contents of the source string into it. The
 * duplicated string is null-terminated. Memory is allocated for the new string
 * using malloc.
 *
 * @param src   The source null-terminated string to be duplicated.
 * @return      A pointer to the newly allocated duplicated string.
 *              Returns NULL if memory allocation fails.
 */
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
