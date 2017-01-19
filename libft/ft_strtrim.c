/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:45:11 by agundry           #+#    #+#             */
/*   Updated: 2016/12/18 18:27:38 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*result;
	size_t		siz;
	int			begin;
	int			end;

	end = 0;
	begin = 0;
	if (s)
	{
		while (s[end] != '\0')
			end++;
		while (ft_isspace(s[--end]))
			;
		end++;
		while (ft_isspace(s[begin]) && s[begin] != '\0')
			begin++;
		siz = end > begin ? (end - begin) : 0;
		if (siz == 0)
			result = ft_memalloc(1);
		else
			result = ft_strsub(s, begin, siz);
		return (result);
	}
	return (NULL);
}
