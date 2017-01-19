/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:27:21 by agundry           #+#    #+#             */
/*   Updated: 2016/12/18 18:27:23 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**result;
	const char	*str;
	size_t		lcnt;
	size_t		wcnt;

	if (!s)
		return (NULL);
	str = s;
	wcnt = ft_cntwrddelimc(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (wcnt + 1))))
		return (NULL);
	while (wcnt--)
	{
		while (*str == c && *str)
			str++;
		lcnt = 0;
		while (str[lcnt] != c && str[lcnt] != '\0')
			lcnt++;
		*result++ = ft_strsub(str, 0, lcnt);
		str += lcnt;
	}
	*result = 0;
	return (result - (ft_cntwrddelimc(s, c)));
}
