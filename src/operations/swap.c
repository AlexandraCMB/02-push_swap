/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/12 14:51:03 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap_a(t_ps *data)
{
	swap(&(data->stack_a));
	log_op(data, SA);
	return ;
}

void	swap_b(t_ps *data)
{
	swap(&(data->stack_b));
	log_op(data, SB);
	return ;
}
