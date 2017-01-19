/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:38:18 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:45:53 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (*little)
	{
		while (*big && len != 0)
		{
			n = 0;
			while (*(big + n) == *(little + n) && n < len)
			{
				n++;
				if (!(*(little + n)))
					return ((char *)big);
			}
			big++;
			len--;
		}
		return (NULL);
	}
	else
		return ((char *)big);
}
