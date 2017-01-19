/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:16:36 by agundry           #+#    #+#             */
/*   Updated: 2016/12/12 20:31:29 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*d;
	const char	*src;

	if (s)
	{
		if (!(d = ft_memalloc(len + 1)))
			return (NULL);
		src = &s[start];
		ft_strncpy(d, src, len);
		d[len + 1] = '\0';
		return (d);
	}
	return (NULL);
}
