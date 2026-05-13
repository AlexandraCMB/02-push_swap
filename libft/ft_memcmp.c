/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:39:14 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/09 20:05:36 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*m1;
	const unsigned char	*m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (n--)
	{
		if (*m1 != *m2 && (*m1 || *m2))
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	return (0);
}
