/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:30:48 by andvieir          #+#    #+#             */
/*   Updated: 2022/11/30 12:02:22 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read(va_list valist, const char *s, int *flags, t_sc *sc)
{
	char *aux;

	aux = ft_strdup((char *)s);
	if (*s == '%')
	{
		s++;
		while (ft_is_flag(*s))
		{
			flags[ft_check_flags(*s, (char *)(s + 1), &sc->ammount)] = 1;
			s++;
		}
		if (!sc->ammount && ft_isdigit(*s))
			ft_check_flags(*s, (char *)(s), &sc->ammount);
		while (ft_isdigit(*s))
			s++;
		s = ft_check_dot((char *)s, aux, sc, flags);
		ft_check_data((int)*((char *)(s)), valist, sc, flags);
		s++;
		sc->ammount = 0;
	}
	else
		ft_putchar(*(s++), sc);
	free(aux);
	return ((char *)s);
}
