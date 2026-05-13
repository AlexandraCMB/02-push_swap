/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:12:54 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/14 14:43:19 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	if (size == 0 && !dst)
		return (0);
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (size <= d)
		return (size + s);
	while (src[i] && (d + i) < (size - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
