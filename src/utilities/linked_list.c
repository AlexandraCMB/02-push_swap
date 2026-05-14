/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:25:05 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/14 15:01:26 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static t_node	*create_node(int num);

//Numbers added to stack (in code data->stack_a)
t_node	*init_stack(char **args)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (args && args[i])
	{
		stack = insert_at_back(&stack, ft_atoi(args[i]));
		i++;
	}
	return (stack);
}

//CIRCULAR DOUBLY LINKED LISTS
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

void	remove_next_node(t_node *node)
{
	t_node	*to_remove;

	if (!node || !node->next)
		return ;
	to_remove = node->next;
	node->next = to_remove->next;
	to_remove->next->prev = node;
	free(to_remove);
	return ;
}

static t_node	*create_node(int num)
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
