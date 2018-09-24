/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:55:19 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:09 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		count;

	if (!s || !f)
		return ;
	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
		{
			(*f)(&(s[count]));
			count++;
		}
	}
}
