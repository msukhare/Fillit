/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhache <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:12 by jhache            #+#    #+#             */
/*   Updated: 2017/11/13 18:13:41 by jhache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*p1;
	t_list	*p2;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	p1 = ft_lstnew(tmp->content, tmp->content_size);
	if (p1 == NULL)
		return (NULL);
	p2 = p1;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		p1->next = ft_lstnew(tmp->content, tmp->content_size);
		if (p1->next == NULL)
			return (NULL);
		p1 = p1->next;
		lst = lst->next;
	}
	return (p2);
}
