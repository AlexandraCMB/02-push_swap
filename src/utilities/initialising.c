/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:46:35 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/12 14:53:41 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_and_initialise_data(t_ps *data, int argc, char **argv)
{
	int		i;
	char	**arg_v;

	i = 1;
	if (argc < 2)
		return ;
	if (argc == 2)
	{
		arg_v = ft_split(argv[1], ' ');
		argc = 1 + word_count(argv[1], ' ');
		i = 0;
	}
	else
		arg_v = argv;
	if (duplicates_in_input(i, argc, arg_v))
	{
		write(2,("Error\n",6);
		exit(EXIT_FAILURE);
	}
	initialise_data(data, i, argc, arg_v);
}

void	push_swap(t_ps *data)
{
	create_indices(data);
	sort(data);
	list_optimisation(data);
	print_ops(data);
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
	free_split(i, arg_v);
}

int	duplicates_in_input(int i, int argc, char **arg_v)
{
	int	j;

	while (arg_v[i] && i < argc - 1)
	{
		j = i + 1;
		while (arg_v[j])
		{
			if (ft_strcmp(arg_v[i], arg_v[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
