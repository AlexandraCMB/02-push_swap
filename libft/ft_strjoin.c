/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:16:03 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/14 15:32:22 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dest_len;
	char	*dest;
	char	*startdest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest_len = s1_len + s2_len;
	if (!s1 && !s2)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (dest_len + 1));
	if (!dest)
		return (NULL);
	startdest = dest;
	while (s1_len-- > 0)
		*dest++ = *s1++;
	while (s2_len-- > 0)
		*dest++ = *s2++;
	*dest = '\0';
	return (startdest);
}
