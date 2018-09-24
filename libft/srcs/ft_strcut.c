/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:14:53 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:25:33 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcut(char *str, int start, int end)
{
	char	*new;
	int		count;

	if (end <= start)
		return (NULL);
	if ((new = (char *)malloc(sizeof(char) * (end - start + 1))) == NULL)
		return (NULL);
	count = start;
	while (count < end)
	{
		new[count - start] = str[count];
		count++;
	}
	new[count - start] = '\0';
	return (new);
}
