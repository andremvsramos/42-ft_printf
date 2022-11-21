/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:23:06 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/21 17:37:28 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	int		i;
	int		j;
	int		*v;
	int		flag;
	char	*line;

	i = 0;
	j = 0;
	/*Checking how many args we have*/
	while (s[i])
	{
		if (s[i] == '%')
			j++;
		i++;
	}

	/*Initialize valist for n args*/
		va_start(valist, s);

	/*Creating an array to keep the ascii values of type of data*/
	i = 0;
	v = (int *)malloc(sizeof(int) * j);
	if (!v)
		return (0);
	j = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (ft_check_flags(s[i]) != 0)
			{
				i++;
				while (ft_isdigit(s[i]))
					i++;
			}
			v[j++] = (int)s[i++];
		}
		i++;
	}

	/*Printing*/
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
		{
			i++;
			flag = ft_check_flags(s[i]);
			if (flag == 1)
			{
				i++;
				line = ft_zeros_to_print((char *)s, i, flag);
				while (ft_isdigit(s[i]))
					i++;
			}
			else if (flag == 4)
			{
				i++;
				if (s[i] == '0')
				{
					flag = 1;
					line = ft_zeros_to_print((char *)s, i, flag);
					line[0] = '+';
				}
				else
					line = ft_zeros_to_print((char *)s, i, flag);
				while (ft_isdigit(s[i]))
					i++;
			}
			i++;
			ft_check_data(v[j++], valist, flag, line);
		}
		i++;
	}

	/*Clean*/
	va_end(valist);

	return (i - j);
}
