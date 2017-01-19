/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:36:17 by agundry           #+#    #+#             */
/*   Updated: 2017/01/11 15:36:47 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_memset.c"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(new, '\0', (size + 1));
	return (new);
}
