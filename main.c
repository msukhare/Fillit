/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:00:00 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/22 16:10:07 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(-1);
}

void	ft_freeall(t_tetris *begin_list, char **map, int size)
{
	t_tetris	*tmp;
	int			i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
}

void	ft_printmap(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
}

int		main(int argc, char **argv)
{
	t_tetris	*begin_list;
	int			size;
	int			i;
	char		**map;

	if (argc != 2)
		ft_error_usage();
	if (!(begin_list = ft_readfile(argv[1])))
		ft_error();
	size = ft_maplen(begin_list);
	if (!(map = ft_map(size)))
		ft_error();
	while (!(ft_resolve(map, begin_list, (size + 1))))
	{
		i = 0;
		while (i < size)
			free(map[i++]);
		free(map);
		if (!(map = ft_map(++size)))
			ft_error();
	}
	ft_printmap(map, size);
	ft_freeall(begin_list, map, size);
	return (0);
}
