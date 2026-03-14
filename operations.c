/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/14 18:15:24 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	if(!*stack)
		return;
	// printf("s0: head->data %d\n", (*stack)->data);
	//printf("s0.1: head->next->data %d\n", (*stack)->next->data);

	t_node *xx1 = (*stack)->prev->prev;
	t_node *x1 = (*stack)->prev;
	t_node *n1 = (*stack);
	t_node *n2 = (*stack)->next;
	t_node *x2 = (*stack)->next->next;
	t_node *xx2 = (*stack)->next->next->next;

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



// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
// ss : sa and sb at the same time.
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

