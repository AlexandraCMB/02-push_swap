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

t_node *createNode(int data) 
{
	t_node* newNode = (t_node*)malloc(sizeof(t_node));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return (newNode);
}

t_node *insert_at_back(t_node **head, int data)
{
	t_node *newNode = createNode(data);
	if(!(*head))
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		(*head) = newNode;
	}
	else
	{
		t_node* tail = (*head)->prev;
		tail->next =  newNode;
		(*head)->prev = newNode;
		newNode->next = (*head);
		newNode->prev = tail;
		tail = newNode;
	}
	return (*head);
}

t_node *init_stack(int argc, char **argv)
{
	int i = 1;
	t_node *stack;
	stack = NULL;
	if(argc > 1)
	{
		while(i < argc)
		{
			stack = insert_at_back(&stack ,atoi(argv[i]));
			i++;
		}
	}
	return(stack);
}

