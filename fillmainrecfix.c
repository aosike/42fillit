#include "fillit.h"

int	main(int ac, char **av)
{
	char	**minos;
	char	*result;
	size_t	w;
	size_t	*wptr;

	w = 0;
	wptr = &w;
	if (ac != 2)
		return (0);
	if(!(minos = opensesame(av[1])))
		return (0);
	result = solve(minos, wptr);
	printsolution(result, wptr);

}

char	**opensesame(char *file)
{
	int		fd;
	char	*str;
	char	**inputs;
	char	**input;

	if(!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(inputs = (char **)malloc(sizeof(char *) * 26)))
		return (NULL);
	ft_bzero(inputs, 26);
	input = inputs;
	str = ft_strnew(22);
	while (read(fd, str, 21))
	{
		if(validate(str) && incheck(str))
			*input++ = store(str);
		else
			return (NULL);
	}
	return (alphabetize(inputs));
}

char 	*store(char *piece)
{
	char	*result;
	size_t	front;
	size_t	mid;
	size_t	back;

	front = 0;
	back = 20;
	while (piece[front] != '#')
		front++;
	mid = front + 2;
	while (piece[mid] != '#')
		mid++;
	front -= (mid % 5) < (front % 5) ? ((front % 5) - (mid % 5)) : 0;
	while (piece[back] != '#')
		back--;
	back++;
	result = ft_strnew(back - front);
	result = ft_strncpy(result, &piece[front], (back - front));
	return (result);
}

int	validate(char *piece)
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
	if (*piece == '\n' && j == 4) 
		return (1);
	return (0);
}



int incheck(char *in)
{
	size_t spots = 0;
	size_t spot = 0;
	size_t	connections;
	while (in[spot])
	{
		if (in[spot] == '#' && (connections = inspotcheck(spot, in)) > 0)
			spots++;
		spot++;
	}
	if (spots == 4 && connections >= 6)
		return (1);
	else
		return (0);
}

int inspotcheck(int spot, char *piece)
{
	static int	x;

	if (!x)
		x = 0;
	x += piece[(spot - 5)] == '#' ? 1 : 0;
	x += piece[(spot - 1)] == '#' ? 1 : 0;
	x += piece[(spot + 1)] == '#' ? 1 : 0;
	x += piece[(spot + 5)] == '#' ? 1 : 0;
	return (x);
}

char	**alphabetize(char **minos)
{
	int 	i;
	char	**things;
	char	*thing;

	things = minos;
	i = 0;
	while (things[i])
	{
		thing = things[i];
		while (*thing || *thing == '\n')
		{
			if (*thing == '#')
				*thing = 'A' + i;
			else
				*thing = '.';
			thing++;
		}
		i++;
	}
	return (minos);
}
