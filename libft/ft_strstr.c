/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:06:03 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:23:28 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		if (needle[j] == haystack[i])
			++j;
		else
		{
			i = i - j;
			j = 0;
		}
		++i;
	}
	if (j == 0)
		return (NULL);
	return ((char *)&haystack[i - (int)ft_strlen(needle)]);
}
