/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doflags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:54 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dozero(t_orderinfo *nfo, int ct, int neg)
{
	int nb;

	nb = ((nfo->plus_flag || (nfo->blank_flag && nfo->zero_flag)) &&
	!neg ? ct + 1 : ct);
	if (nfo->fildwid && nfo->lenfield > ct)
	{
		fill_str(nfo->lenfield - nb, '0');
		return (nfo->lenfield);
	}
	return (ct);
}

int	dominus(t_orderinfo *nfo, int ct)
{
	if (nfo->fildwid && nfo->lenfield > ct)
		fill_str(nfo->lenfield - ct, ' ');
	return (nfo->lenfield);
}

int	doplus(t_orderinfo *nfo, int i)
{
	if (nfo->plus_flag)
	{
		if (i < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
		return (1);
	}
	return (0);
}
