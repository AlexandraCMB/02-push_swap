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

// ra (rotate a): Shift up all elements of stack a by 1.
void	op_ra(t_node **stack, int checker)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;
	if (checker)
		write(1, "ra\n", 3);
	return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
void	op_rb(t_node **stack, int checker)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;
	if (checker)
		write(1, "rb\n", 3);
	return ;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	op_rra(t_node **stack, int checker)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->prev;
	if (checker)
		write(1, "rra\n", 4);
	return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	op_rrb(t_node **stack, int checker)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->prev;
	if (checker)
		write(1, "rrb\n", 4);
	return ;
}
