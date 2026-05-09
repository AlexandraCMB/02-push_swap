/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:54 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/09 16:49:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sorting two numbers in A
void sort(t_ps *data)
{
	size_t len = data->size_of_list;
	if (len == 2)
	{
		if (data->stack_a->num > data->stack_a->next->num)
			swap_a(data);
	}
	else if (len == 3)
		sort_three(data);
	else if (len == 4)
		printf("\nDo sort_four(data) here\n");
	else if (len == 5)
		sort_five(data);
	else
		chunk_sort(data);
}

//Sorting three numbers in A
void sort_three(t_ps *data)
{
	int first = data->stack_a->num;
	int second = data->stack_a->next->num;
	int third = data->stack_a->prev->num;

	if (first > second && second < third && first < third)
		swap_a(data);
	else if (first < second && second > third && first > third)
		rev_rot_a(data);
	else if (first > second && second < third && first > third)
		rot_a(data);
	else if (first < second && second > third && first < third)
	{
		rev_rot_a(data);
		swap_a(data);
	}
	else if (first > second && second > third)
	{
		swap_a(data);
		rev_rot_a(data);
	}
}

void sort_five(t_ps *data)
{
	while(stack_len(data->stack_a) > 3)
	{
		if(data->stack_a->idx == 0 || data->stack_a->idx == 1)
			push_b(data);
		if(data->stack_a->prev->idx == 0 || data->stack_a->prev->idx == 1)
		{
			rev_rot_a(data);
			push_b(data);
		}
		else
			rot_a(data);
	}
	sort_three(data);
	if(data->stack_b->idx == 0)
		rot_b(data);
	push_a(data);
	push_a(data);
	
}

//comparing if top of stack b is bigger than all of those in stack A (for sorting 5)
// int max_in_stack(t_node *stack, size_t idx)
// {
// 	int len;
// 	t_node *tmp;
	
// 	len = stack_len(stack);
// 	tmp = stack;
// 	while(len > 0)
// 	{
// 		if(tmp->idx > idx)
// 			return 0;
// 		tmp = tmp->next;
// 		len--;
// 	}

// 	return 1;
// }

//comparing if top of stack b is smaller than all of those in stack A (for sorting 5)
// int min_in_stack(t_node *stack, size_t idx)
// {
// 	int len;
// 	t_node *tmp;
	
// 	len = stack_len(stack);
// 	tmp = stack;
// 	while(len > 0)
// 	{
// 		if(tmp->idx < idx)
// 			return 0;
// 		tmp = tmp->next;
// 		len--;
// 	}

// 	return 1;
// }


//check lentgh of stack - stack to be specified
// int stack_in_order(t_node *stack)
// {
// 	int len;
// 	t_node *tmp;
	
// 	len = stack_len(stack);
// 	tmp = stack;
// 	while(len > 1)
// 	{
// 		if(tmp->idx > tmp->next->idx)
// 			return 0;
// 		tmp = tmp->next;
// 		len--;
// 	}
// 	printf("here\n");

// 	return 1;
// }