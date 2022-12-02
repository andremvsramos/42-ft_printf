/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:12:52 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 11:44:45 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_sc *sc)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	sc->len++;
	return (1);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	ft_putunsigned(unsigned int nbr, int *flags, t_sc *sc)
{
	char	*uns_int;
	int		i;

	i = 0;
	uns_int = ft_uitoa(nbr);
	if (!flags[5])
		ft_putstr(uns_int);
	else
	{
		ft_putstr(uns_int);
		while (i++ < sc->ammount - ft_strlen(uns_int))
			ft_putchar(' ', sc);
	}
	sc->len += ft_strlen(uns_int);
	free(uns_int);
}
