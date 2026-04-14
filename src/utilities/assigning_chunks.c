/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:57:08 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/14 18:35:57 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void number_of_chunks(t_ps *data)
{
	size_t len = data->list_size;
	int num_chunks;

	if (len <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	assign_chunk_numbers(data, num_chunks);
	return ;
}


void assign_chunk_numbers(t_ps *data, int num_chunks)
{
	size_t len;
	size_t chunk_size;
	t_node *current;
	size_t count;

	len = data->list_size;
	chunk_size = len / num_chunks;
	current = data->stack_a;
	count = 0;
	while (current && count < len)
	{
		current->chunk_num = current->idx / chunk_size;
		current = current->next;
		count++;
	}
	return;
}

