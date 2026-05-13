/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 16:12:47 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	input_checker(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	while (len--)
	{
		i = 0;
		while (str[i] == ' ' )
			i++;
		if (str[i] == '-' || str[i] == '+' )
			i++;
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
		str++;
	}
	return (0) ;
}

void check_ints(t_ps *data)
{
	int x;
	x = data->stack_a_size;
	while(x--> 0)
	{
		int_overflow(data, data->stack_a->num);
	}
	return ;
}

void	int_overflow(t_ps *data, long int num)
{
	int	x;

	x = (int)num;
	if ((long int)x != num)
	{
		free(data);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return ;
}
