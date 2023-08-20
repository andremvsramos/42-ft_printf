/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:12:09 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:33:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/**
 * @brief ANSI escape code to clear the current line and move the cursor to the
 * beginning.
 *
 * This preprocessor macro defines an ANSI escape code used to clear the current
 * line and move the cursor to the beginning of the line. It is often used to
 * overwrite the contents of a line with new content, creating a visual update
 * effect.
 */
# define CLEAR_TXT "\33[2K\r"

/**
 * @brief Structure to hold control data for custom printf implementation.
 *
 * This structure is used to hold control data for a custom printf
 * implementation. It stores information related to length counters,
 * formatting options, and other data needed to handle printing and formatting
 * operations.
 */
typedef	struct	s_sc
{
	int		len;
	int		ammount;
	int		pre_dot_ammount;
	int		wd_size;
	int		hex_size;
}				t_sc;

void		ft_init(t_sc *sc);
char		*ft_read(va_list valist, const char *s, int *flags, t_sc *sc);

int			ft_printf(const char *s, ...);
void		ft_check_data(int ptr, va_list valist, t_sc *sc, int *flags);
int			ft_putchar(char c, t_sc *sc);
int			ft_putstr(char *str);
void		ft_putptr(unsigned long long nbr, int *flags, t_sc *sc);
void		ft_putdecimal(int nbr, int *flags, t_sc *sc);
int			ft_nbrlen(int n);
int			ft_ui_nbrlen(unsigned int n);
int			ft_abs(int nbr);
int			ft_puthex(unsigned long nbr, int f, int *flags, t_sc *sc);
void		ft_putunsigned(unsigned int nbr, int *flags, t_sc *sc);
void		ft_putnbr(int n, t_sc *sc);
char		*ft_itoa(int nbr);
char		*ft_uitoa(unsigned int nbr);
int			ft_check_flags(char c, char *str, int *result);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_zeros_to_print(int n, int flag, char sign);
char		*ft_strchr(const char *s);
const char	*ft_read_text(t_sc *sc, const char *s);
int			ft_ammount(char *str);
int			ft_is_flag(char c);
void		ft_print_ammount(int n, t_sc *sc);
void		ft_print_0x(int *f, int str_len, t_sc *sc);
char		*ft_check_dot(char *s, char *aux, t_sc *sc, int *flags);
void		ft_char(char c, int *flags, t_sc *sc);

void		ft_bzero(void *dest, size_t n);
void		*ft_memset(void *str, int c, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(char *src);
int			ft_strncmp(char *s1, char *s2, unsigned int n);

char		*ft_process_minus_flag(int nbr, char *number, int *flags, int n);
char		*ft_process_zero_flag(int n, char *number, char *aux, int flag3);
char		*ft_process_plus_flag(int nbr, char *number, int *flags, int n);
char		*ft_process_space_flag(char *number, int nbr, int n);
char		*ft_no_num_flags(char *number, char *aux, int n);

void		ft_strings(char *str, int *flags, t_sc *sc);
void		ft_check_pre_dot_ammount(const char *s, t_sc *sc);
int			ft_size_delimitation(t_sc *sc, int str_len);
char		*ft_minmax(char *dest, char *str, t_sc *sc);
char		*ft_string_minus_flag(char *dest, char *str, int *flags, t_sc *sc);
void		ft_pointer_flags(int *flags, int n, t_sc *sc);

void		ft_print_spaces_before(int min, int max, t_sc *sc);

int			ft_valid_flags_str(int *flags);
int			ft_valid_flags_nbr(int *flags);

void	ft_hflags(unsigned long nbr, int f, int *flags, t_sc *sc);
void	ft_hex_minus(unsigned long nbr, int f, int *flags, t_sc *sc);

#endif
