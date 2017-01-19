/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:12:41 by agundry           #+#    #+#             */
/*   Updated: 2016/12/18 18:26:01 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*one;
	const char	*two;
	char		*result;
	size_t		i;
	size_t		j;

	one = s1;
	two = s2;
	if (one && two)
	{
		i = ft_strlen(one);
		j = ft_strlen(two);
		if (!(result = ft_memalloc(i + j + 1)))
			return (NULL);
		ft_strncpy(result, one, i);
		ft_strncpy((result + i), two, j);
		return (result);
	}
	return (NULL);
}
