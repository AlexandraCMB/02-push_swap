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

#include "../push_swap.h"

/**
 * sa expain ops here
 */
void	op_sa(t_node **stack, int checker)
{
	if (!*stack || !((*stack)->next))
		return ;
	if ((*stack)->next == (*stack)->prev)
	{
		(*stack) = (*stack)->prev;
		write(1, "sa\n", 3);
		return ;
	}
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	if (checker)
		write(1, "sa\n", 3);
	return ;
}

void	op_sb(t_node **stack, int checker)
{
	if (!*stack || !((*stack)->next))
		return ;
	if ((*stack)->next == (*stack)->prev)
	{
		(*stack) = (*stack)->prev;
		write(1, "sb\n", 3);
		return ;
	}
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	if (checker)
		write(1, "sb\n", 3);
	return ;
}
