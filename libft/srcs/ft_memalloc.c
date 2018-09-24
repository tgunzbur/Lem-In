/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:08:49 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:30:50 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	count;
	void	*pointer;
	char	*temp_pointer;

	if ((pointer = (void*)malloc(size)) != NULL)
	{
		temp_pointer = (char *)pointer;
		count = 0;
		while (count < size)
		{
			temp_pointer[count] = '\0';
			count++;
		}
		return (pointer);
	}
	else
		return (NULL);
}
