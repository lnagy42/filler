/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:54 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_pox2(t_orderinfo *nfo, int ct, int a)
{
	if (nfo->zero_flag && !nfo->prec && nfo->fildwid && nfo->lenfield > ct)
		fill_str(nfo->lenfield - ct, '0');
	if (nfo->prec && !nfo->fildwid && nfo->lenprec > ct && nfo->conv_o)
	{
		fill_str(nfo->lenprec - ct, '0');
		ct = nfo->lenprec;
	}
	else if (nfo->prec && !nfo->fildwid && nfo->lenprec > ct)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec + a;
	}
	else if (nfo->prec && nfo->fildwid && nfo->lenprec > ct &&
		nfo->lenfield > nfo->lenprec)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec;
	}
	else if (nfo->prec && nfo->fildwid && nfo->lenfield < nfo->lenprec &&
		nfo->lenprec > ct)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec + a;
	}
	return (ct);
}

int			do_pox(t_orderinfo *nfo, int ct, int i)
{
	int	a;

	a = (nfo->conv_p || (nfo->hash_flag && (nfo->conv_x || nfo->conv_bigx)))
		* 2 + (nfo->conv_o && nfo->hash_flag);
	if (!nfo->prec && !nfo->minus_flag && nfo->fildwid && !nfo->zero_flag &&
		nfo->lenfield > ct && i)
		fill_str(nfo->lenfield - ct - a, ' ');
	else if (nfo->prec && nfo->fildwid && !nfo->minus_flag && nfo->lenprec > ct
		&& nfo->lenfield > nfo->lenprec)
		fill_str(nfo->lenfield - nfo->lenprec - a, ' ');
	else if (nfo->prec && nfo->fildwid && !nfo->minus_flag && nfo->lenprec <= ct
		&& nfo->lenfield > nfo->lenprec)
		fill_str(nfo->lenfield - ct - a + (!i && !nfo->lenprec ? 1 : 0), ' ');
	else if (nfo->fildwid && !nfo->minus_flag && nfo->lenfield > ct &&
		nfo->conv_p && !nfo->zero_flag)
		fill_str(nfo->lenfield - ct - a, ' ');
	if (i || nfo->conv_p || (nfo->conv_o && nfo->prec))
		ct = dosharp(nfo, ct);
	ct = do_pox2(nfo, ct, a);
	if (nfo->lenfield > ct && !nfo->minus_flag)
		return (nfo->lenfield + (nfo->prec && nfo->fildwid && !i &&
			!nfo->lenprec ? 1 : 0));
		return (ct);
}

static int	pik_flag(t_orderinfo *nfo, int ct, int neg)
{
	if (neg)
		ft_putchar('-');
	else if (nfo->plus_flag)
	{
		ft_putchar('+');
		ct++;
	}
	else if (nfo->blank_flag)
	{
		ft_putchar(' ');
		ct++;
	}
	return (ct);
}

static int	do_di2(t_orderinfo *nfo, int ct, int a)
{
	if (nfo->prec && !nfo->fildwid && nfo->lenprec > ct)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec + a;
	}
	else if (nfo->prec && nfo->fildwid && nfo->lenprec > ct &&
		nfo->lenfield > nfo->lenprec)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec;
	}
	else if (nfo->prec && nfo->fildwid && nfo->lenprec == ct &&
		nfo->lenfield > nfo->lenprec)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec + a;
	}
	else if (nfo->prec && nfo->fildwid && nfo->lenfield < nfo->lenprec &&
		nfo->lenprec > ct)
	{
		fill_str(nfo->lenprec - ct + a, '0');
		ct = nfo->lenprec + a;
	}
	return (ct);
}

int			do_di(t_orderinfo *nfo, int ct, long long i)
{
	int	a;

	a = (i < 0 || nfo->plus_flag || nfo->blank_flag) ? 1 : 0;
	if (!nfo->prec && nfo->fildwid && !nfo->minus_flag && !nfo->zero_flag &&
		nfo->lenfield > ct)
		fill_str(nfo->lenfield - ct, ' ');
	else if (nfo->prec && nfo->fildwid && !nfo->minus_flag && nfo->lenprec > ct
		&& nfo->lenfield > nfo->lenprec)
		fill_str(nfo->lenfield - nfo->lenprec - a, ' ');
	else if (nfo->prec && nfo->fildwid && !nfo->minus_flag && nfo->lenprec < ct
		&& nfo->lenfield > nfo->lenprec)
		fill_str(nfo->lenfield - ct + (!i && !nfo->lenprec ? 1 : 0), ' ');
	ct = pik_flag(nfo, ct, i < 0 ? 1 : 0);
	if (nfo->zero_flag && !nfo->prec && nfo->fildwid && nfo->lenfield > ct)
		fill_str(nfo->lenfield - ct, '0');
	ct = do_di2(nfo, ct, a);
	if (nfo->lenfield > ct && !nfo->minus_flag)
		return (nfo->lenfield + (nfo->prec && nfo->fildwid && !i &&
			!nfo->lenprec ? 1 : 0));
		return (ct);
}
