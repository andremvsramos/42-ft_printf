/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:35 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:41:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int		total, totalog;

	total = ft_printf("FT %-1X \n", 0);
	totalog = printf("OG %-1X \n", 0);
	printf("\n");
	printf("OG    PRINTED: %d\n", totalog);
	printf("TOTAL PRINTED: %d\n", total);
	return 0;
}
