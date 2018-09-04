/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:44:40 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:19:35 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	i = ft_strlen(s1);
	while (s2[j] != '\0' && k < n)
	{
		s1[i] = s2[j];
		++i;
		++j;
		++k;
	}
	s1[i] = '\0';
	return (s1);
}
