/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:18 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/12 14:52:11 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*data;

	data = malloc(sizeof(t_ps));
	if (!data)
		free(data);
	parse_and_initialise_data(data, argc, argv);
	push_swap(data);
	free_all(data);
	return (1);
}
