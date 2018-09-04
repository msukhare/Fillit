/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:48:06 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:11:58 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup != NULL)
	{
		while (s1[i])
		{
			dup[i] = s1[i];
			++i;
		}
		dup[i] = '\0';
	}
	return (dup);
}
