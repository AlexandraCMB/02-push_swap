/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:54:58 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 14:07:56 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/ft_printf.h"

//Printing operationss to data->operations list
//Then function to print them at the end of the program
void	log_op(t_ps *data, t_op op)
{
	insert_at_back(&data->operations, op);
	data->operations_counter += 1;
	return ;
}

const char	*op_to_str(t_op op)
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

void	print_ops(t_ps *data)
{
	int		op_count;
	t_node	*tmp;
	int		size;

	op_count = 0;
	tmp = data->operations;
	size = data->operations_counter;
	if (!data || !data->operations)
		return ;
	while (size-- > 0 && tmp != NULL)
	{
		ft_printf("%s\n", op_to_str(tmp->num));
		op_count += 1;
		tmp = tmp->next;
	}
	return ;
}
