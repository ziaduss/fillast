/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map_point.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moghomra <moghomra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 10:11:53 by moghomra     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 08:34:13 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		ft_malloc_map(t_all *al, int inc)
{
	int		i;

	i = 0;
	al->tm = ft_sqrt(4 * al->nbr_bloc) + inc;
	if (!(al->map = ft_memalloc(sizeof(char*) * al->tm)))
		return ;
	while (i < al->tm)
	{
		al->map[i] = malloc(sizeof(char) * al->tm);
		i++;
	}
	ft_map_point(al);
}

void		ft_map_point(t_all *al)
{
	int		i;
	int		j;

	i = 0;
	while (i < al->tm)
	{
		j = 0;
		while (j < al->tm)
		{
			al->map[i][j] = '.';
			j++;
		}
		i++;
	}
}
