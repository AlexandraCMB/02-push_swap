/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:39:44 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/11 17:38:05 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	char const		*offset;
	unsigned int	s_len;
	unsigned int	bytes;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len + start > s_len)
		bytes = s_len - start;
	else
		bytes = len;
	d = malloc((sizeof(char) * bytes) + 1);
	if (!d)
		return (NULL);
	offset = (s + start);
	ft_memmove(d, offset, bytes);
	d[bytes] = '\0';
	return (d);
}
