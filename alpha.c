/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:13:04 by tbisi             #+#    #+#             */
/*   Updated: 2017/01/09 15:32:27 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char 	alphabetize(char **minos)
{
	int i;
	size_t	spot;

	i = 0;
	spot = 0;
	while (*minos)
	{
		while (*minos[spot])
		{
			if (spot == '#')
				spot = 'A' + i;
			else
				spot = '.';
			spot++;
		}
		minos++;
		i++;
	}
	return (minos);
}
