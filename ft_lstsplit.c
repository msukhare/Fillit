/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:27:11 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:28:25 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*ft_createlem(char **piece, char letter)
{
	t_tetris	*tmp;
	int			i;

	if (!(tmp = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!piece)
		return (NULL);
	tmp->piece = piece;
	tmp->next = NULL;
	i = 0;
	while (i < 4)
	{
		tmp->pos[i][0] = 0;
		tmp->pos[i][1] = 0;
		++i;
	}
	tmp->extrem[0] = 1;
	tmp->extrem[1] = 0;
	tmp->letter = letter;
	return (tmp);
}

t_tetris		*ft_lstsplit(char *str, int size)
{
	t_tetris	*begin_list;
	t_tetris	*elem;
	t_tetris	*tmp;
	int			i;
	char		letter;

	i = 0;
	letter = 'A';
	if (!(tmp = ft_createlem(ft_strsplit(ft_strsub(str, i, 19), '\n'),
					letter++)))
		return (NULL);
	i += 21;
	begin_list = tmp;
	elem = tmp;
	while (i < size)
	{
		if (!(tmp = ft_createlem(ft_strsplit(ft_strsub(str, i, 19), '\n'),
						letter++)))
			return (NULL);
		elem->next = tmp;
		elem = tmp;
		i += 21;
	}
	return (begin_list);
}
