/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:36:07 by lnagy             #+#    #+#             */
/*   Updated: 2016/11/24 05:47:09 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_info(t_env *e, char *line, int y)
{
	if ((y = get_next_line(0, &line)) <= 0)
		return (y);
	if (!e->board)
		if (set_board(e, line) == -1)
			return (-1);
	free(line);
	if ((y = get_next_line(0, &line)) <= 0)
		return (y);
	return (0);
}

int		parse(t_env *e)
{
	char	*line;
	char	**board;
	int		y;

	y = 0;
	line = NULL;
	get_info(e, line, y);
	free(line);
	e->size_x = -1;
	e->size_y = -1;
	e->y = -1;
	e->x = e->width;
	board = e->board;
	while (get_next_line(0, &line) > 0 && ft_isdigit(line[0]))
	{
		parse_line(e, line, y, board);
		board++;
		y++;
	}
	if (e->size_x == -1 && e->size_y == -1)
		get_enpos(e);
	get_piece(e, line);
	y = play(e, (t_coord){-1, -1}, 0, 0);
	free_piece(e->piece, e->p_height);
	return (y);
}

int		main(void)
{
	char	*line;
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.last[0] = 'o';
	e.last[1] = 'x';
	e.maj_p[0] = 'O';
	e.maj_p[1] = 'X';
	get_next_line(0, &line);
	e.player = *(ft_strchr(line, 'p') + 1) - '1';
	free(line);
	while (1 && parse(&e) != -1)
		;
	return (0);
}
