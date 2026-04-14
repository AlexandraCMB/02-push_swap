/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/14 18:33:54 by abrunjes         ###   ########.fr       */
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
	if (!data->stack_b)
		return ;
	push(&data->stack_b, &data->stack_a);
	log_op(data, PA);
	return ;
}

void push_b(t_ps *data)
{
	if (!data->stack_a)
		return ;
	push(&data->stack_a, &data->stack_b);
	log_op(data, PB);
	return ;
}