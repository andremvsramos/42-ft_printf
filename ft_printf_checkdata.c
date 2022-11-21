/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:27 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/21 17:05:39 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_data(int ptr, va_list valist, int flag, char *line)
{
	if (ptr == 99) //%c
		ft_putchar(va_arg(valist, int));
	else if (ptr == 115) //%s
		ft_putstr(va_arg(valist, char *));
	else if (ptr == 112) //%p
	{
		write(1, "0x", 2);
		ft_putptr(va_arg(valist, long long int));
	}
	else if (ptr == 100 || ptr == 105) //%d || %i
		ft_putdecimal(va_arg(valist, int), flag, line);
	else if (ptr == 117) //%u
		ft_putunsigned(va_arg(valist, unsigned int));
	else if (ptr == 120) //%x
		ft_puthex(va_arg(valist, int), 0);
	else if (ptr == 88) //%X
		ft_puthex(va_arg(valist, int), 1);
	else if (ptr == 37) //%%
		ft_putchar('%');
}

int	ft_check_flags(char c) //State machine
{
	if (c == '0')
		return (1);
	else if (c == '#')
		return (2);
	else if (c == ' ')
		return (3);
	else if (c == '+')
		return (4);
	return (0);
}
