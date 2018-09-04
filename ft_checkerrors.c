/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerrors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:35:27 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/22 15:53:57 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(-1);
}

void	ft_checkerror1(char *str)
{
	int	i;
	int	nb_lines;

	nb_lines = 0;
	i = 0;
	(str[0] == '#' || str[0] == '.') ? i++ : ft_error();
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '#' && str[i] != '.')
			ft_error();
		if (str[i] == '\n')
		{
			++nb_lines;
			if (str[i + 1] == '\n')
			{
				(nb_lines == 4) ? nb_lines = 0 : ft_error();
				++i;
			}
		}
		++i;
	}
	if ((str[i - 1] == '\n' && str[i - 2] == '\n') || nb_lines == 1)
		ft_error();
}

void	ft_checkerror2(char *str)
{
	int	i;
	int	nb_chara;
	int	diez;

	nb_chara = 0;
	diez = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			++diez;
		if (str[i] == '#' || str[i] == '.')
			++nb_chara;
		if (str[i] == '\n' && nb_chara % 4 != 0)
			ft_error();
		else if (str[i] == '\n' && str[i + 1] == '\n')
		{
			(diez != 4 || nb_chara != 16) ? ft_error() : 0;
			nb_chara = 0;
			diez = 0;
		}
		++i;
	}
	(nb_chara != 16 || diez != 4) ? ft_error() : 0;
}

int		ft_count_links(char **s, int i, int j)
{
	int	k;
	int	nb_links;

	nb_links = 0;
	k = j;
	(j - 1) < 0 ? k = j : --k;
	if (s[i][j] == s[i][k] && k != j)
		++nb_links;
	k = j;
	(j + 1) > 3 ? k = j : ++k;
	if (s[i][j] == s[i][k] && k != j)
		++nb_links;
	k = i;
	(i - 1) < 0 ? k = i : --k;
	if (s[i][j] == s[k][j] && k != i)
		++nb_links;
	k = i;
	(i + 1) > 3 ? k = i : ++k;
	if (s[i][j] == s[k][j] && k != i)
		++nb_links;
	return (nb_links);
}

void	ft_checkerror3(t_tetris *begin_list)
{
	int		i;
	int		j;
	int		nb_links;

	while (begin_list)
	{
		i = 0;
		nb_links = 0;
		while (begin_list->piece[i])
		{
			j = 0;
			while (begin_list->piece[i][j])
			{
				if (begin_list->piece[i][j] == '#')
					nb_links += ft_count_links(begin_list->piece, i, j);
				++j;
			}
			++i;
		}
		if (nb_links != 6 && nb_links != 8)
			ft_error();
		nb_links == 8 ? begin_list->extrem[1] = 2 : 0;
		ft_posrela(begin_list);
		begin_list = begin_list->next;
	}
}
