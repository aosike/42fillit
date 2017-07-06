/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:07:58 by tbisi             #+#    #+#             */
/*   Updated: 2017/02/07 14:16:33 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**minos;
	char	*result;
	size_t	w;
	size_t	*wptr;
	int		fd;

	w = 0;
	fd = 0;
	wptr = &w;
	if (ac != 2)
	{
		write(1, "usage: ./fillit target_file\n", 27);
		exit(0);
	}
	if ((minos = opensesame(av[1], fd)) == NULL)
		write(1, "error\n", 6);
	else
	{
		result = solve(minos, wptr);
		printsolution(result, wptr);
	}
	return (0);
}

char	**opensesame(char *file, int fd)
{
	char	*str;
	char	**inputs;
	size_t	i;

	if (!(fd = open(file, O_RDONLY))
			|| !(inputs = (char **)malloc(sizeof(char *) * 26)))
		return (NULL);
	i = 0;
	while (read(fd, (str = ft_strnew(21)), 20))
	{
		if (validate(str) && incheck(str))
			alphabetize(inputs[i++] = store(str));
		else
			return (NULL);
		if (!(read(fd, str, 1)))
		{
			while (inputs[i])
				inputs[i++] = NULL;
			return ((*inputs) ? inputs : NULL);
		}
		else if (*str != '\n')
			return (NULL);
	}
	return (NULL);
}

void	printsolution(char *result, size_t *w)
{
	int	spot;
	int	wi;

	wi = *w;
	spot = 0;
	while (result[spot])
	{
		write(1, &result[spot], 1);
		if (spot != 0 && ((spot + 1) % wi) == 0)
			write(1, "\n", 1);
		spot++;
	}
}

char	*store(char *piece)
{
	char	*result;
	size_t	front;
	size_t	mid;
	size_t	back;

	front = 0;
	back = 19;
	while (piece[front] != '#')
		front++;
	mid = front + 2;
	while (piece[mid] != '#')
		mid++;
	front -= (mid % 5) < (front % 5) ? ((front % 5) - (mid % 5)) : 0;
	while (piece[back] != '#')
		back--;
	back++;
	result = ft_strndup(&piece[front], (back - front));
	return (result);
}
