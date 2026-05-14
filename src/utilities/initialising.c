/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:46:35 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/14 14:09:31 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	pars_inputs(t_ps *data, int argc, char **argv)
{
	char	**arg_v;
	int		split;

	split = 0;
	if (argc == 2)
	{
		arg_v = ft_split(argv[1], ' ');
		argc = 1 + word_count(argv[1], ' ');
		split = 1;
	}
	else
		arg_v = argv + 1;
	initialise_data(data, argc, arg_v);
	if (split)
		free_split(arg_v);
	return ;
}

void	initialise_data(t_ps *data, int argc, char **arg_v)
{
	data->stack_a = init_stack(arg_v);
	data->size_of_list = argc - 1;
	data->stack_b = NULL;
	data->operations = NULL;
	data->operations_counter = 0;
	data->stack_a_size = argc - 1;
	data->stack_b_size = 0;
	return ;
}
