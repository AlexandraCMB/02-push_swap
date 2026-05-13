/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:25:13 by brunj             #+#    #+#             */
/*   Updated: 2026/05/13 14:08:02 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_optimisation(t_ps *data)
{
	int		i;
	t_node	*tmp;

	i = data->operations_counter;
	tmp = data->operations;
	while (i-- > 1)
	{
		if (operation_pair_check(tmp) == 1)
		{
			remove_next_node(tmp);
			data->operations_counter -= 1;
			tmp->num = RR;
		}
		else if (operation_pair_check(tmp) == 2)
		{
			remove_next_node(tmp);
			data->operations_counter -= 1;
			tmp->num = RRR;
		}
		tmp = tmp->next;
	}
	return ;
}

int	operation_pair_check(t_node *operation)
{
	if ((operation->num == RA && operation->next->num == RB)
		|| (operation->num == RB && operation->next->num == RA))
		return (1);
	if ((operation->num == RRA && operation->next->num == RRB)
		|| (operation->num == RRB && operation->next->num == RRA))
		return (2);
	return (0);
}
