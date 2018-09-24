/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:37:39 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:50:39 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr(char const *s)
{
	int	count;

	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
		{
			ft_putchar(s[count]);
			count++;
		}
	}
}
