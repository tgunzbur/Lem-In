/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:25:27 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:46:48 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !del)
		return ;
	while (*alst != NULL)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, (*del));
		*alst = temp;
	}
	alst = NULL;
	temp = NULL;
}
