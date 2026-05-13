/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:03:52 by abrunjes          #+#    #+#             */
/*   Updated: 2025/10/26 11:41:14 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = 's';
	b = 'S';
	c = '*';
	d = -5;
	e = '7';
	printf("Yes = 1, No = 0\n");
	printf(" Is %c alpha?:%d \n", a, ft_isalpha(a));
	printf(" Is %c alpha?:%d \n", b, ft_isalpha(b));
	printf(" Is %c alpha?:%d \n", c, ft_isalpha(c));
	printf(" Is %c alpha?:%d \n", d, ft_isalpha(d));
	printf(" Is %c alpha?:%d \n", e, ft_isalpha(e));
	return (0);
}*/
