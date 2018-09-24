/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:03:42 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:24 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_joinstring(char *join,
		char const *s1, char const *s2, int count2)
{
	int count;

	count = 0;
	while (s1[count] != '\0')
	{
		join[count] = s1[count];
		count++;
	}
	while (s2[count - count2] != '\0')
	{
		join[count] = s2[count - count2];
		count++;
	}
	join[count] = '\0';
	return (join);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		count;
	int		count2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
		count++;
	count2 = count;
	while (s2[count - count2] != '\0')
		count++;
	if ((join = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	return (ft_joinstring(join, s1, s2, count2));
}
