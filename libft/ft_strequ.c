/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:56:03 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 15:17:38 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char const	*one;
	char const	*two;

	if (!s1 || !s2)
		return (0);
	one = s1;
	two = s2;
	while (*one || *two)
	{
		if (*one++ != *two++)
			return (0);
	}
	return (1);
}
