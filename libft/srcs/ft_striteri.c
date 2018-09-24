/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:23:00 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:17 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	count;

	if (!s || !f)
		return ;
	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
		{
			(*f)(count, &s[count]);
			count++;
		}
	}
}
