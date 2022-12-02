/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:37:04 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/29 13:32:24 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_valid_flags_nbr(int *flags)
{
	if (flags[1] && flags[3] && flags[4] && flags[5])
	{
		ft_printf("Cannot input all flags at the same time... idiot...");
		exit (EXIT_FAILURE);
	}
	if (flags[1] && flags[5])
	{
		ft_printf("Cannot input '0' and '-' flags at the same time");
		exit (EXIT_FAILURE);
	}
	if (flags[5] && flags[4])
	{
		ft_printf("Fucking idiot... Don't input '-' and '+' together");
		exit (EXIT_FAILURE);
	}
	return (1);
}

int	ft_valid_flags_str(int *flags)
{
	if (flags[4])
	{
		ft_printf("If you do this, program goes BOOM");
		exit (EXIT_FAILURE);
	}
	return (1);
}
