/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:18 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 14:42:41 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//printing stacks
int main (int argc, char **argv)
{
	t_ps *data;

	// 1. Allocate the main wrapper
    data = malloc(sizeof(t_ps));
    // 2. Allocate the actual stack headers inside the wrapper
    data->stack_a = malloc(sizeof(t_stack));
    data->stack_b = malloc(sizeof(t_stack));
	
    // 3. Initialize values 
    data->stack_a->head = init_stack(argc, argv);
    data->stack_a->size = argc - 1; // Assuming init_stack works correctly
    data->stack_b->head = NULL;
    data->stack_b->size = 0;

	
	printf("Before:\n");
	print_stacks(data);
	create_indices(data);
	//DEMO OPERATIONS
	
	swap_a(data);
	push_b(data);

	//
	printf("\nAfter:\n");
	print_stacks(data);
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	return (1);
}

//for indices checking
/* int main (int argc, char **argv)
{
	t_node *stack_a;

	stack_a = init_stack(argc, argv);
	create_indices(stack_a);
	return (1);
}
 */

int  stack_len(t_node *stack)
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

int print_stacks(t_ps *data)
{
	t_node *tmp_a = data->stack_a->head;
	t_node *tmp_b = data->stack_b->head;

	int a = data->stack_a->size;
	int b = data->stack_b->size;
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
