/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:54:58 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/14 15:18:16 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/ft_printf.h"

static const char	*op_to_str(t_op op);

//Logging operations in linked list
void	log_op(t_ps *data, t_op op)
{
	insert_at_back(&data->operations, op);
	data->operations_counter += 1;
	return ;
}

//Printing operations to stdout - by iteration through operations list
void	print_ops(t_ps *data)
{
	t_node	*tmp;
	int		size;

	tmp = data->operations;
	size = data->operations_counter;
	if (!data || !data->operations)
		return ;
	while (size-- > 0 && tmp != NULL)
	{
		ft_printf("%s\n", op_to_str(tmp->num));
		tmp = tmp->next;
	}
	return ;
}

//Array of strings to define the ops simplified with use of enum.
//No safety implemented since function can't call outside bounds.
static const char	*op_to_str(t_op op)
{
	char	*ops[11];

	ops[0] = "sa";
	ops[1] = "sb";
	ops[2] = "ss";
	ops[3] = "pa";
	ops[4] = "pb";
	ops[5] = "ra";
	ops[6] = "rb";
	ops[7] = "rr";
	ops[8] = "rra";
	ops[9] = "rrb";
	ops[10] = "rrr";
	return (ops[op]);
}
