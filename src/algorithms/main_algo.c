/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:15:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/09 17:24:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_sort(t_ps *data)
{
	size_t current_chunk;
	size_t x = 0;
	current_chunk = 0;
	//x= 0;
	while( data->stack_a && data->number_of_chunks > current_chunk  )
	{
		// x++;
		
		if(data->stack_a->chunk == current_chunk)
		{
			x++;
			push_b(data);
			if(data->stack_b && data->stack_b->next && data->stack_b->idx < data->stack_b->next->idx)
				swap_b(data);
		}	
		else
			rot_a(data);
		if( data->stack_a && x >= data->size_of_chunk )
		{
			x =0;
			current_chunk++;
			// printf("current chunk increased to - %ld\n", current_chunk);
		}

	}
	size_t i = data->size_of_list;
	int j;
	while(data->stack_b)
	{
		j = cost_to_top_b(data, i) 
		if(j < (i/2))
		{
			while(j-- > 0 )
				rot_b(data);
		}
		else
		{
			while(i-j++ >= 0)
				rev_rot_b(data);
		}
		push_a(data);
		
	}
}



int cost_to_top_b(t_ps *data, size_t num_in_list)
{
	int cost;
	int len;
	t_node *tmp;

	
	cost = 0;
	len = stack_len(data->stack_b);
	tmp = data->stack_b;
	if(len == 1)
		return 0;
	while(tmp->idx != tmp->next->idx && tmp->idx != num_in_list )
	{
		cost += 1;
		tmp = tmp->next;
	}
	return cost;
}
