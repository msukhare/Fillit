/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upround_sqrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:47:42 by jhache            #+#    #+#             */
/*   Updated: 2017/11/20 18:43:42 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sqrt(unsigned int nb, int flag)
{
	unsigned int	i;

	i = 1;
	while (i < (nb / i))
		++i;
	if (i * i == nb || flag == UPROUNDED)
		return (i);
	return (1);
}
