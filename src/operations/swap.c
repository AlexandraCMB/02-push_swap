/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 14:24:32 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa expain ops here
 */
//checker is 1 if sa or sb not s
void	swap(t_node **stack)
{

	if (!*stack || !((*stack)->next))
		return ;
	if ((*stack)->next == (*stack)->prev)
	{
		(*stack) = (*stack)->prev;
		return ;
	}
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	return ;
}

void swap_a(t_ps *data)
{
	swap(&(data->stack_a->head));
	return ;
}

void swap_b(t_ps *data)
{
	swap(&(data->stack_b->head));
	return ;
}

void swap_both(t_ps *data)
{
	swap_a(data);
	swap_b(data);
	return ;
}