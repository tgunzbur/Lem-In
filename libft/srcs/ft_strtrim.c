/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:10:55 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:47 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		c;
	int		start;
	int		end;
	char	*trim;

	if (s == NULL)
		return (NULL);
	c = 0;
	while ((s[c] == '\n' || s[c] == '\t' || s[c] == ' ') && s[c] != '\0')
		c++;
	start = c;
	while (s[c] != '\0')
		c++;
	c--;
	while ((s[c] == '\n' || s[c] == '\t' || s[c] == ' ') && c > start)
		c--;
	end = c;
	if ((trim = (char*)malloc(sizeof(char) * (end - start + 2))) == NULL)
		return (NULL);
	c = start - 1;
	while (++c <= end)
		trim[c - start] = s[c];
	trim[c - start] = '\0';
	return (trim);
}
