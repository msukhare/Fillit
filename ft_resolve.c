/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:01:56 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/22 15:05:34 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_maplen(t_tetris *lst)
{
	int		nb;

	nb = 0;
	while (lst)
	{
		++nb;
		lst = lst->next;
	}
	return (ft_sqrt(nb * 4, UPROUNDED));
}

int			ft_check(char **map, t_tetris *list, int i, int j)
{
	int		posi;
	int		len;

	len = ft_strlen(map[0]);
	posi = 0;
	while (posi < 4)
	{
		i += list->pos[posi][0];
		j += list->pos[posi][1];
		if (i >= len || j >= len || i < 0 || j < 0 || map[i][j] != '.')
			return (0);
		++posi;
	}
	return (1);
}

void		ft_clear(char **map, int i, int j, t_tetris *lst)
{
	int		posi;

	posi = 0;
	while (posi < 4)
	{
		i += lst->pos[posi][0];
		j += lst->pos[posi][1];
		map[i][j] = '.';
		++posi;
	}
}

void		ft_putpiece(char **map, t_tetris *lst, int i, int j)
{
	int		posi;

	posi = 0;
	while (posi < 4)
	{
		i += lst->pos[posi][0];
		j += lst->pos[posi][1];
		map[i][j] = lst->letter;
		++posi;
	}
}

int			ft_resolve(char **map, t_tetris *lst, int size)
{
	int		i;
	int		j;

	i = 0;
	if (lst == NULL)
		return (1);
	while (i <= ((size - lst->extrem[0]) + 1))
	{
		j = 0;
		while (j <= ((size - lst->extrem[1]) + 1))
		{
			if (ft_check(map, lst, i, j))
			{
				ft_putpiece(map, lst, i, j);
				if (ft_resolve(map, lst->next, size))
					return (1);
				ft_clear(map, i, j, lst);
			}
			++j;
		}
		++i;
	}
	return (0);
}
