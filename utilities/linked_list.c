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

#include "../push_swap.h"

t_node	*insert_at_beginning(t_node **head, t_node *newnode)
{
	t_node	*tail;

	if (!(*head))
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		(*head) = newnode;
	}
	else
	{
		tail = (*head)->prev;
		newnode->next = (*head);
		newnode->prev = tail;
		(*head)->prev = newnode;
		tail->next = newnode;
		(*head) = newnode;
	}
	return (*head);
}

t_node	*create_node(int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

t_node	*insert_at_back(t_node **head, int data)
{
	t_node	*newnode;
	t_node	*tail;

	newnode = create_node(data);
	if (!(*head))
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		(*head) = newnode;
	}
	else
	{
		tail = (*head)->prev;
		tail->next = newnode;
		(*head)->prev = newnode;
		newnode->next = (*head);
		newnode->prev = tail;
		tail = newnode;
	}
	return (*head);
}

t_node	*init_stack(int argc, char **argv)
{
	int		i;
	t_node	*stack;

	i = 1;
	stack = NULL;
	if (argc > 1)
	{
		while (i < argc)
			stack = insert_at_back(&stack, atoi(argv[i++]));
	}
	return (stack);
}
