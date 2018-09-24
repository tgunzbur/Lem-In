/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tunnels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:30:45 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/29 14:27:48 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_tunnel(char *line, t_room *start)
{
	int		c;
	int		i;

	c = 0;
	while (line[c] && line[c] != '-')
		c++;
	if (!line[c])
		return (0);
	i = 0;
	line[c++] = '\0';
	start->name = NULL;
	while (i < start->nb_links && ft_strcmp(start->links[i]->name, line))
		i++;
	line[c - 1] = '-';
	if (i >= start->nb_links)
		return (0);
	i = 0;
	while (i < start->nb_links && ft_strcmp(start->links[i]->name, &(line[c])))
		i++;
	if (i >= start->nb_links)
		return (0);
	return (1);
}

int	create_tunnels(t_room *start, char *line, int *error)
{
	create_tunnel(start, line);
	free(line);
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (is_tunnel(line, start))
		{
			if ((*error = create_tunnel(start, line)) < 0)
			{
				free(line);
				return (*error);
			}
		}
		else if (!is_commentary(line))
		{
			free(line);
			return (LINE_ERROR);
		}
		free(line);
	}
	if (line)
		free(line);
	return (1);
}
