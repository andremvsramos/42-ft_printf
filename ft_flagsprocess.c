/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:05 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 13:08:38 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_minus_flag(int nbr, char *number, int *flags, int n)
{
	int		i;
	int		j;
	int		x;
	char	*aux;

	aux = ft_itoa(nbr);
	i = 0;
	x = 0;
	j = 0;
	if (nbr < 0)
	{
		number[i++] = '-';
		j++;
	}
	flags[3] = 0;
	if (!n)
		return (aux);
	if (n < ft_strlen(aux))
		while (aux[j])
			number[i++] = aux[j++];
	else
		while (aux[j])
			number[i++] = aux[j++];
		while (i < n)
			number[i++] = ' ';
	flags[1] = 0;
	number[i] = '\0';
	free(aux);
	return (number);
}

char	*ft_process_zero_flag(int n, char *number, char *aux, int flag3)
{
	int	i;

	i = 0;
	n -= ft_strlen(aux);
	ft_memset(number, '0', n);
	if (aux[i] == '-')
	{
		number[i] = '-';
		i++;
		n++;
	}
	else if (flag3)
		number[i] = ' ';
	while (aux[i])
		number[n++] = aux[i++];
	number[n] = '\0';
	if (*number)
		return (number);
	return (0);
}

char	*ft_process_plus_flag(int nbr, char *number, int *flags, int n)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_itoa(nbr);
	if (!flags[1])
		ft_memset(number, ' ', n);
	if (flags[1])
	{
		if (nbr > 0)
			number[0] = '+';
		else
			number[0] = aux[0];
	}
	else if (!flags[1])
	{
		while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	}
	number[n] = '\0';
	flags[3] = 0;
	return (number);
}

char	*ft_process_space_flag(char *number, int nbr, int n)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_itoa(nbr);
	ft_memset(number, ' ', n);
	while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	return (number);
}

char	*ft_no_num_flags(char *number, char *aux, int n)
{
	int	i;

	i = 0;
	if (ft_strlen(aux) > n)
	{
		while (aux[i])
		{
			number[i] = aux[i];
			i++;
		}
	}
	else if (n)
	{
		ft_memset(number, ' ', n);
		while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	}
	else
	{
		while (aux[i])
			number[n++] = aux[i++];
	}
	number[n] = '\0';
	return (number);
}
