/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:25:05 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:35:17 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	

t_node *insert_at_beginning(t_node **head, t_node *newNode)
{
	if(!(*head))
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		(*head) = newNode;
	}
	else
	{
		t_node* tail = (*head)->prev;
		newNode->next = (*head);
		newNode->prev = tail;
		(*head)->prev = newNode;
		tail->next = newNode;
		(*head) = newNode;
    }
    return (*head);
  }


