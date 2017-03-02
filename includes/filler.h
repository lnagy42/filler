/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:36:07 by lnagy             #+#    #+#             */
/*   Updated: 2016/11/10 18:05:32 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# define MIN(a, b)	(a < b ? a : b)
# define ABS(x)		(x < 0 ? -x : x)

typedef struct	s_env
{
	int			player;
	char		last[2];
	char		maj_p[2];
	char		**board;
	int			width;
	int			height;
	int			x;
	int			y;
	int			size_x;
	int			size_y;
	char		**piece;
	int			p_height;
	int			p_width;
}				t_env;

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

int				set_board(t_env *e, char *line);
int				play(t_env *e, t_coord pos, int i, int j);
void			get_enpos(t_env *e);
int				get_piece(t_env *e, char *line);
void			parse_line(t_env *e, char *line, int y, char **board);
void			free_piece(char **piece, int height);

#endif
