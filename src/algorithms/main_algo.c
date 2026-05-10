/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:15:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/10 16:37:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_sort(t_ps *data)
{
	size_t current_chunk;
	size_t x = 0;
	current_chunk = 0;

	// size_t y;
	while( data->stack_a && data->number_of_chunks > current_chunk  )
	{

		size_t len = data->stack_a_size;
		while( len -- > data->stack_a_size/2 - 1)
		{
			t_node *tmp = data->stack_a;
			size_t cost = 0
			cost++;
			if(tmp->chunk = current_chuck)
				break;
				
		}

		
		
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
			x = 0;
			current_chunk++;
		}

	}
	push_back_from_b(data);
}

void push_back_from_b(t_ps* data)
{
	size_t i = data->size_of_list -1;
	size_t j;
	while(data->stack_b)
	{
		j = cost_to_top_b(data, i);
		if(j < (i/2))
		{
			while(j-- > 0 )
				rot_b(data);
		}
		else
		{
			while(1 + i - j > 0)
			{
				rev_rot_b(data);
				j++;
			}
		}
		push_a(data);
		i--;

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

void optimised_next_a_to_top(t_ps* data)
{
	size_t i = data->stack_a_size -1;
	size_t j;

	j = cost_to_top_a(data, i);
	if(j < (i/2))
	{
		while(j-- > 0 )
			rot_a(data);
	}
	else
	{
		while(1 + i - j > 0)
		{
			rev_rot_a(data);
			j++;
		}
	}
	push_b(data);
}



size_t cost_to_top_up_a(t_ps *data, size_t current_chunk)
{
	t_node *tmp = data->stack_a;
	size_t len = 0;
	size_t cost = 0;
	
	while(len++ <(data->stack_a_size/2) + 1)
	{
		if( tmp->chunk == current_current)
			cost = len;
		tmp = tmp->next;
	}
	return cost
}




cost_to_top_down_a(t_ps *data, size_t current_chunk)
{
	t_node *tmp = data->stack_a->prev;
	size_t len = 0;
	size_t cost = 0;
	size_t x = 0;
	if(data->stack_a_size % 2 = 0)
		x = 
	while(len++ <(data->stack_a_size/2) + )
	{
		if( tmp->chunk == current_current)
			cost = len;
		tmp = tmp->prev;
	}
	return cost
}
