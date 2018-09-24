/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:58:57 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:25 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	count;

	if (s == NULL)
		return (NULL);
	if ((cpy = (char*)malloc(sizeof(char) * (len + 1))))
	{
		count = start;
		while ((count - start) < len)
		{
			cpy[count - start] = s[count];
			count++;
		}
		cpy[count - start] = '\0';
		return (cpy);
	}
	return (NULL);
}
