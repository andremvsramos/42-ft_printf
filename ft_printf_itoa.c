/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:34:31 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/21 17:35:21 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = ft_abs(nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_zeros_to_print(char	*str, int index, int flag)
{
	int		result;
	int		i;
	char	*line;

	i = 0;
	result = 0;
	while (ft_isdigit(str[index]))
		result = result * 10 + (str[index++] - 48);
	line = (char *)malloc(sizeof(char) * result + 1);
	if (!line)
		return (NULL);
	if (flag == 1)
		while (i < result - 2)
			line[i++] = '0';
	else if (flag == 4)
		while (i < result - 2)
			line[i++] = ' ';
	line[i] = '\0';
	return (line);
}
