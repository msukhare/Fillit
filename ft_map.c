/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:26:24 by jhache            #+#    #+#             */
/*   Updated: 2017/11/22 12:57:34 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map(int sidelen)
{
	char	**map;
	int		j;
	int		i;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char*) * sidelen)))
		return (NULL);
	while (j < sidelen)
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * (sidelen + 1))))
			return (NULL);
		i = 0;
		while (i < sidelen)
		{
			map[j][i] = '.';
			++i;
		}
		map[j][i] = '\0';
		++j;
	}
	return (map);
}
