/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:54:30 by abrunjes          #+#    #+#             */
/*   Updated: 2025/10/26 11:40:53 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main (void)
{
	int a = 's';
	int b = 'S';
	int c = '*';
	int d = 1;
	int e = '7';
	printf("Yes = 1, No = 0\n");
	printf(" Is %c alpha?:%d \n", a, ft_isascii(a));
	printf(" Is %c alpha?:%d \n", b, ft_isascii(b));
	printf(" Is %c alpha?:%d \n", c, ft_isascii(c));
	printf(" Is %c alpha?:%d \n", d, ft_isascii(d));
	printf(" Is %c alpha?:%d \n", e, ft_isascii(e));
	return 0;
}
*/
