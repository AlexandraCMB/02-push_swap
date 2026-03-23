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

void	create_indices(t_node *stack)
{
	int	len;
	int	i;
	int	*arr;

	len = stack_len(stack);
	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return ;
	while (i < len)
	{
		arr[i] = stack->data;
		stack = stack->next;
		i++;
	}
	bubble_sort(arr, len);
	assign_indices(stack, arr, len);
	free(arr);
	return ;
}

void	assign_indices(t_node *stack, int *arr, int len)
{
	t_node	*head;
	int		entry;
	int		x;

	head = stack;
	entry = 1;
	x = 0;
	while (head != stack || entry == 1)
	{
		entry = 0;
		while (x <= len)
		{
			if (arr[x] == head->data)
			{
				head->idx = x;
				printf("head[data, idx]->[%d, %zu] \n", head->data, head->idx);
				break ;
			}
			x++;
		}
		x = 0;
		head = head->next;
	}
	return ;
}

void	bubble_sort(int *arr, int len)
{
	int	order_checker;
	int	tmp;
	int	x;

	x = 0;
	order_checker = in_order(arr, len);
	while (order_checker != -1)
	{
		while (x < len - 1)
		{
			if (arr[x] > arr[x + 1])
			{
				tmp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = tmp;
			}
			x++;
		}
		x = 0;
		order_checker = in_order(arr, len);
	}
	return ;
}

int	in_order(int *arr, int len)
{
	int	i;

	i = len - 2;
	while (arr[i] && arr[i] <= arr[i + 1] && i >= 0)
		i--;
	return (i);
}
