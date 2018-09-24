/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:28:00 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:51:10 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	if (s[count] != c)
		return (NULL);
	return ((char *)&(s[count]));
}
