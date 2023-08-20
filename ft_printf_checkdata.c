/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:27 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:19:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Check data type and call appropriate formatting function.
 *
 * This function checks the provided data type `ptr` and calls the appropriate
 * formatting function based on the data type. It takes the va_list `valist`
 * to extract the corresponding argument. The `flags` array controls formatting
 * options, and the formatting is performed according to the specific data type.
 *
 * @param ptr     The specifier representing the data type.
 * @param valist  The va_list containing arguments.
 * @param sc      A pointer to a structure that contains additional control data
 * @param flags   An array of integer flags controlling formatting options.
 */
void	ft_check_data(int ptr, va_list valist, t_sc *sc, int *flags)
{
	if (ptr == 99)
		ft_char(va_arg(valist, unsigned int), flags, sc);
	else if (ptr == 115)
		ft_strings(va_arg(valist, char *), flags, sc);
	else if (ptr == 112)
		ft_putptr(va_arg(valist, unsigned long long), flags, sc);
	else if (ptr == 100 || ptr == 105)
		ft_putdecimal(va_arg(valist, int), flags, sc);
	else if (ptr == 117)
		ft_putunsigned(va_arg(valist, unsigned int), flags, sc);
	else if (ptr == 120)
		ft_hflags(va_arg(valist, unsigned int), 0, flags, sc);
	else if (ptr == 88)
		ft_hflags(va_arg(valist, unsigned int), 1, flags, sc);
	else if (ptr == 37)
		ft_putchar('%', sc);
	ft_bzero(flags, 256);
}

/**
 * @brief Check if a character is a valid flag character.
 *
 * This function checks whether the given character `c` is a valid flag
 * character used in format specifiers. It returns a non-zero value (true) if
 * the character is a valid flag character, and 0 (false) otherwise.
 *
 * @param c   The character to be checked.
 * @return    Non-zero if the character is a valid flag character, 0 otherwise.
 */
int	ft_is_flag(char c)
{
	return (c == '0' || c == '#'
		|| c == ' ' || c == '+' || c == '-' || c == '.');
}

/**
 * @brief Check and process formatting flags.
 *
 * This function checks and processes formatting flags. It determines the type
 * of flag represented by the character `c` and returns the corresponding flag
 * index. Additionally, it extracts and returns the width value specified in
 * the format string after the flag. The `result` parameter is used to return
 * the width value.
 *
 * @param c       The character representing the flag.
 * @param str     The format string.
 * @param result  A pointer to the variable storing the extracted width value.
 * @return        The flag index determined by the character `c`.
 */
int	ft_check_flags(char c, char *str, int *result)
{
	int	i;

	i = 0;
	if (c == '0')
		i = 1;
	else if (c == '#')
		i = 2;
	else if (c == ' ')
		i = 3;
	else if (c == '+')
		i = 4;
	else if (c == '-')
		i = 5;
	else if (c == '.')
		i = 6;
	*result = ft_ammount(str);
	return (i);
}

/**
 * @brief Extract width value from a format string.
 *
 * This function extracts the width value specified in the format string `str`.
 * It iterates through the string, converting digits to an integer width value.
 * The resulting width value is returned.
 *
 * @param str   The format string containing the width specification.
 * @return      The extracted width value.
 */
int	ft_ammount(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	return (res);
}
