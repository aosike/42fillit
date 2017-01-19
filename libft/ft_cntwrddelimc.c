/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrddelimc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:26:56 by agundry           #+#    #+#             */
/*   Updated: 2016/12/13 16:10:33 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntwrddelimc(const char *str, char c)
{
	const char	*s;
	size_t		i;

	s = str;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			i++;
			while (*s++ != c && *s)
				;
		}
	}
	return (i);
}
