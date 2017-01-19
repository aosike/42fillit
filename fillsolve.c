#include "fillit.h"

char	*solve(char minos[26][17], size_t mcnt)
{
	char	*result;
	size_t	w;
	int		swich;

	swich = 0;
	w = smallsq(mcnt);
	while (!(fillit(minos, w, 0, (result = periods(ft_strnew(w * w), w)))))
	{
		w++;
		swich++;
		free(result);
	}
	if (swich)
		 printsolution(result, w);
	return (NULL);
}

char	*periods(char *str, size_t w)
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i++ < (w * w))
		*s++ = '.';
	return (str);
}

int	fillit(char minos[26][17], size_t w, size_t spot, char *result)
{
	static size_t	placecount;
	size_t	num;
	static size_t	minocount;
	
	if (!minocount)
		minocount = countminos(minos);
	if (!placecount || spot == 0)
		placecount = 0;
	if (placecount == minocount)
		return (1);
	if (!result[spot])
		return (0);
	num = 0;
	while (num < minocount)
	{
		if (uniquemino(minos[num], result))
		{
			if (placemino(minos[num], result, spot, w))
			{
				placecount++;
				if (fillit(minos, w, (spot + 1), result))
					return (1);
			}
			else
				deletemino(minos[num], result);
		}
		num++;
	}
	if (fillit(minos, w, (spot + 1), result))
		return (1);
	return (0);
}

size_t	findnextspot(char *result)
{
	size_t	siz;

	siz = 0;
	while (result[siz] && result[siz] != '.')
		siz++;
	return (siz);
}

size_t	countminos(char minos[26][17])
{
	size_t	i;

	i = 0;
	while(minos[i][0] != '\0')
		i++;
	return (i);
}

int	placemino(char *mino, char *result, size_t spot, int w)
{
	char *res;
	char *min;
	int	i;

	res = result;
	min = mino;
	while (*min == '.')
	{
		spot++;
		min++;
	}
	while (*min)
	{
		while (*min != '.' && *min)
		{
			if (*(min + 1) && (*(min + 1) != '.') && ((spot + 1) % w) == 0)
				return (0);
			if (res[spot] == '.')
				res[spot++] = *min++;
			else
				return (0);
		}
		i = 0;
		while (*min == '.')
		{
			i++;
			min++;
		}
		spot += w - (5 - i);
	}
	return (1);
}

void	deletemino(char *mino, char *result)
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

int uniquemino(char *mino, char *result)
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
size_t	smallsq(size_t mcnt)
{
	size_t	size;
	size_t	sq;

	sq = 2;
	size = (mcnt * 4);
	while((sq * sq) < size)
		sq++;
	return (sq);
}
