/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:25:05 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/14 18:49:34 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->num = num;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

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

t_node	*insert_at_back(t_node **head, int num)
{
	t_node	*newnode;
	t_node	*tail;

	newnode = create_node(num);
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
		{
			input_checker(argv[i]);
			stack = insert_at_back(&stack, ft_atoi(argv[i]));
			i++;
		}
	}
	return (stack);
}


