/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:42:18 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/05 17:54:55 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*lo;

	d = (char) c;
	lo = NULL;
	while (*s != '\0')
	{
		if (*s == d)
			lo = ((char *) s);
		s++;
	}
	if (d == '\0')
		return ((char *) s);
	return (lo);
}
