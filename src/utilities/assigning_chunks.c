/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:57:08 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/09 11:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//How many chunks the orignal list of numbers will be split into 
void number_of_chunks(t_ps *data)
{
	size_t len = data->size_of_list;
	int num_chunks;

	if (len <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	data->number_of_chunks = num_chunks;
	data->size_of_chunk = (data->size_of_list + (data->number_of_chunks - 1)) / data->number_of_chunks;

	assign_chunk_numbers(data);
	return ;
}

//To each node assign the chunk number (done at inital pass when in stack_a)
void assign_chunk_numbers(t_ps *data)
{
	size_t len;
	t_node *tmp;

	len = data->size_of_list;
	tmp = data->stack_a;
	while (tmp &&  len-- > 0)
	{
		tmp->chunk = tmp->idx / data->size_of_chunk;
		tmp = tmp->next;
	}
	return;
}

