#include "fillit.h"

int	main(int ac, char **av)
{
	size_t	mcnt;
	char	minos[26][17];
	char	*tmp;
	int		fd;

	if (ac != 2)
		return (0);
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	tmp = ft_strnew(22);
	mcnt = 0;
	while (read(fd, tmp, 21))
	{
		if (validate(tmp) && incheck(tmp))
		{
			tmp = alphabetize(tmp, mcnt);
			store(minos[mcnt], tmp);
			mcnt++;
		}
	}
	solve(minos, (mcnt + 1));
}

/*char	**opensesame(char *file)
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
	}
	return (alphabetize(inputs));
}*/

void	store(char mino[], char *input)
{
	size_t	front;
	size_t	mid;
	size_t	back;

	front = 0;
	back = 20;
	while (ft_isalpha(*(input + front)))
		front++;
	mid = front + 2;
	while (!(ft_isalpha(*(input + mid))))
		mid++;
	front -= (mid % 5) < (front % 5) ? ((front % 5) - (mid % 5)) : 0;
	while (!(ft_isalpha(*(input + back))))
		back--;
	back++;
	mino = ft_strncpy(mino, (input + front), (back - front));
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
	while (in[spot])
	{
		if (in[spot] == '#' && inspotcheck(spot, in))
			spots++;
		spot++;
	}
	if (spots == 4)
		return (1);
	else
		return (0);
}

int inspotcheck(int spot, char *piece)
{
	int	x = 0;

	x += piece[(spot - 5)] == '#' ? 1 : 0;
	x += piece[(spot - 1)] == '#' ? 1 : 0;
	x += piece[(spot + 1)] == '#' ? 1 : 0;
	x += piece[(spot + 5)] == '#' ? 1 : 0;
	return (x);
}

char	*alphabetize(char *input, int wcnt)
{
	char	*i;

	i = input;
	while (*input)
	{
		*input = *input == '#' ? ('A' + wcnt) : '.';
		input++;
	}
	return (i);
}
