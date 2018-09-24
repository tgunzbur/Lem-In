/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tunnel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:48:36 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/29 16:22:19 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	take_names(char *line, char **start, char **end)
{
	int		s_c;
	int		e_c;

	s_c = 0;
	while (line[s_c] && line[s_c] != '-')
		s_c++;
	*start = (char *)malloc(sizeof(char) * (s_c + 1));
	if (!(*start = ft_strncpy(*start, line, s_c)))
	{
		free(*start);
		return (MEMORY_ERROR);
	}
	(*start)[s_c] = '\0';
	e_c = ++s_c;
	while (line[e_c])
		e_c++;
	*end = (char *)malloc(sizeof(char) * (e_c - s_c + 2));
	if (!(*end = ft_strncpy(*end, &(line[s_c]), e_c - s_c + 1)))
	{
		free(*end);
		return (MEMORY_ERROR);
	}
	(*end)[e_c - s_c + 1] = '\0';
	return (1);
}

t_room		**add_link(t_room *room, t_room *ptr)
{
	t_room	**links;
	int		count;
	int		error;

	if (!(links = (t_room **)malloc(sizeof(t_room *) * (room->nb_links + 1))))
		return (NULL);
	count = -1;
	error = 0;
	while (++count < room->nb_links)
	{
		links[count] = room->links[count];
		if (!(ft_strcmp(links[count]->name, ptr->name)))
			error = 1;
	}
	if (error == 0)
	{
		links[count] = ptr;
		room->nb_links++;
	}
	if (room->nb_links - 1 > 0)
		free(room->links);
	return (links);
}

int			create_tunnel(t_room *room, char *line)
{
	int		s_c;
	int		e_c;
	char	*start;
	char	*end;

	start = NULL;
	end = NULL;
	if (!(take_names(line, &start, &end)))
		return (MEMORY_ERROR);
	s_c = 0;
	while (s_c < room->nb_links && ft_strcmp(room->links[s_c]->name, start))
		s_c++;
	e_c = 0;
	while (e_c < room->nb_links && ft_strcmp(room->links[e_c]->name, end))
		e_c++;
	if (s_c == room->nb_links || e_c == room->nb_links)
		return (LINE_ERROR);
	room->links[s_c]->links = add_link(room->links[s_c], room->links[e_c]);
	room->links[e_c]->links = add_link(room->links[e_c], room->links[s_c]);
	free(start);
	free(end);
	if (!room->links[s_c]->links || !room->links[e_c]->links)
		return (MEMORY_ERROR);
	return (1);
}
