#include "fillit.h"

void	printsolution(char *result, size_t w)
{
	int	spot;

	spot = 0;
	while (result[spot])
	{
		write (1, &result[spot], 1);
		if (spot != 0 && ((spot + 1) % w) == 0)
			write (1, "\n", 1);
		spot++;
	}
}
