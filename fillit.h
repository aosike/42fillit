/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:21:37 by tbisi             #+#    #+#             */
/*   Updated: 2017/02/02 15:18:13 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"

char	**opensesame(char *file, int fd);
char	*store(char *piece);
int		validate(char *piece);
int		incheck(char *in);
int		inspotcheck(int spot, char *piece);
char	*solve(char **minos, size_t *w);
int		fillit(char **minos, size_t w, size_t spot, char *result);
int		placemino(char *mino, char *result, size_t spot, int w);
void	deletemino(char *mino, char *result);
int		uniquemino(char *mino, char *result);
int		smallsq(char **pcs);
char	*alphabetize(char *mino);
char	*periods(char *str, size_t w);
size_t	countminos(char **minos);
void	printsolution(char *result, size_t *w);
size_t	findnextspot(char *result);
#endif
