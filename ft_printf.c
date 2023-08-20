/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:23:06 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:32:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Calculate the length of a null-terminated string.
 *
 * This function calculates and returns the length of the null-terminated string
 * `str`.
 *
 * @param str   The input null-terminated string.
 * @return      The length of the input string.
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Locate the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character '%' in the
 * null-terminated string `s`. If found, it returns a pointer to the first
 * occurrence; otherwise, it returns NULL.
 *
 * @param s    The input null-terminated string to search.
 * @return     A pointer to the first occurrence of '%', or NULL if not found.
 */
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

/**
 * @brief Initialize the t_sc structure with default values.
 *
 * This function initializes the members of the t_sc structure with default
 * values.
 *
 * @param sc   A pointer to the t_sc structure to be initialized.
 */
void	ft_init(t_sc *sc)
{
	sc->len = 0;
	sc->ammount = 0;
	sc->pre_dot_ammount = 0;
	sc->wd_size = 0;
	sc->hex_size = 0;
}

/**
 * @brief Check and process the dot precision in the format string.
 *
 * This function checks for a dot precision in the format string `s`. It
 * extracts the precision value and updates the flags and the t_sc
 * structure accordingly. It returns a pointer to the next character in the
 * format string.
 *
 * @param s       The format string to check.
 * @param aux     A pointer to the current position in the format string.
 * @param sc      A pointer to the t_sc structure.
 * @param flags   An array of integer flags controlling formatting options.
 * @return        A pointer to the next character in the format string.
 */
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

/**
 * @brief Custom printf function with variable argument list.
 *
 * This function implements a custom version of the printf function. It parses
 * the format string `s`, processes the format specifiers, and performs the
 * corresponding output formatting and printing using the va_list valist. It
 * returns the total number of characters printed.
 *
 * @param s       The format string.
 * @param ...     Variable argument list.
 * @return        The total number of characters printed.
 */
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
