/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:59:35 by jhache            #+#    #+#             */
/*   Updated: 2017/11/10 18:09:27 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	result;

	i = 1;
	if (n < 0)
	{
		result = (unsigned int)(n * -1);
		ft_putchar_fd('-', fd);
	}
	else
		result = (unsigned int)n;
	while (result / i > 9)
		i *= 10;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		while (i != 0)
		{
			ft_putchar_fd((result / i) + 48, fd);
			result %= i;
			i /= 10;
		}
	}
}
