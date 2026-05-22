/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:54 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/22 16:43:10 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	list_not_in_order(t_ps *data);

void	sort(t_ps *data)
{
	size_t	len;

	len = data->size_of_list;
	if (len == 1 || list_not_in_order(data) == 0)
	{
		free_all(data);
		exit_message(0);
	}
	else if (len == 2)
	{
		if (data->stack_a->num > data->stack_a->next->num)
			swap_a(data);
	}
	else if (len == 3)
		sort_three(data);
	else if (len == 4)
		sort_four(data);
	else if (len == 5)
		sort_five(data);
	else
		butterfly_sort(data);
	return ;
}

//Sorting three numbers in A
void	sort_three(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->num;
	second = data->stack_a->next->num;
	third = data->stack_a->prev->num;
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
	return ;
}

void	sort_five(t_ps *data)
{
	while (data->stack_a_size > 3)
	{
		if (data->stack_a->idx == 0 || data->stack_a->idx == 1)
			push_b(data);
		if (data->stack_a->prev->idx == 0 || data->stack_a->prev->idx == 1)
		{
			rev_rot_a(data);
			push_b(data);
		}
		else
			rot_a(data);
	}
	sort_three(data);
	if (data->stack_b->idx == 0)
		rot_b(data);
	push_a(data);
	push_a(data);
	return ;
}

void	sort_four(t_ps *data)
{
	push_b(data);
	sort_three(data);
	if (data->stack_b->idx == 0)
		push_a(data);
	else if (data->stack_b->idx == 1)
	{
		push_a(data);
		swap_a(data);
	}
	else if (data->stack_b->idx == 2)
	{
		rot_a(data);
		push_a(data);
		swap_a(data);
		rev_rot_a(data);
	}
	else if (data->stack_b->idx == 3)
	{
		push_a(data);
		rot_a(data);
	}
	return ;
}

static int	list_not_in_order(t_ps *data)
{
	int		i;
	t_node	*tmp;

	i = data->size_of_list;
	tmp = data->stack_a;
	while (i > 1)
	{
		if (tmp->idx > tmp->next->idx)
			return (1);
		tmp = tmp->next;
		i--;
	}
	return (0);
}
