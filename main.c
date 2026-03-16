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

int main (int argc, char **argv)
{
	int i;
	t_node *stack_a;
	t_node *stack_b;
	// t_node *x1;

	i = 1;

	stack_a = init_stack(argc, argv);

	int *arr = (int *)malloc(stack_len(stack_a) * sizeof(int));
	
	t_node *tmp;
	tmp = stack_a;
	
	int i = 0;
	while(tmp->next != stack)
	{
		tmp = tmp->next;
		arr[i++];
	}


	





	stack_b = NULL;
	//x1 = stack_a;
	printf("Before:\n");
	print_stacks(stack_a, stack_b);
	//printf("Operation: ");
	op_ss(&stack_a, &stack_b);
	printf("\nAfter:\n");
	print_stacks(stack_a, stack_b);
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
