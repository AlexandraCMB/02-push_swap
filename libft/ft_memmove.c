/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:54:45 by abrunjes          #+#    #+#             */
/*   Updated: 2025/11/05 15:48:22 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s == d)
		return (dest);
	if (s < d && s + n > d)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
/*
int main(void)
{
	char d[] = "0123";
	char *s = d + 2;
	size_t n = 0;
	printf("||SOURCE BEFORE is: %s\n", s);
	printf("||DEST BEFORE is: %s\n", d);
	printf("||SRC after of DST - copy forward||\n");
	printf("AFTER\n");
	while (n < 8)
	{
		char d1[] = "0123";
		char *s1 = d1 + 2;
		printf("n = %ld\n", n);
		ft_memmove(d1, s1, n);
		printf("Src after is: %s\n", s1);
		printf("Dst after is: %s\n----------\n", d1);
		n++;
	}

	char ss[] = "0123";
	char *dd = ss + 2;
	size_t m = 0;
	printf("~~~~~~~~~~~~\n||SOURCE is:    %s\n", ss);
	printf("||DEST BEFORE is: %s\n", dd);
	printf("||DST after  SRC -- copy backward||\n");
	printf("AFTER\n");
	while (m < 8)
	{
		char ss1[] = "0123";
		char dd1[] = "2345";
		printf("n = %ld\n", m);
		ft_memmove(dd1, ss1, m);
		printf("Src after is: %s\n", ss1);
		printf("Dst after is: %s\n----------\n", dd1);
		m++;
	}
	return (0);
}

 */
