/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:41:05 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:47:13 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;
	t_list *prev;

	if (!lst || !f)
		return (NULL);
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = (*f)(lst);
	prev = new;
	first = new;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new = (*f)(lst);
		lst = lst->next;
		prev->next = new;
		prev = new;
	}
	return (first);
}
