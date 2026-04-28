/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:41:19 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/28 13:12:55 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//freeing linked list nodes
void free_nodes(t_node *list)
{
	t_node *tmp;
	t_node *next;
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
