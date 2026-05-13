/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:31:55 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 16:45:33 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_x_x(unsigned long int nb, const char fmt)
{
	char	*base;
	int		mod;
	int		len;
	int		q;

	len = 0;
	if (fmt == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		q = ft_found_x_x((nb / 16), fmt);
		len += q;
	}
	mod = nb % 16;
	ft_putchar(base[mod]);
	len += 1;
	return (len);
}

int	ft_found_ptr(void *ptr)
{
	uintptr_t	address;
	int			len;

	address = (uintptr_t)ptr;
	len = 0;
	if (!ptr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_found_x_x((uintptr_t)address, 'x');
	return (len);
}

int	ft_found_s(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

int	ft_found_d_i(int nb)
{
	int	len;
	int	num;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb >= 10)
		len += ft_found_d_i(nb / 10);
	ft_putchar(num);
	len++;
	return (len);
}

int	ft_found_u(int nb)
{
	int	len;
	int	num;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb >= 10)
		len += ft_found_u(nb / 10);
	ft_putchar(num);
	len++;
	return (len);
}