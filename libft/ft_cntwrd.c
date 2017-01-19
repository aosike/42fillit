/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:33:06 by agundry           #+#    #+#             */
/*   Updated: 2016/12/08 21:26:27 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntwrd(const char *s1)
{
	const char	*s;
	size_t		i;

	s = s1;
	i = 0;
	while (*s)
	{
		while (ft_isspace(*s++))
			;
		if (!(ft_isspace(*s++)))
		{
			i++;
			while (!(ft_isspace(*s++)))
				;
		}
	}
	return (i);
}
