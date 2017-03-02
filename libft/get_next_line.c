/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 20:46:28 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/13 18:51:21 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void		freetmp(int fd, char **line, char **box, char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	tmp = ft_strndup(buf, i);
	*line = ft_strjoin(box[fd], tmp);
	if (box[fd])
		free(box[fd]);
	free(tmp);
	box[fd] = ft_strdup(buf + i + 1);
}

static int		gnl2(int const fd, int *rd, char **line, char **box)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((*rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*rd] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			freetmp(fd, line, box, buf);
			return (1);
		}
		else
		{
			tmp = ft_strjoin(box[fd], buf);
			free(box[fd]);
			box[fd] = tmp;
		}
	}
	return (0);
}

static int		get_norm(const int fd, char **line, char **box)
{
	if (box[fd] && ft_strcmp(box[fd], "") != 0)
	{
		*line = box[fd];
		box[fd] = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			rd;
	char		buf[BUFF_SIZE + 1];
	static char	*box[255] = {NULL};
	int			i;
	char		*tmp;

	i = 0;
	if (fd <= -1 || !(line) || read(fd, buf, 0) == -1)
		return (-1);
	if ((ft_strchr(box[fd], '\n')))
	{
		while (box[fd][i] != '\n')
			i++;
		*line = ft_strndup(box[fd], i);
		tmp = ft_strdup(box[fd] + i + 1);
		free(box[fd]);
		box[fd] = tmp;
		return (1);
	}
	if (gnl2(fd, &rd, line, box) == 1)
		return (1);
	if (get_norm(fd, line, box) == 1)
		return (1);
	return (0);
}
