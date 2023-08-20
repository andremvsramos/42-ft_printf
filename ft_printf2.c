/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:30:48 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Read and process format specifiers in the format string.
 *
 * This function reads and processes format specifiers in the format string `s`.
 * It handles flags, field width, precision, and data conversion specifiers. It
 * updates the `flags` and `sc` structures accordingly. If a '%' character is
 * encountered, it extracts and processes the format specifiers and delegates
 * data conversion using other functions. If no format specifier is found, it
 * prints the character directly.
 *
 * @param valist   The va_list containing variable arguments.
 * @param s        The format string to be processed.
 * @param flags    An array of integer flags controlling formatting options.
 * @param sc       A pointer to a structure that contains additional control
 * data.
 * @return         A pointer to the next character in the format string.
 */
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
