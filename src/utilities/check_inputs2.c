/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/19 14:39:07 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	no_num_found(char *str)
{
	int	i;
	int	num_found;

	i = 0;
	num_found = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num_found = 1;
		i++;
	}
	if (num_found == 0)
		return (0);
	return (1);
}
