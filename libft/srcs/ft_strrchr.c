/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:32:10 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:27:49 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		count++;
	while (s[count] != c && count >= 0)
		count--;
	if (s[count] != c)
		return (NULL);
	return ((char *)&(s[count]));
}
