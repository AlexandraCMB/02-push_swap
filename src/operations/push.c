/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 14:27:57 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*removed;

	removed = (*stack_from);
	if (removed->next == removed)
		(*stack_from) = NULL;
	else
	{
		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		(*stack_from) = removed->next;
	}
	insert_at_beginning(stack_to, removed);
	return ;
}

void push_a(t_ps *data)
{
	if (!data->stack_b->head)
		return ;
	push(&data->stack_b->head, &data->stack_a->head);
	data->stack_a->size++;
	data->stack_b->size--;
	return ;
}

void push_b(t_ps *data)
{
	if (!data->stack_a->head)
		return ;
	push(&data->stack_a->head, &data->stack_b->head);
	data->stack_b->size++;
	data->stack_a->size--;
	return ;
}