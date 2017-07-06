/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:02:56 by tbisi             #+#    #+#             */
/*   Updated: 2017/01/25 20:15:52 by tbisi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			findnextspot(char *result)
{
	size_t	siz;

	siz = 0;
	while (result[siz] && result[siz] != '.')
		siz++;
	return (siz);
}

size_t			countminos(char **minos)
{
	char	**min;
	size_t	i;

	i = 0;
	min = minos;
	while (*min != NULL)
	{
		min++;
		i++;
	}
	return (i);
}

void			deletemino(char *mino, char *result)
{
	char *res;
	char *min;

	min = mino;
	res = result;
	while (*min == '.')
		min++;
	while (*res)
	{
		*res = *res == *min ? '.' : *res;
		res++;
	}
}

int				uniquemino(char *mino, char *result)
{
	char	*res;
	char	*min;

	res = result;
	min = mino;
	while (*min == '.')
		min++;
	while (*res)
	{
		if (*res == *min)
			return (0);
		res++;
	}
	return (1);
}

int				smallsq(char **pcs)
{
	int size;
	int sq;

	sq = 2;
	size = (countminos(pcs) * 4);
	while ((sq * sq) < size)
		sq++;
	return (sq);
}
