/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:17 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/17 15:19:44 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	starting_i(int x);
static int	ft_abs(int x);

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = starting_i(n);
	s = malloc(sizeof(char) * i + 1);
	if (!s)
		return (NULL);
	*(s + i) = '\0';
	if (n == 0)
	{
		*s = '0';
		return (s);
	}
	while (i--)
	{
		*(s + i) = ft_abs(n % 10) + '0';
		if (i == 0 && *s == '0')
			*(s + i) = '-';
		n /= 10;
	}
	return (s);
}

static int	ft_abs(int x)
{
	if (x < 0)
	{
		x *= -1;
		return (x);
	}
	return (x);
}

static int	starting_i(int x)
{
	int	q;
	int	i;

	q = x;
	i = 0;
	if (x <= 0)
		i = 1;
	while (q != 0)
	{
		q /= 10;
		i += 1;
	}
	return (i);
}
