/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:28:52 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:53 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*new;

	if (s != NULL)
	{
		count = 0;
		while (s[count] != '\0')
			count++;
		if ((new = (char*)malloc(sizeof(char) * (count + 1))))
		{
			count = 0;
			while (s[count] != '\0')
			{
				new[count] = (*f)(count, s[count]);
				count++;
			}
			new[count] = '\0';
			return (new);
		}
		else
			return (NULL);
	}
	return (NULL);
}
