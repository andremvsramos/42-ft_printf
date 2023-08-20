/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:37:04 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:14:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Validate and handle numeric formatting flags.
 *
 * This function validates the combination of numeric formatting flags. It
 * checks for incompatible flag combinations and exits the program with an error
 * message if such combinations are found. Specifically, it checks for cases
 * where certain flags cannot be used together, such as '0' and '-', '+'
 * and '-', etc.
 *
 * @param flags   An array of integer flags controlling formatting options.
 * @return        Always returns 1 as a success indicator.
 */
int	ft_valid_flags_nbr(int *flags)
{
	if (flags[1] && flags[3] && flags[4] && flags[5])
	{
		ft_printf("Cannot input all flags at the same time...");
		exit (EXIT_FAILURE);
	}
	if (flags[1] && flags[5])
	{
		ft_printf("Cannot input '0' and '-' flags at the same time");
		exit (EXIT_FAILURE);
	}
	if (flags[5] && flags[4])
	{
		ft_printf("Don't input '-' and '+' together");
		exit (EXIT_FAILURE);
	}
	return (1);
}
/**
 * @brief Validate and handle string formatting flags.
 *
 * This function validates string formatting flags. It checks for the presence
 * of a specific flag and exits the program with an error message if that flag
 * is set.
 * The function specifically handles the case when the fourth flag is set,
 * indicating a behavior that should not be used.
 *
 * @param flags   An array of integer flags controlling formatting options.
 * @return        Always returns 1 as a success indicator.
 */
int	ft_valid_flags_str(int *flags)
{
	if (flags[4])
	{
		ft_printf("If you do this, program goes BOOM");
		exit (EXIT_FAILURE);
	}
	return (1);
}
