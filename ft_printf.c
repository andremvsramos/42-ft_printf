/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:23:06 by andvieir          #+#    #+#             */
/*   Updated: 2022/12/02 12:05:48 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}

void	ft_init(t_sc *sc)
{
	sc->len = 0;
	sc->ammount = 0;
	sc->pre_dot_ammount = 0;
	sc->wd_size = 0;
	sc->hex_size = 0;
}

char	*ft_check_dot(char *s, char *aux, t_sc *sc, int *flags)
{
	if (*s == '.')
	{
		ft_check_pre_dot_ammount(aux, sc);
		flags[ft_check_flags(*s, (char *)(s + 1), &sc->ammount)] = 1;
		s++;
		while (ft_isdigit(*s))
			s++;
	}
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	t_sc	sc;
	int		flags[256];

	va_start(valist, s);
	ft_init(&sc);
	ft_bzero(flags, 256 * sizeof(int));
	while (*s)
		s = ft_read(valist, s, flags, &sc);
	va_end(valist);
	return (sc.len);
}
