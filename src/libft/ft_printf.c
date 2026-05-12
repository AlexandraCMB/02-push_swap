/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:56:50 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/12 14:59:07 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_specifier(const char fmt, va_list ap)
{
	int	count;

	count = 0;
	if (fmt == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		count += ft_found_s(va_arg(ap, char *));
	else if (fmt == 'd' || fmt == 'i')
		count += ft_found_d_i(va_arg(ap, int));
	else if (fmt == 'u')
		count += ft_found_u(va_arg(ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		count += ft_found_x_x(va_arg(ap, unsigned int), fmt);
	else if (fmt == 'p')
		count += ft_found_ptr(va_arg(ap, void *));
	else if (fmt == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format))
				total += ft_specifier(*format, ap);
		}
		else
		{
			ft_putchar(*format);
			total++;
		}
		format++;
	}
	va_end(ap);
	return (total);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}