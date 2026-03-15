/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:46:23 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:39:01 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int print_stacks(t_node *stack_a, t_node *stack_b)
{
	// if(stack_a->prev)
	// 	stack_a=stack_a->prev;
	// if(stack_b->prev)
	// 	stack_b=stack_b->prev;
	t_node *tmp_a = stack_a;
	t_node *tmp_b = stack_b;
	int first_pass = 1;

	if (!stack_a && !stack_b)
	{
		printf("A: (empty)  B: (empty)\n");
		return (0);
	}
	printf("	Stack A	 |   Stack B\n");
	printf("-------------------------------\n");

	while (tmp_a && (first_pass || tmp_a != stack_a))
	{
	first_pass = 0;
	printf("	%d	", tmp_a->data);
	tmp_a = tmp_a->next;
	if (tmp_b)
	{
		printf(" |	%d\n", tmp_b->data);
		tmp_b = tmp_b->next;
		if (tmp_b == stack_b)
			tmp_b = NULL;
	}
	else
		printf(" |	-\n");
	}
	return (1);
}

int main (int argc, char **argv)
{
	int i;
	t_node *stack_a;
	t_node *stack_b;
	
	i = 1;
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	printf("Before:\n");
	print_stacks(stack_a, stack_b);
	//printf("Operation: ");
	//op_pb(&stack_a, &stack_b);
	printf("\nAfter:\n");
	print_stacks(stack_a, stack_b);
	return (1);
}


// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.
