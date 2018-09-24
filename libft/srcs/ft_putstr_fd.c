/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:38:42 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:50:46 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	count;

	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
}
