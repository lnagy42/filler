/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:36:07 by lnagy             #+#    #+#             */
/*   Updated: 2016/11/10 18:05:32 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_enpos(t_env *e)
{
	int		i;
	char	*p;

	i = 0;
	while ((p = ft_strchr(e->board[i], e->maj_p[!e->player])) == NULL)
		i++;
	e->x = p - e->board[i];
	e->size_x = e->x;
	e->y = i;
	e->size_y = i;
}

int		check_piece(t_env *e, int w, int h, int k)
{
	int	i;
	int	j;

	j = 0;
	while (j < e->p_height)
	{
		i = 0;
		while (i < e->p_width)
		{
			if (e->piece[j][i] != '.')
			{
				if (j + h < 0 || i + w < 0 || j + h >= e->height ||
					i + w >= e->width || ft_tolower(e->board[j + h][i + w])
					== e->last[!e->player])
					return (-1);
				k += (ft_tolower(e->board[j + h][i + w]) ==
					e->last[e->player]);
				if (k == 2)
					return (-1);
			}
			i++;
		}
		j++;
	}
	return (k);
}

int		put_piece(t_env *e, int i, int j, t_coord *ret)
{
	int k;
	int	w;
	int	h;

	w = i - e->p_width + 1;
	while (w <= i)
	{
		h = j - e->p_height + 1;
		while (h <= j)
		{
			if ((k = check_piece(e, w, h, 0)) == 1)
			{
				ret->x = w;
				ret->y = h;
				return (MIN(ABS(e->x - w), ABS(e->size_x - w)) +
					MIN(ABS(e->y - h), ABS(e->size_y - h)));
			}
			h++;
		}
		w++;
	}
	return (-1);
}

int		play(t_env *e, t_coord pos, int i, int j)
{
	int		dist;
	int		new_d;
	t_coord	ret;

	dist = e->width + e->height;
	while (j < e->height)
	{
		i = 0;
		while (i < e->width)
		{
			if (ft_tolower(e->board[j][i]) == e->last[e->player])
				if ((new_d = put_piece(e, i, j, &ret)) != -1 && new_d < dist)
				{
					pos.x = ret.x;
					pos.y = ret.y;
					dist = new_d;
				}
			i++;
		}
		j++;
	}
	ft_printf("%d %d\n", pos.y, pos.x);
	return (pos.x == -1 && pos.y == -1 ? -1 : 0);
}
