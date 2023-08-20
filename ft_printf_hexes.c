/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:41:45 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:21:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Convert and print an unsigned long integer as hexadecimal.
 *
 * This function recursively converts the unsigned long integer `nbr` into its
 * hexadecimal representation and prints it. The character set for hexadecimal
 * conversion is determined by the value of the `f` parameter (0 for lowercase,
 * 1 for uppercase). The function supports the '#' flag by printing a '0x' or
 * '0X' prefix before the hexadecimal representation if the flag is set.
 *
 * @param nbr     The unsigned long integer to be converted and printed.
 * @param f       The character set specifier (0 for lowercase, 1 for uppercase)
 * @param flags   An array of integer flags controlling formatting options.
 * @param sc      A pointer to a structure that contains additional control data
 * @return        The number of characters printed.
 */
int	ft_puthex(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	char	*base;
	int		n;

	n = 0;
	if (f == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (flags[2])
	{
		ft_printf("%c%c", base[0], (base[10] + 23));
		sc->len += 2;
	}
	flags[2] = 0;
	if (nbr >= 16)
	{
		n += ft_puthex(nbr / 16, f, flags, sc);
		n += ft_puthex(nbr % 16, f, flags, sc);
	}
	else
	{
		n += ft_putchar(base[nbr], sc);
		sc->hex_size++;
	}
	return (n);
}

/**
 * @brief Convert and print a pointer value in hexadecimal.
 *
 * This function converts the pointer value `ptr` into its hexadecimal
 * representation and prints it. It also handles the case where the pointer is
 * NULL, in which case it prints "(nil)". The function delegates hexadecimal
 * conversion and formatting to `ft_puthex` and `ft_pointer_flags` functions,
 * respectively.
 *
 * @param ptr     The pointer value to be converted and printed.
 * @param flags   An array of integer flags controlling formatting options.
 * @param sc      A pointer to a structure that contains additional control data
 */
void	ft_putptr(unsigned long long ptr, int *flags, t_sc *sc)
{
	char	*base;
	int		n;

	flags[2] = 1;
	base = "0123456789abcdef";
	if(!ptr)
	{
		write(1, "(nil)", 5);
		sc->len += 5;
		return ;
	}
	else
		n = ft_puthex(ptr, 0, flags, sc);
	ft_pointer_flags(flags, n, sc);
}

/**
 * @brief Print "0x" prefix and update formatting flags and length.
 *
 * This function prints the "0x" prefix for hexadecimal representation and
 * updates the formatting flags and length accordingly. It is typically used
 * when printing hexadecimal values with the '#' flag set.
 *
 * @param f       A pointer to the flag variable.
 * @param str_len The length of the string representation.
 * @param sc      A pointer to a structure that contains additional control data
 */
void	ft_print_0x(int *f, int str_len, t_sc *sc)
{
	*f = 1;
	ft_print_ammount(str_len, sc);
	write(1, "0x", 2);
	sc->len += 2;
}

/**
 * @brief Print a specified amount of spaces.
 *
 * This function prints a specified number of spaces. It is typically used to
 * ensure proper alignment and spacing in the formatted output.
 *
 * @param n       The number of spaces to print.
 * @param sc      A pointer to a structure that contains additional control data
 */
void	ft_print_ammount(int n, t_sc *sc)
{
	while (n-- > 1)
	{
		ft_putchar(' ', sc);
	}
}

/**
 * @brief Print spaces before content to align based on width.
 *
 * This function prints a specified number of spaces before content to achieve
 * alignment based on the minimum and maximum width values provided. It is often
 * used to ensure proper alignment in formatted output.
 *
 * @param min     The minimum width value.
 * @param max     The maximum width value.
 * @param sc      A pointer to a structure that contains additional control data
 */
void	ft_print_spaces_before(int min, int max, t_sc *sc)
{
	while (min < max)
	{
		ft_putchar(' ', sc);
		min++;
	}
}
