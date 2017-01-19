/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:41:44 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:48:27 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;

	len = (ft_strlen(s1) + 1);
	if ((result = (char *)malloc(len)))
	{
		return (ft_strcpy(result, s1));
	}
	return (NULL);
}
