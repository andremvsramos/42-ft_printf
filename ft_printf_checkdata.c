/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:27 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 11:59:25 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_data(int ptr, va_list valist, t_sc *sc, int *flags)
{
	if (ptr == 99)
		ft_char(va_arg(valist, unsigned int), flags, sc);
	else if (ptr == 115)
		ft_strings(va_arg(valist, char *), flags, sc);
	else if (ptr == 112)
		ft_putptr(va_arg(valist, unsigned long long), flags, sc);
	else if (ptr == 100 || ptr == 105)
		ft_putdecimal(va_arg(valist, int), flags, sc);
	else if (ptr == 117)
		ft_putunsigned(va_arg(valist, unsigned int), flags, sc);
	else if (ptr == 120)
		ft_hflags(va_arg(valist, unsigned int), 0, flags, sc);
	else if (ptr == 88)
		ft_hflags(va_arg(valist, unsigned int), 1, flags, sc);
	else if (ptr == 37)
		ft_putchar('%', sc);
	ft_bzero(flags, 256);
}

int	ft_is_flag(char c)
{
	return (c == '0' || c == '#'
		|| c == ' ' || c == '+' || c == '-' || c == '.');
}

int	ft_check_flags(char c, char *str, int *result)
{
	int	i;

	i = 0;
	if (c == '0')
		i = 1;
	else if (c == '#')
		i = 2;
	else if (c == ' ')
		i = 3;
	else if (c == '+')
		i = 4;
	else if (c == '-')
		i = 5;
	else if (c == '.')
		i = 6;
	*result = ft_ammount(str);
	return (i);
}

int	ft_ammount(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	return (res);
}
