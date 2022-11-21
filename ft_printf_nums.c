/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:51:53 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/21 17:33:43 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_putdecimal(int nbr, int flag, char *line)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_nbrlen(nbr);
	if (flag == 3) //' '
	{
		if (nbr >= 0)
			line[0] = ' ';
	}
	else if (flag == 4) //'+'
	{
		if (nbr >= 0)
			line[ft_strlen(line) - 1] = '+';
	}
	str = ft_itoa(nbr);
	ft_putstr(line);
	size = ft_nbrlen(nbr);
	/*while (size--)
		ft_putchar('\b');*/
	size = ft_putstr(str);
	return (size);
}
