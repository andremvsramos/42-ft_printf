/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:45:46 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:08:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Fill a memory block with zeros.
 *
 * This function fills the memory block pointed to by `dest` with zeros.
 * The memory block's size is determined by the parameter `n`, which specifies
 * the number of bytes to be filled with zeros.
 *
 * @param dest Pointer to the memory block to be filled with zeros.
 * @param n    Number of bytes to fill with zeros.
 */
void	ft_bzero(void *dest, size_t n)
{
	ft_memset(dest, 0, n);
}
