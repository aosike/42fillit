/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agundry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:52:36 by agundry           #+#    #+#             */
/*   Updated: 2016/12/14 17:21:37 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (neg * nbr);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (neg * nbr);
}
