/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/14 19:20:12 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void input_checker(char *str)
{
	int i;
	int len;
	len = ft_strlen(str);
	while(len--)
	{
		i = 0;
		while (str[i] == ' ' )
			i++;
		if (str[i] == '-' || str[i] == '+' )
			i++;
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		str++;
	}
	return;
}

void int_overflow(long int num)
{
	int x;
	x = (int)num;

	// printf("int x is %d\n",x);
	// printf("long int num is %ld\n",num);
	if((long int)x != num )
	{	
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return;
}