/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:03:54 by agundry           #+#    #+#             */
/*   Updated: 2016/12/18 18:22:41 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char *p2;

	p1 = (const unsigned char *)malloc(sizeof(s1));
	p2 = (const unsigned char *)malloc(sizeof(s2));
	p1 = s1;
	p2 = s2;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
			n--;
		}
	}
	return (0);
}
