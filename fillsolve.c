/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillsolve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:03:13 by tbisi             #+#    #+#             */
/*   Updated: 2017/02/02 15:11:36 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*solve(char **minos, size_t *wptr)
{
	char	*result;
	size_t	w;

	*wptr = smallsq(minos);
	w = *wptr;
	while (!(fillit(minos, w, 0, (result = periods(ft_strnew(w * w), w)))))
	{
		w++;
		free(result);
		result = NULL;
	}
	*wptr = w;
	return (result);
}

char			*periods(char *str, size_t w)
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i++ < (w * w))
		*s++ = '.';
	return (str);
}

int				fillit(char **minos, size_t w, size_t spot, char *result)
{
	static size_t	minocount;
	static size_t	placecount;
	static size_t	wtmp;

	if (wtmp != w)
	{
		wtmp = w;
		placecount = 0;
		minocount = countminos(minos);
	}
	if (placecount == minocount)
		return (1);
	while (result[spot] && placecount < minocount)
	{
		if (placemino(minos[placecount], result, spot, w))
		{
			placecount++;
			if (fillit(minos, w, findnextspot(result), result))
				return (1);
			deletemino(minos[placecount -= 1], result);
		}
		spot++;
	}
	return (0);
}

int				placemino(char *min, char *result, size_t spot, int w)
{
	int	i;

	while (*min++ == '.')
		spot++;
	min--;
	while (*min)
	{
		while (*min != '.' && *min)
		{
			if (result[spot] != '.' || (*(min + 1)
						&& *(min + 1) != '.' && ((spot + 1) % w) == 0))
			{
				deletemino(min, result);
				return (0);
			}
			else if (result[spot] == '.')
				result[spot++] = *min++;
		}
		i = 0;
		while (*min++ == '.')
			i++;
		min--;
		spot += w - (5 - i);
	}
	return (1);
}
