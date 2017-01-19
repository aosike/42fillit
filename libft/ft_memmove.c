/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:04:01 by agundry           #+#    #+#             */
/*   Updated: 2016/12/04 17:34:08 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		n;

	n = len;
	s = src;
	d = dst;
	if (s < d)
	{
		s += n;
		d += n;
		while (n-- > 0)
			*--d = *--s;
	}
	else
		while (n-- > 0)
			*d++ = *s++;
	return (dst);
}
