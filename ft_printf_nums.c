/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:51:53 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 11:15:34 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_sc *sc)
{
	if (n == -2147483648)
	{
		ft_putchar('-', sc);
		ft_putchar('2', sc);
		ft_putnbr(147483648, sc);
	}
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-', sc);
		ft_putnbr(n, sc);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, sc);
		ft_putnbr(n % 10, sc);
	}
	else
		ft_putchar(n + '0', sc);
}

void	ft_putdecimal(int nbr, int *flags, t_sc *sc)
{
	char	*number;
	char	*aux;
	int		i;
	int		size;

	i = 0;
	ft_valid_flags_nbr(flags);
	aux = ft_itoa(nbr);
	if (ft_nbrlen(nbr) > sc->ammount)
		size = ft_nbrlen(nbr);
	else
		size = sc->ammount;
	number = (char *)malloc(sizeof(char) * (size + 1));
	if (!number)
	{
		free(number);
		return ;
	}
	if(!sc->ammount)
	{
		ft_putnbr(nbr, sc);
		free(number);
		free(aux);
		return ;
	}
	if (flags[5])
		number = ft_process_minus_flag(nbr, number, flags, sc->ammount);
	if (flags[1])
		number = ft_process_zero_flag(sc->ammount, number, aux, flags[3]);
	if (flags[4])
		number = ft_process_plus_flag(nbr, number, flags, sc->ammount);
	if (flags[3] && !flags[1])
		number = ft_process_space_flag(number, nbr, sc->ammount);
	if (!flags[1] && !flags[2] && !flags[3] && !flags[4] && !flags[5])
		number = ft_no_num_flags(number, aux, sc->ammount);
	ft_putstr(number);
	sc->len += ft_strlen(number);
	free(number);
	free(aux);
}
