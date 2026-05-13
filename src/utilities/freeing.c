/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:41:19 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 14:08:31 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//freeing linked list nodes
void	free_nodes(t_node *list)
{
	t_node	*tmp;
	t_node	*next;

	if (!list)
		return ;
	tmp = list;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		if (next == list)
			break ;
		tmp = next;
	}
	return ;
}

void	free_split(int i, char **arg_v)
{
	if (i == 0)
	{
		while (arg_v[i])
		{
			free(arg_v[i]);
			i++;
		}
		free(arg_v);
	}
	return ;
}

void	free_all(t_ps *data)
{
	free_nodes(data->stack_a);
	free_nodes(data->stack_b);
	free_nodes(data->operations);
	free(data);
	return ;
}
