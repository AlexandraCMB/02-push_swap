/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:07:23 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/14 14:54:03 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*mall;
	char	*scheck;

	scheck = (char *)s;
	size = ft_strlen(scheck) + 1;
	mall = malloc(size * sizeof(char));
	if (!mall)
		return (NULL);
	ft_memcpy(mall, s, size);
	return (mall);
}
