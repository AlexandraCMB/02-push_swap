/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/13 19:16:05 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void check_inputs(int argc, char **argv)
{
	char	**tmp;

	if (argc < 2 || (argv[1][0] == '\0' && argc == 2))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
		tmp = argv + 1;//FISH
	int z = 0;
	while(tmp[z])
	{
		printf("tmp[%d] - %s\n",z,tmp[z]);
		z++;
	}
	if(invalid_input(tmp))
	{
		// free_split(tmp);//FISH
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return ;
	
}


int invalid_input(char **tmp)
{
	int i = 0;
	int err = 0;
	while(tmp[i])
	{
		if(input_checker(tmp[i]))
		{
			err = 1;
			printf("input_check flag\n");
		}
		i++;
	}
	i = 0;
	while(tmp[i])
	{
		if(int_overflow(ft_atoi(tmp[i])))
		{
			err = 1;
			printf("int_overflow flag\n");
		}
		i++;
	}
	if(duplicates_in_input(tmp))
	{
		err = 1;
		printf("duplicates_in_input flag\n");
	}
	printf("err is %d\n", err);
	return(err);
}

int	input_checker(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
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
	return (0) ;
}

int	duplicates_in_input(char **tmp)
{
	int	i;
	int j;

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

int	int_overflow(long int num)
{
	int	x;

	x = (int)num;
	if ((long int)x != num)
		return (1);
	return (0);
}
