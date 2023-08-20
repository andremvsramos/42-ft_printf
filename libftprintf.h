/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:12:09 by andvieir          #+#    #+#             */
/*   Updated: 2023/08/20 14:41:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//
int		ft_printf(const char *s, ...);
void	ft_check_data(int ptr, va_list valist, int flag, char *line);
void	ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putptr(unsigned long long int);
int		ft_putdecimal(int nbr, int flag, char *line);
int		ft_nbrlen(int n);
int		ft_abs(int nbr);
void	ft_puthex(int nbr, int f);
void	ft_putunsigned(unsigned int nbr);
void	ft_putnbr(int n);
char	*ft_itoa(int nbr);
int		ft_check_flags(char c);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_zeros_to_print(char *str, int index, int flag);
char	*ft_strdup(char *str);
int		ft_strchr(char c);

#endif
