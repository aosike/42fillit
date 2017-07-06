/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillvalid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:16:14 by tbisi             #+#    #+#             */
/*   Updated: 2017/01/25 20:20:57 by tbisi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				validate(char *piece)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*piece && *piece != '\n')
	{
		i = 0;
		while ((*piece == '.' || *piece == '#') && i++ < 5)
			piece++;
		if (*piece == '\n' && i == 4)
		{
			piece++;
			j++;
		}
		else
			return (0);
	}
	if ((*piece == '\n' || *piece == '\0') && j == 4)
		return (1);
	return (0);
}

int				incheck(char *in)
{
	size_t	connections;
	size_t	spots;
	size_t	spot;

	connections = 0;
	spots = 0;
	spot = 0;
	while (in[spot])
	{
		if (in[spot] == '#' && (connections += inspotcheck(spot, in)))
			spots++;
		spot++;
	}
	if (spots == 4 && connections >= 6)
		return (1);
	else
		return (0);
}

int				inspotcheck(int spot, char *piece)
{
	int	x;

	x = 0;
	x += piece[(spot - 5)] == '#' ? 1 : 0;
	x += piece[(spot - 1)] == '#' ? 1 : 0;
	x += piece[(spot + 1)] == '#' ? 1 : 0;
	x += piece[(spot + 5)] == '#' ? 1 : 0;
	return (x);
}

char			*alphabetize(char *mino)
{
	int			i;
	static int	minocount;

	if (!minocount)
		minocount = 0;
	i = 0;
	while (mino[i])
	{
		if (mino[i] == '#')
			mino[i] = 'A' + minocount;
		else
			mino[i] = '.';
		i++;
	}
	minocount++;
	return (mino);
}
