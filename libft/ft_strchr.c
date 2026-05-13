/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:55:25 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/09 16:54:11 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = (char) c;
	while (*s != '\0')
	{
		if (*s == d)
			return ((char *)s);
		s++;
	}
	if (*s == d)
		return ((char *)s);
	else
		return (NULL);
}
