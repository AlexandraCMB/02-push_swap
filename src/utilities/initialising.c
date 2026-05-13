/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:46:35 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 19:19:07 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	pars_inputs(t_ps *data, int argc, char **argv)
{
	int		i;
	char	**arg_v;

	i = 1;
	
	if (argc == 2)
	{
		arg_v = ft_split(argv[1], ' ');
		argc = 1 + word_count(argv[1], ' ');
		i = 0;
	}
	else
		arg_v = argv + 1;
	printf("here\n");
	int z = 0;
	while(arg_v[z])
	{
		printf("arg_v[%d] - %s\n",z,arg_v[z]);
		z++;
	}
	initialise_data(data, i, argc, arg_v);
	return ;
}

void	initialise_data(t_ps *data, int i, int argc, char **arg_v)
{
	data->stack_a = init_stack(i, arg_v);
	data->size_of_list = argc - 1;
	data->stack_b = NULL;
	data->operations = NULL;
	data->operations_counter = 0;
	data->stack_a_size = argc - 1;
	data->stack_b_size = 0;
	printf("--- DEBUG: Data Initialization ---\n");
	printf("stack_a (pointer):    %p\n", (void *)data->stack_a);
	printf("stack_b (pointer):    %p\n", (void *)data->stack_b);
	printf("size_of_list:         %ld\n", data->size_of_list);
	printf("stack_a_size:         %ld\n", data->stack_a_size);
	printf("stack_b_size:         %ld\n", data->stack_b_size);
	printf("operations (ptr):     %p\n", (void *)data->operations);
	printf("ops_counter:          %ld\n", data->operations_counter);
	printf("----------------------------------\n");
	return ;
}

