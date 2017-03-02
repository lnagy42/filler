/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:36:07 by lnagy             #+#    #+#             */
/*   Updated: 2016/11/10 18:05:32 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(char **piece, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(piece[i]);
		i++;
	}
	free(piece);
}

int		get_piece(t_env *e, char *line)
{
	int		i;
	char	**t;

	i = 0;
	t = ft_strsplit(line, ' ');
	e->p_height = ft_atoi(t[1]);
	e->p_width = ft_atoi(t[2]);
	e->piece = ft_memalloc(sizeof(char *) * e->p_height);
	free(line);
	while (i < e->p_height)
	{
		get_next_line(0, &line);
		e->piece[i] = line;
		i++;
	}
	ft_deltab(t);
	return (0);
}

int		set_board(t_env *e, char *line)
{
	char	**t;
	int		height;
	int		i;

	t = ft_strsplit(line, ' ');
	e->height = ft_atoi(t[1]);
	e->width = ft_atoi(t[2]);
	height = e->height + 1;
	if ((e->board = ft_memalloc(sizeof(char *) * height)) == NULL)
		return (-1);
	i = 0;
	while (i < height - 1)
	{
		if ((e->board[i] = ft_memalloc(e->width + 1)) == NULL)
			return (-1);
		i++;
	}
	ft_deltab(t);
	return (0);
}

void	parse_line(t_env *e, char *line, int y, char **board)
{
	char	*p;
	char	*en_pos;
	char	*line_map;

	line_map = ft_strchr(line, ' ') + 1;
	en_pos = ft_strchr(line_map, e->last[!e->player]);
	ft_strcpy(*board, line_map);
	if (en_pos != NULL)
	{
		e->y = e->y == -1 ? y : e->y;
		e->x = e->x < en_pos - line_map ? e->x : en_pos - line_map;
		e->size_y = y;
		p = en_pos;
		while ((en_pos = ft_strchr(p + 1, e->last[!e->player])))
			p = en_pos;
		e->size_x = e->size_x > p - line_map ? e->size_x : p - line_map;
	}
	free(line);
}
