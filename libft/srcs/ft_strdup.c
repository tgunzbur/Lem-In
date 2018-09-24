/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:11:16 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:25:49 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		count;
	char	*cpy;

	count = 0;
	while (s[count] != '\0')
		count++;
	cpy = (char*)malloc(sizeof(char) * (count + 1));
	if (cpy == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		cpy[count] = s[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}
