/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:42:21 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:39:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Process and print formatted strings with various options.
 *
 * This function processes and prints formatted strings based on the input
 * string `str` and various formatting options controlled by the integer array
 * `flags`.
 * The control data structure `sc` is used to track and manage information about
 * the printing process.
 *
 * @param str     The input string to be processed and printed.
 * @param flags   An array of integer flags controlling formatting options.
 * @param sc      A pointer to the control data structure.
 */
void	ft_strings(char *str, int *flags, t_sc *sc)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		sc->len += 6;
		return ;
	}
	sc->wd_size = ft_size_delimitation(sc, ft_strlen(str));
	if (!ft_strlen(str))
	{
		if (sc->ammount)
			while (i++ < sc->ammount)
				ft_putchar(' ', sc);
		return ;
	}
	if (ft_strlen(str) == sc->wd_size)
	{
		ft_putstr(str);
		sc->len += ft_strlen(str);
		return ;
	}
	if (flags[5] && !flags[6])
	{
		ft_putstr(str);
		sc->len += ft_strlen(str);
		ft_print_ammount(sc->ammount - ft_strlen(str) + 1, sc);
		return ;
	}
	if (!flags[6] && !sc->ammount)
	{
		dest = ft_strdup((char *)str);
		ft_putstr(dest);
		sc->len += ft_strlen(dest);
		free(dest);
		return ;
	}
	dest = (char *)malloc(sizeof(char) * sc->wd_size + 1);
	if (!dest)
		return ;
	if (sc->wd_size == sc->pre_dot_ammount)
		ft_memset(dest, ' ', sc->wd_size);
	if (flags[6])
		dest = ft_string_minus_flag(dest, str, flags, sc);
	free(dest);
}

/**
 * @brief Copies the source string to the destination with padding handling.
 *
 * This function copies the source string `str` to the destination `dest` with
 * padding handling based on the width and pre-dot width from the control
 * structure `sc`.
 *
 * @param dest   The destination string with padding.
 * @param str    The source string to be copied.
 * @param sc     A pointer to the control data structure.
 * @return       The modified destination string.
 */
char	*ft_minmax(char *dest, char *str, t_sc *sc)
{
	if (sc->wd_size == sc->pre_dot_ammount)
	{
		if (sc->ammount < ft_strlen(str))
			ft_strlcpy(dest + ft_strlen(dest) - sc->ammount,
				str, (sizeof(char) * sc->ammount + 1));
		else
		{
			ft_memset(dest, ' ', sc->pre_dot_ammount);
			ft_strlcpy(dest + ft_strlen(dest) - ft_strlen(str) - 1,
				str, (sizeof(char) * sc->ammount));
		}
	}
	else
		ft_strlcpy(dest, str, (sizeof(char) * sc->ammount + 1));
	dest[sc->wd_size] = '\0';
	return (dest);
}

/**
 * @brief Calculates the size based on width delimitation and formatting options.
 *
 * This function calculates the size for formatting based on the width delimitation,
 * the source string length `str_len`, and the control data structure `sc`.
 *
 * @param sc        A pointer to the control data structure.
 * @param str_len   The length of the source string.
 * @return          The calculated size for formatting.
 */
int	ft_size_delimitation(t_sc *sc, int str_len)
{
	int	size;

	size = 0;
	if (sc->pre_dot_ammount)
	{
		if (sc->pre_dot_ammount < str_len)
			size = str_len;
		else if (sc->ammount > sc->pre_dot_ammount)
			size = sc->ammount;
		else
			size = sc->pre_dot_ammount;
	}
	else
	{
		if (str_len > sc->ammount)
			size = str_len;
		else
			size = sc->ammount;
	}
	return (size);
}

/**
 * @brief Checks the pre-dot width from the format string.
 *
 * This function checks the pre-dot width from the format string `s` and updates
 * the pre-dot width in the control data structure `sc`.
 *
 * @param s   The format string.
 * @param sc  A pointer to the control data structure.
 */
void	ft_check_pre_dot_ammount(const char *s, t_sc *sc)
{
	int			temp;
	static int	dot;

	temp = 0;
	while (temp <= dot)
	{
		if (*s == '.')
			s++;
		while (*s != '.')
			s++;
		temp++;
	}
	if (*s == '.')
	{
		s--;
		while (ft_isdigit(*s))
			s--;
		s++;
		if (*s == '0')
			exit(EXIT_FAILURE);
		sc->pre_dot_ammount = ft_ammount((char *)s);
		while (*s != '.')
			s++;
	}
	dot = temp;
}

/**
 * @brief Applies left-justification padding and handles destination string.
 *
 * This function applies left-justification padding to the destination `dest`
 * based on the source string `str`, formatting flags, and the control data
 * structure `sc`.
 *
 * @param dest   The destination string with padding.
 * @param str    The source string to be copied.
 * @param flags  An array of integer flags controlling formatting options.
 * @param sc     A pointer to the control data structure.
 * @return       The modified destination string.
 */
char	*ft_string_minus_flag(char *dest, char *str, int *flags, t_sc *sc)
{
	if (flags[6])
	{
		if (flags[5])
		{
			ft_strlcpy(dest, str, sc->ammount + 1);
			ft_memset(dest + ft_strlen(dest), ' ', sc->ammount);
		}
		else
			dest = ft_minmax(dest, str, sc);
	}
	else
		ft_strlcpy(dest, str, (sizeof(char) * sc->ammount + 1));
	dest[sc->wd_size] = '\0';
	return (dest);
}
