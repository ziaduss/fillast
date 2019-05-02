/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 11:23:40 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 08:15:53 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solve(t_all *al, int pos, int a)
{
	int		x;
	int		y;

	if (a == al->nbr_bloc)
		return (1);
	while (pos < al->tm * al->tm)
	{
		x = pos / al->tm;
		y = pos % al->tm;
		if (check_place(al, x, y, a))
		{
			ft_putsol(al, x, y, a);
			if (ft_solve(al, 0, a + 1))
				return (1);
			del_tet(al, a);
		}
		pos++;
	}
	return (0);
}

int			error_fillit(char *str, t_all *t)
{
	int		x;

	x = 0;
	if (!(ft_check_error(str)))
	{
		free(str);
		return (0);
	}
	else
	{
		stock_tet(t, str);
		while (x < t->nbr_bloc)
		{
			if (!(checkblock(t, x, 0)) && !(square(t, x, 0)))
				return (0);
			x++;
		}
		x = 0;
		while (x < t->nbr_bloc)
		{
			fill_xy(t, x);
			x++;
		}
	}
	return (1);
}

void		free_map(t_all t)
{
	int		i;

	i = 0;
	while (i < t.tm)
	{
		free(t.map[i]);
		i++;
	}
	free(t.map);
}

char		*start(int fd, char **argv)
{
	char	*str;

	str = ft_strnew(1);
	fd = open(argv[1], O_RDONLY);
	str = read_file(fd, str, argv);
	close(fd);
	return (str);
}

int			main(int argc, char **argv)
{
	char	*str;
	int		si;
	t_all	t;

	si = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		exit(0);
	}
	str = start(0, argv);
	if (!(error_fillit(str, &t)))
	{
		ft_putstr("error\n");
		exit(0);
	}
	else
	{
		ft_malloc_map(&t, si);
		while (!(ft_solve(&t, 0, 0)))
			ft_malloc_map(&t, si++);
		print_map(&t);
	}
	free_map(t);
	return (0);
}
