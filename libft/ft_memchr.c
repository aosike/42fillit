/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:58:49 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:50:43 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
		}
	}
	return (NULL);
}
