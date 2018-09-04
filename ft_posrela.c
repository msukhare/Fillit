/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posrela.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:16:20 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/21 13:30:25 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_extrem(t_tetris *lst)
{
	int		lsti;

	lsti = 0;
	while (lsti < 4)
		lst->extrem[0] += lst->pos[lsti++][0];
	if (lst->extrem[1] == 2)
		return ;
	if (lst->extrem[0] == 1)
		lst->extrem[1] = 4;
	else if (lst->extrem[0] == 4)
		lst->extrem[1] = 1;
	else if (lst->extrem[0] == 3)
		lst->extrem[1] = 2;
	else if (lst->extrem[0] == 2)
		lst->extrem[1] = 3;
}

void		ft_posrela(t_tetris *lst)
{
	int		i;
	int		j;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	while (i < 3 || j < 4)
	{
		if (lst->piece[i][j] == '#')
		{
			lst->pos[p][0] = i - lst->pos[0][0];
			lst->pos[p++][1] = j - lst->pos[0][1];
			lst->pos[0][0] = i;
			lst->pos[0][1] = j;
		}
		(j == 4) ? j = 0 : ++j;
		if (j == 0)
			++i;
	}
	lst->pos[0][0] = 0;
	lst->pos[0][1] = 0;
	ft_extrem(lst);
	free(lst->piece);
}
