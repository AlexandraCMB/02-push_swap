/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:42:18 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*removed;

	removed = (*stack_b);
	if (removed->next == removed)
		(*stack_b) = NULL;
	else
	{
		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		(*stack_b) = removed->next;
	}
	insert_at_beginning(stack_a, removed);
	write(1, "pa\n", 3);
	return ;
}

void	op_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*removed;

	removed = (*stack_a);
	if (removed->next == removed)
		(*stack_a) = NULL;
	else
	{
		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		(*stack_a) = removed->next;
	}
	insert_at_beginning(stack_b, removed);
	write(1, "pb\n", 3);
	return ;
}
