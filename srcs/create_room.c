/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:10:03 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/05 16:30:45 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char			*take_name(char *line, t_room *room)
{
	int		count;
	char	*name;

	count = 0;
	while (line[count] && line[count] != ' ')
		count++;
	name = (char *)malloc(sizeof(char) * (count + 1));
	if (!name || !(name = ft_strncpy(name, line, count)))
		return (NULL);
	name[count] = '\0';
	count = 0;
	while (count < room->nb_links)
		if (!(ft_strcmp(room->links[count++]->name, name)))
			return (NULL);
	return (name);
}

static t_vector2	take_pos(char *line, t_room *room)
{
	int			count;
	t_vector2	pos;

	pos.x = -1;
	pos.y = -1;
	count = 0;
	while (line[count] && line[count] != ' ')
		count++;
	if (!line[count])
		return (pos);
	pos.x = ft_atoi(&(line[++count]));
	while (line[count] && line[count] != ' ')
		count++;
	if (!line[count])
		return (pos);
	pos.y = ft_atoi(&(line[++count]));
	count = 0;
	while (count < room->nb_links)
	{
		if (room->links[count]->pos.x == pos.x &&
			room->links[count]->pos.y == pos.y && (pos.x = -1))
			return (pos);
		count++;
	}
	return (pos);
}

int					create_room(t_room *rooms, char *line)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (MEMORY_ERROR);
	room->ant = 0;
	room->end = 0;
	if (!(room->name = take_name(line, rooms)))
		return (0);
	room->links = NULL;
	room->nb_links = 0;
	room->pos = take_pos(line, rooms);
	if (room->pos.x == -1 || room->pos.y == -1)
		return (0);
	rooms->links = add_link(rooms, room);
	if (!room->name || !rooms->links)
		return (MEMORY_ERROR);
	else
		return (1);
}

int					create_command_room(t_room *rooms, char *line)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (MEMORY_ERROR);
	room->ant = 0;
	room->end = 0;
	if (!(ft_strcmp(line, "##end")))
		room->end = 1;
	if (!(ft_strcmp(line, "##start")))
		room->end = -1;
	get_next_line(0, &line);
	ft_putendl(line);
	if (!line || !is_room(line) || !(room->name = take_name(line, rooms)))
		return (0);
	room->links = NULL;
	room->nb_links = 0;
	room->pos = take_pos(line, rooms);
	if (room->pos.x == -1 || room->pos.y == -1)
		return (0);
	rooms->links = add_link(rooms, room);
	free(line);
	if (!room->name || !rooms->links)
		return (MEMORY_ERROR);
	return (1);
}
