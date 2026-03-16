/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:46:23 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:39:01 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int print_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node *tmp_a = stack_a;
	t_node *tmp_b = stack_b;

	int a = stack_len(stack_a);
	int b = stack_len(stack_b);
	if (a==0 && b ==0)
	{
		printf("A: (empty)	 	B: (empty)\n");
		return (0);
	}
	printf("	Stack A	| Stack B\n");
	printf("-------------------------------\n");

	while ((a + b) > 0)
	{
		if(a == 0 && b > 0)
		{
			printf("	-	|	%d\n", tmp_b->data);
			tmp_b=tmp_b->next;
			b--;
		}
		if(a > 0 && b==0)
		{
			printf("	%d	|	-\n", tmp_a->data);
			tmp_a=tmp_a->next;
			a--;
		}
		if(a > 0 && b > 0)
		{
			printf("	%d	|	%d\n", tmp_a->data, tmp_b->data);
			tmp_a=tmp_a->next;
			tmp_b=tmp_b->next;
			a--;
			b--;
		}
	}
	return (1);
}

int stack_len(t_node *stack)
{
	int i = 1;
	t_node *tmp;
	tmp = stack;
	if(!stack)
		return 0;
	while(tmp->next != stack)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int main (int argc, char **argv)
{
	int i;
	t_node *stack_a;
	t_node *stack_b;
	// t_node *x1;

	
	i = 1;
	stack_a = init_stack(argc, argv);
	stack_b = init_stack(argc, argv);
	//x1 = stack_a;
	printf("Before:\n");
	print_stacks(stack_a, stack_b);
	//printf("Operation: ");
	op_ss(&stack_a, &stack_b);
	printf("\nAfter:\n");
	print_stacks(stack_a, stack_b);
	return (1);
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
