/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:18 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/14 13:44:45 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*data;

	check_inputs(argc, argv);
	data = malloc(sizeof(t_ps));
	if (!data)
		free(data);
	pars_inputs(data, argc, argv);
	push_swap(data);
	free_all(data);
	return (1);
}

void	push_swap(t_ps *data)
{
	create_indices(data);
	sort(data);
	list_optimisation(data);
	print_ops(data);
	return ;
}
