/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:12 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/25 16:34:04 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_indices(t_ps *data)
{
	int	len;
	int	i;
	int	*arr;
	t_node *tmp;

	len = data->stack_a->size;
	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return ;
	tmp = data->stack_a->head;
	while (i < len)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, len);
	assign_indices(tmp, arr, len);
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
		while (x < len)
		{
			if (arr[x] == head->num)
			{
				head->idx = x;
				//printf("Assigned index %ld to value %d\n", head->idx, head->data);
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
	while (i >= 0 && arr[i] <= arr[i + 1])
		i--;
	return (i);
}
