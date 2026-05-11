/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:46:35 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/11 18:12:37 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicates_in_input(int argc, char **argv)
{
    int x = argc;
    int i = 1;
    int j;
    while(i < x - 1)
    {
        j = i+1;
        while(j < x )
        {
            if(argv[i] == argv[j])
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}