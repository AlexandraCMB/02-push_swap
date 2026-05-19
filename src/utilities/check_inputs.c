/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/19 14:27:05 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static int	invalid_input(char **tmp);
static int	input_checker(char *str);
static int	duplicates_in_input(char **tmp);
static int	int_overflow(long int num);

//Funciton to check validity of inputs - first sorts parsing of inputs
//i.e. if ./p_s "" or without
void	check_inputs(int argc, char **argv)
{
	char	**tmp;
	int		split;

	split = 0;
	if (argc < 2)
		exit_message(0);
	if ((argv[1][0] == '\0' && argc == 2))
		exit_message(1);
	else if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		split = 1;
	}
	else
		tmp = argv + 1;
	if (invalid_input(tmp))
	{
		if (split)
			free_split(tmp);
		exit_message(1);
	}
	if (split)
		free_split(tmp);
	return ;
}

//calling on below functions checks vlaidity of inputs
// ie numbers only (w/ +/-), integer range and no duplicates
static int	invalid_input(char **tmp)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (tmp[i])
	{
		if (input_checker(tmp[i]))
			err = 1;
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		if (int_overflow(ft_atoi(tmp[i])))
			err = 1;
		i++;
	}
	if (duplicates_in_input(tmp))
		err = 1;
	return (err);
}

//Is input a digit with wither -/+ before
static int	input_checker(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	no_num_found(str);
	while (len--)
	{
		i = 0;
		while (str[i] == ' ' )
			i++;
		if (str[i] == '-' || str[i] == '+' )
			i++;
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
		str++;
	}
	return (0);
}

//Duplicate inputs not allowed
static int	duplicates_in_input(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i] && tmp[i + 1])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (ft_strcmp(tmp[i], tmp[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Inputs outside of [INT_MIN, INT_MAX]
static int	int_overflow(long int num)
{
	int	x;

	x = (int)num;
	if ((long int)x != num)
		return (1);
	return (0);
}
