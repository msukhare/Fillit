/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:31:48 by jhache            #+#    #+#             */
/*   Updated: 2017/11/22 15:45:37 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_countsize(char *str)
{
	int		fd;
	int		nb_chara;
	char	c;

	nb_chara = 1;
	if (!(fd = open(str, O_RDONLY)))
		return (-1);
	while (read(fd, &c, 1) > 0)
		++nb_chara;
	close(fd);
	return (nb_chara);
}

t_tetris		*ft_readfile(char *str)
{
	char		*pieces;
	int			file;
	int			i;
	t_tetris	*begin_list;

	i = 0;
	if (!(pieces = (char *)malloc(sizeof(char) * (ft_countsize(str) + 1))))
		return (NULL);
	if (!(file = open(str, O_RDONLY)))
		return (NULL);
	while ((read(file, (pieces + i), 1)) > 0)
		i++;
	pieces[i] = '\0';
	close(file);
	ft_checkerror1(pieces);
	ft_checkerror2(pieces);
	if (!(begin_list = ft_lstsplit(pieces, i)))
		return (NULL);
	free(pieces);
	ft_checkerror3(begin_list);
	return (begin_list);
}
