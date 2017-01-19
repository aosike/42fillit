/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:17:10 by agundry           #+#    #+#             */
/*   Updated: 2016/12/09 02:23:38 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	uc = c;
	d = dst;
	s = src;
	if (n)
	{
		while (n > 0)
		{
			*d = *s;
			if ((*d) == uc)
				return (++d);
			d++;
			s++;
			n--;
		}
	}
	return (0);
}
