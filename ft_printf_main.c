/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:35 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 12:09:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	/*char	*i = "42 Porto";
	int		a = 2, hex = 3, u = -12;*/
	int		total, totalog;

	total = ft_printf("FT %-1X \n", 0);
	totalog = printf("OG %-1X \n", 0);
	printf("\n");
	//printf(" NULL %s NULL ", NULL);
	//total = ft_printf("NULL %s NULL", NULL);
	printf("OG    PRINTED: %d\n", totalog);
	printf("TOTAL PRINTED: %d\n", total);
	return 0;
}
