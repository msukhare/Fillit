/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:13:51 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:02:20 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*var_compute(unsigned int *result, int n, int *len, char **str)
{
	*len = 1;
	if (n < 0)
	{
		*result = (unsigned int)(n * -1);
		++(*len);
	}
	else
		*result = (unsigned int)n;
	while (n > 9 || n < -9)
	{
		++(*len);
		n /= 10;
	}
	*str = ft_strnew(*len);
	return (*str);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	result;
	int				len;
	char			*str;
	int				j;

	j = 0;
	i = 1;
	if (!(str = var_compute(&result, n, &len, &str)))
		return (str);
	if (n < 0)
	{
		str[j++] = '-';
		--len;
	}
	while (--len > 0)
		i *= 10;
	while (i > 0)
	{
		str[j] = result / i + 48;
		result %= i;
		i /= 10;
		++j;
	}
	return (str);
}
