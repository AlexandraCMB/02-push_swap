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

/**
 * sa expain ops here
 */
 
void	op_sa(t_node **stack, int checker)
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
	if(checker)
		write(1, "sa\n", 3);
	return;
}


void	op_sb(t_node **stack, int checker)
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
	if(checker)
		write(1, "sb\n", 3);
	return;
}

void	op_ss(t_node **stack_a, t_node **stack_b)
{
	int checker;
	checker = 0;
	op_sa(stack_a, checker);
	op_sa(stack_b, checker);
	write(1, "ss\n", 4);
	return;

}

void op_pa(t_node **stack_a, t_node **stack_b)
{
	t_node *removed;
	
	removed = (*stack_b);
	if(removed->next == removed)
	{
		(*stack_b)=NULL;
	}
	else
	{void	op_ss(t_node **stack_a,t_node **stack_b);

		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		(*stack_b) = removed->next;
	}

	insert_at_beginning(stack_a, removed);
	write(1, "pa\n", 3);
	return;
}

void op_pb(t_node **stack_a, t_node **stack_b)
{
	t_node *removed;
	
	removed = (*stack_a);
	if(removed->next == removed)
	{
		(*stack_a)=NULL;
	}
	else
	{
		removed->prev->next = removed->next;
		removed->next->prev = removed->prev;
		(*stack_a) = removed->next;
	}

	insert_at_beginning(stack_b, removed);
	write(1, "pb\n", 3);
	return;
}

// ra (rotate a): Shift up all elements of stack a by 1.
void op_ra(t_node **stack, int checker)
{
	if(!(*stack))
		return;
	(*stack) = (*stack)->next;
	if(checker)
		write(1, "ra\n", 3);
	return;
}

// rb (rotate b): Shift up all elements of stack b by 1.
void op_rb(t_node **stack, int checker)
{

	if(!(*stack))
		return;
	(*stack) = (*stack)->next;
	if(checker)
		write(1, "rb\n", 3);
	return;
}
// rr : ra and rb at the same time
void op_rr(t_node **stack_a,t_node **stack_b)
{
	int check = 0;
	op_ra(stack_a, check);
	op_rb(stack_b, check);
	write(1, "rr\n", 3);
	return;
}



// rra (reverse rotate a): Shift down all elements of stack a by 1.
void op_rra(t_node **stack, int checker)
{
	if(!(*stack))
		return;
	(*stack) = (*stack)->prev;
	if(checker)
		write(1, "rra\n", 4);
	return;
}
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void op_rrb(t_node **stack, int checker)
{

	if(!(*stack))
		return;
	(*stack) = (*stack)->prev;
	if(checker)
		write(1, "rrb\n", 4);
	return;
}
// rrr : rra and rrb at the same time.
void op_rrr(t_node **stack_a,t_node **stack_b)
{
	int check = 0;
	op_ra(stack_a, check);
	op_rb(stack_b, check);
	write(1, "rrr\n", 4);
	return;
}
