/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:07:49 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/14 14:52:26 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !big)
		return (0);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] && big[i + j] == little[j] && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
		j = 0;
	}
	return (NULL);
}

/*PLAN()
Scenario searching
1) if all little ⊂ big (to len) >> from little to end of big
2) '' some ""					>> NULL
3) empty little 				>> all big

4) LITTLE NEEDS TO BE NULL TERMINATED - not coded in though
5) If big isnt.. undefined behaaviour but not NULL

- Write STRSTR (modified so undefinded behaviour returns NULL ie
NEEDLE AND HAYSTACK BOTH HAVE TO BE NULL TERMED) - search for
n in haystack where haystack is restrict to size of  len
- say call it "big sub" if posso return "big"
^^stupid.. strstr is nearly there .. just add in length restriction

*/
