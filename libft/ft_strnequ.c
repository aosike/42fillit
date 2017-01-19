/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:05:20 by agundry           #+#    #+#             */
/*   Updated: 2016/12/12 13:30:18 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char const	*one;
	char const	*two;

	if (s1 && s2)
	{
		one = s1;
		two = s2;
		while (n-- > 0 && (*one || *two))
		{
			if (*one++ != *two++)
				return (0);
		}
		return (1);
	}
	return (0);
}
