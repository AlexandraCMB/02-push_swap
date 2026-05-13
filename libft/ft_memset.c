/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:42:40 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/03 11:28:22 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
