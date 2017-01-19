/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbisi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:21:37 by tbisi             #+#    #+#             */
/*   Updated: 2017/01/18 19:38:12 by agundry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	**opensesame(char *file);
void	store(char mino[], char *input);
int		validate(char *piece);
int		incheck(char *in);
int		inspotcheck(int spot, char *piece);
char	*solve(char minos[26][17], size_t mcnt);
int		fillit(char minos[26][17], size_t w, size_t spot, char *result);
int		placemino(char *mino, char *result, size_t spot, int w);
void	deletemino(char *mino, char *result);
int		uniquemino(char *mino, char *result);
size_t	smallsq(size_t mcnt);

int		ft_isalpha(int c);
void	*ft_memalloc(size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
char	*alphabetize(char *input, int wcnt);
void	*ft_memset(void *b, int c, size_t len);
char	*periods(char *str, size_t w);
size_t	countminos(char minos[26][17]);
void	printsolution(char *result, size_t w);
size_t	findnextspot(char *result);
#endif
