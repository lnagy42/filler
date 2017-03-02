/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 18:01:28 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list pa, t_orderinfo *nfo, const char *len)
{
	char	c;

	nfo->conv_c = 1;
	if (!nfo->minus_flag && nfo->fildwid)
		fill_str(nfo->lenfield - 1, nfo->zero_flag ? '0' : ' ');
	if (len[0] != 'c')
		write(1, len, 1);
	else
	{
		c = va_arg(pa, int);
		write(1, &c, 1);
	}
	if (nfo->minus_flag && nfo->fildwid)
		fill_str(nfo->lenfield - 1, ' ');
	return (nfo->lenfield > 1 ? nfo->lenfield : 1);
}
