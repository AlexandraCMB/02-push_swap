/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:18 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/11 18:07:48 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//printing stacks
int main (int argc, char **argv)
{
	t_ps *data;
	if(duplicates_in_input(argc,argv))
	{
		printf("Error\n");
		return 0;
	}

	//MALLOC
    data = malloc(sizeof(t_ps));

    //INIT
    data->stack_a = init_stack(argc, argv);
    data->size_of_list = argc - 1; // Assuming init_stack works correctly
	data->stack_b = NULL;
	data->operations = NULL;
	data->operations_counter = 0;
	data->stack_a_size= argc-1;
	data->stack_b_size = 0;
	printf(BLUE"\nBefore:\n"RESET);
	print_stacks(data);
	
	create_indices(data);
	sort(data);
	list_optimisation(data);
	print_ops(data);
	
	printf(TURQ"\nAfter:\n"RESET);
	print_stacks(data);

	
	//FREE
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	free_nodes(data->operations);
	free(data);
	return (1);
}


int print_stacks(t_ps *data)
{
	t_node *tmp_a = data->stack_a;
	t_node *tmp_b = data->stack_b;

	size_t a = data->stack_a_size;
	size_t b = data->stack_b_size;

	if (a==0 && b ==0)
	{
		printf(PURP"A: (empty)	 	B: (empty)\n");
		return (0);
	}
	printf(PURP"	Stack A	| Stack B\n");
	printf("-------------------------------\n");

	while ((a + b) > 0)
	{
		if(a == 0 && b > 0)
		{
			printf(PURP"	-		|	%d\n"RESET, tmp_b->num );
			tmp_b=tmp_b->next;
			b--;
		}
		if(a > 0 && b==0)
		{
			printf(PURP"	%d	|	-\n"RESET, tmp_a->num);
			tmp_a=tmp_a->next;
			a--;
		}
		if(a > 0 && b > 0)
		{
			printf(PURP"	%d	|	%d\n"RESET, tmp_a->num, tmp_b->num);
			tmp_a=tmp_a->next;
			tmp_b=tmp_b->next;
			a--;
			b--;
		}
	}
	return (1);
}
