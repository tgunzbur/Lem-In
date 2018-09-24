/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:09:59 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:29:09 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_cpyline(char *line, char *buffer)
{
	unsigned int	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (ft_strlen(line) > count + 1)
		buffer = ft_strcpy(buffer, &(line[count + 1]));
	line[count] = '\0';
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	buffer[FD_MAX + 1][BUFF_SIZE + 1] = {"\0"};
	char		*temp;
	int			error;

	error = 1;
	if (fd < 0 || fd > FD_MAX || !line || !(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (buffer[fd][0] != '\0')
		*line = ft_strcpy(*line, buffer[fd]);
	ft_bzero(buffer[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && error > 0)
	{
		error = read(fd, buffer[fd], BUFF_SIZE);
		if (error > 0)
		{
			temp = *line;
			if ((*line = ft_strjoin(*line, buffer[fd])) == NULL)
				return (-1);
			ft_bzero(buffer[fd], BUFF_SIZE);
			free(temp);
		}
	}
	if (*line[0] != '\0' && error >= 0)
		return (ft_cpyline(*line, buffer[fd]));
	return (error);
}
