/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:42:00 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:16:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Fill a memory block with a specified byte value.
 *
 * This function fills the memory block pointed to by `str` with the byte value
 * `c`. The size of the memory block is determined by the parameter `n`, which
 * specifies the number of bytes to be filled with the specified value `c`.
 *
 * @param str   Pointer to the memory block to be filled.
 * @param c     The byte value to be used for filling the memory block.
 * @param n     Number of bytes to fill with the specified byte value.
 * @return      Pointer to the filled memory block (`str`).
 */
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)str)[i++] = c;
	return (str);
}
