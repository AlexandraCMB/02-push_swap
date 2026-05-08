/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunj <brunj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:12 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/08 13:56:59 by brunj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Create the indices for each node in stack_a (done at the start of the program)
void	create_indices(t_ps *data)
{
	int	len;
	int	i;
	int	*arr;
	t_node *tmp;

	len = data->size_of_list;
	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	tmp = data->stack_a;
	if (!arr)
		return ;
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

//Parsing through the stack and assigning the correct index to each node (done at the start of the program)
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
				break ;
			}
			x++;
		}
		x = 0;
		head = head->next;
	}
	return ;
}

//Bubble sort to sort the array of numbers (done at the start of the program)
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
