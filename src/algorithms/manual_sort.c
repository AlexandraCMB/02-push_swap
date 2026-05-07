/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:54 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/07 18:51:52 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sorting two numbers in A
void sort(t_ps *data)
{
	size_t len = data->list_size;
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
		printf("\nDo main_algo(data) here\n");
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
	if(stack_in_order(data->stack_a)==1)
	{
		printf("in order\n");
		return;
	}
	push_b(data);
	push_b(data);
	sort_three(data);
	print_stacks(data);
	printf("--top of A is %d\n", data->stack_a->num);
	printf("--top of B is %d\n", data->stack_b->num);
	// int i = 4;
	while(data->stack_b  )
	{
		//top of B bigger than all of A
		if(max_in_stack(data->stack_a, data->stack_b->idx)==1)
		{
			while(data->stack_b->idx != data->stack_a->idx + 1)
				rev_rot_a(data);
			printf("MAX\n");
			print_stacks(data);
			push_a(data);
		//	rot_a(data);
		}
		//top of B smaller than all of A
		else if(min_in_stack(data->stack_a, data->stack_b->idx) )
		{
			while(data->stack_b->idx != data->stack_a->idx -1)
				rot_a(data);
			push_a(data);
			printf("MIN\n");
			print_stacks(data);

		}
		//top of B between values in A - rotate until spot found
		else
		{
			while(data->stack_b->idx != data->stack_a->idx -1)
				rot_a(data);
			push_a(data);
			printf("BETWEEN\n");
			print_stacks(data);

		}
	}
	print_stacks(data);
	while(data->stack_a->idx != 0)
	{
		print_stacks(data);
		if(cost_to_top_a(data, 0) > 2)
			rev_rot_a(data);
		else
			rot_a(data);
	}
	return;
}

//comparing if top of stack b is bigger than all of those in stack A (for sorting 5)
int max_in_stack(t_node *stack, size_t idx)
{
	int len;
	t_node *tmp;
	
	len = stack_len(stack);
	tmp = stack;
	while(len > 0)
	{
		if(tmp->idx > idx)
			return 0;
		tmp = tmp->next;
		len--;
	}

	return 1;
}

//comparing if top of stack b is smaller than all of those in stack A (for sorting 5)
int min_in_stack(t_node *stack, size_t idx)
{
	int len;
	t_node *tmp;
	
	len = stack_len(stack);
	tmp = stack;
	while(len > 0)
	{
		if(tmp->idx < idx)
			return 0;
		tmp = tmp->next;
		len--;
	}

	return 1;
}

int cost_to_top_a(t_ps *data, size_t num_in_list)
{
	int cost;
	int len;
	t_node *tmp;

	
	cost = 0;
	len = stack_len(data->stack_a);
	tmp = data->stack_a;
	if(len == 1)
		return 0;
	while(tmp->idx != tmp->next->idx && tmp->idx != num_in_list )
	{
		cost += 1;
		tmp = tmp->next;
	}
	return cost;
}

//check lentgh of stack - stack to be specified
int stack_in_order(t_node *stack)
{
	int len;
	t_node *tmp;
	
	len = stack_len(stack);
	tmp = stack;
	while(len > 1)
	{
		if(tmp->idx > tmp->next->idx)
			return 0;
		tmp = tmp->next;
		len--;
	}
	printf("here\n");

	return 1;
		

	
}