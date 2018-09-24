/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:25:03 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:46 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				new[count] = (*f)(s[count]);
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
