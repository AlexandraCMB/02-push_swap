/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:59:37 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 13:30:16 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# define B_PURP "\033[1;35m"
# define B_GREEN "\033[1;32m"
# define B_RED "\033[1;31m"
# define BROWN "\033[33m"
# define RESET "\033[0m"

int		ft_printf(const char *format, ...);
int		ft_specifier(const char fmt, va_list ap);
int		ft_putchar(int c);
//UTILS
int		ft_found_x_x(unsigned long int nb, const char fmt);
int		ft_found_ptr(void *p);
int		ft_found_s(char *s);
int		ft_found_d_i(int nb);
int		ft_found_u(int nb);

#endif
