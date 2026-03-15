/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:40:30 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa expain ops here
 */
void	op_sa(t_node **stack)
{
	if(!*stack || !((*stack)->next))
		return;
	if((*stack)->next == (*stack)->prev)
	{
		(*stack) = (*stack)->prev;
		write(1, "sa\n", 3);
		return;
	}
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack) ->prev;
	(*stack)->prev->next = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	write(1, "sa\n", 3);
	return;
}


void	op_sb(t_node **stack)
{
	if(!*stack || !((*stack)->next))
		return;
	if((*stack)->next == (*stack)->prev)
	{
		(*stack) = (*stack)->prev;
		write(1, "sb\n", 3);
		return;
	}

	(*stack)->next = (*stack)->next->next;
	(*stack)->next->prev->prev = (*stack) ->prev;
	(*stack)->prev->next = (*stack)->next->prev;
	(*stack)->next->prev = (*stack);
	(*stack)->prev->next->next = (*stack);
	(*stack)->prev = (*stack)->prev->next;
	(*stack) = (*stack)->prev;
	write(1, "sb\n", 3);
	return;
}

void op_pb(t_node **stack_a, t_node **stack_b)
{
	t_node *removed;
	
	removed = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	//ONE NODE
	if((*stack_a)->next == (*stack_a))
	{
		// (*stack_a)=NULL;
	}
	//>2 NODES	
	else
	{
	(*stack_a)->prev->prev->next = (*stack_a);
	(*stack_a)->prev = (*stack_a)->prev->prev;
	}
	insert_at_beginning(stack_b, removed);

	write(1, "pb\n", 3);
	return;
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

