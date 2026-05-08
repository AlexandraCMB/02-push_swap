/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunj <brunj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:15:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/08 21:46:10 by brunj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void chunk_sort(t_ps *data)
{
	size_t current_chunk;
	
	current_chunk = 0;
	//x= 0;
	printf("nu")
	while(data->stack_a ||  data->number_of_chunks > current_chunk)
	{
		// x++;
		
		if(data->stack_a->chunk == current_chunk)
		{
			if((data->stack_a->idx % data->size_of_chunk) < (data->size_of_chunk/2))
			{
				push_b(data);
				rot_b(data);
			}
			else
				push_b(data);
		}
		else if(data->stack_b < data->stack_b->next)
			swap_b(data); 	
		else
			rot_a(data);
		// if((data->stack_a->idx + 1) % data->size_of_chunk)
		current_chunk++;
			
	}
}