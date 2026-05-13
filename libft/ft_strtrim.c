/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:33:55 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/11 17:37:36 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set);
static int	find_start(char *s1, char const *set);
static int	find_end(char *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s_start;
	char	*s_end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	s_start = (char *)s1;
	s_end = (char *)s1;
	i = find_start(s_start, set);
	j = find_end(s_end, set);
	trim = ft_substr(s1, i, (j - i));
	return (trim);
}

static int	is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	find_start(char *s1, char const *set)
{
	int	i;

	i = 0;
	while (*s1 && is_in_set(*s1, set))
	{
		s1++;
		i++;
	}
	return (i);
}

static int	find_end(char *s1, char const *set)
{
	int		j;
	char	*end;

	j = ft_strlen(s1);
	end = s1 + j - 1;
	while (end && is_in_set(*end, set))
	{
		end--;
		j--;
	}
	return (j);
}
