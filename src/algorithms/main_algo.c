/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:15:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 16:54:58 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ps *data)
{
	size_t	x;
	size_t	i;

	x = ft_sqrt(data->size_of_list) * 1.1;
	i = 0;
	while (data->stack_a)
	{
		if (data->stack_a->idx <= i)
		{
			push_b(data);
			rot_b(data);
			i++;
		}
		else if (data->stack_a->idx <= i + x)
		{
			push_b(data);
			i++;
		}
		else
			rot_a(data);
	}
	push_back_from_b(data);
}

size_t	ft_sqrt(size_t nb)
{
	size_t	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void	push_back_from_b(t_ps *data)
{
	size_t	i;
	size_t	j;

	i = data->size_of_list -1;
	while (data->stack_b)
	{
		j = cost_to_top_b(data, i);
		if (j < (i / 2))
		{
			while (j-- > 0)
				rot_b(data);
		}
		else
		{
			while (data->stack_b_size - j > 0)
			{
				rev_rot_b(data);
				j++;
			}
		}
		push_a(data);
		i--;
	}
}

size_t	cost_to_top_b(t_ps *data, size_t num_in_list)
{
	size_t	cost;
	size_t	len;
	t_node	*tmp;

	cost = 0;
	len = data->stack_b_size;
	tmp = data->stack_b;
	if (len <= 1)
		return (0);
	while (tmp->idx != num_in_list && tmp->next != data->stack_b)
	{
		cost ++;
		tmp = tmp->next;
	}
	return (cost);
}
