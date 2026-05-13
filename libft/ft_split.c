/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:39:06 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/12 16:22:07 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c);
static char		*word_make(char const *s, char c);
static int		word_len(char const *s, char c);
static char		**freedom(char **s, int i);

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**mpointer;
	int		i;

	wc = word_count(s, c);
	mpointer = malloc(sizeof(char *) * (wc + 1));
	if (!s || !(mpointer))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			mpointer[i] = word_make(s, c);
			if (!mpointer[i])
				return (freedom(mpointer, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	mpointer[i] = NULL;
	return (mpointer);
}

//size to malloc fo **mpointer
static int	word_count(char const *s, char c)
{
	int	check;
	int	words;

	check = 1;
	words = 0;
	while (*s)
	{
		if (*s != c && check)
		{
			words++;
			check = 0;
		}
		if (*s == c)
			check = 1;
		s++;
	}
	return (words);
}

//s here is actuall word. not delimieter!!
static char	*word_make(char const *s, char c)
{
	int		letters;
	char	*mchar;
	int		i;

	i = 0;
	letters = word_len(s, c);
	mchar = malloc(sizeof(char) * (letters + 1));
	if (!mchar)
		return (NULL);
	*(mchar + letters) = '\0';
	while (i < letters)
	{
		mchar[i] = s[i];
		i++;
	}
	return (mchar);
}

//modified strlen in otder to use in word_make
static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**freedom(char **s, int i)
{
	while (i > 0)
		free(s[--i]);
	free(s);
	return (NULL);
}
