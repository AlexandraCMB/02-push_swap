/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:15:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/11 16:49:17 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_sort(t_ps *data)
{
	size_t current_chunk;
	size_t x = 0;
	size_t cost_up;
	size_t cost_down;
	current_chunk = 0;

	push_a(data);
	push_a(data);
	
	while( data->stack_a && data->number_of_chunks > current_chunk  )
	{
		cost_up = cost_to_top_up_a(data, current_chunk);
		cost_down = cost_to_top_down_a(data, current_chunk);
		printf("current chunk: %ld, cost up: %ld, cost down: %ld\n", current_chunk, cost_up, cost_down);
		if(cost_up <= cost_down)
		{
			while(cost_up-- > 0)
			{
				rot_a(data);
			}
		}
		else
		{
			while(cost_down-- > 0)
			{
				rev_rot_a(data);
			}

		}
		push_b(data);
		if(data->stack_b && data->stack_b->next && data->stack_b->idx < data->stack_b->next->idx)
			swap_b(data);
		print_stacks(data);
		
		x++;
		if( data->stack_a && x >= data->size_of_chunk )
		{
			x = 0;
			current_chunk++;
		}

	}
	push_back_from_b(data);
}

// void chunk_sort(t_ps *data)
// {
// 	size_t current_chunk;
// 	size_t x = 0;
// 	size_t cost_up;
// 	size_t cost_down;
// 	current_chunk = 0;

// 	push_a(data);
// 	push_a(data);
	
// 	while( data->stack_a && data->number_of_chunks > current_chunk  )
// 	{
// 		cost_up = cost_to_top_up_a(data, current_chunk);
// 		cost_down = cost_to_top_down_a(data, current_chunk);
// 		printf("current chunk: %ld, cost up: %ld, cost down: %ld\n", current_chunk, cost_up, cost_down);
// 		if(cost_up <= cost_down)
// 		{
// 			while(cost_up-- > 0)
// 			{
// 				rot_a(data);
// 			}
// 		}
// 		else
// 		{
// 			while(cost_down-- > 0)
// 			{
// 				rev_rot_a(data);
// 			}

// 		}
// 		push_b(data);
// 		if(data->stack_b && data->stack_b->next && data->stack_b->idx < data->stack_b->next->idx)
// 			swap_b(data);
// 		print_stacks(data);
		
// 		x++;
// 		if( data->stack_a && x >= data->size_of_chunk )
// 		{
// 			x = 0;
// 			current_chunk++;
// 		}

// 	}
// 	push_back_from_b(data);
// }

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
			while(data->stack_b_size - j > 0)
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
	if(len <= 1)
		return 0;
	while(tmp->idx != num_in_list && tmp->next != data->stack_b)
	{
		cost ++;
		tmp = tmp->next;
	}
	return cost;
}


size_t cost_to_top_up_a(t_ps *data, size_t current_chunk)
{
	t_node *tmp = data->stack_a;
	size_t len = 0;
	size_t cost = 0;
	int found = 0;
	
	while(len <=(data->stack_a_size/2) + 1)
	{
		if( tmp->chunk == current_chunk)
		{
			cost = len;
			found = 1;
			break;
		}
		tmp = tmp->next;
		len++;
	}
	if(!found)
		return 9999;
	return cost;
}

size_t cost_to_top_down_a(t_ps *data, size_t current_chunk)
{
	t_node *tmp = data->stack_a->prev;
	size_t len = 0;
	size_t cost = 0;
	int found = 0;
	while(len <=((data->stack_a_size + 1)/2) -1 )
	{
		if( tmp->chunk == current_chunk)
		{
			cost = len+1;
			found = 1;
			break;
		}
		len++;
		tmp = tmp->prev;
	}
	if(!found)
		return 9999;
	return cost;
}
