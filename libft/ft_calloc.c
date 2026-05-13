/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:48:47 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/05 15:41:38 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*m;
	size_t	x;

	x = nmemb * size;
	if (nmemb == 0 || size == 0)
		x = 0;
	if ((x != 0) && (x / nmemb != size))
		return (NULL);
	else
		m = malloc(x);
	if (m == NULL )
		return (NULL);
	ft_memset(m, 0, x);
	return (m);
}
