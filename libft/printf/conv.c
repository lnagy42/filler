/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 18:00:52 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(va_list pa, t_orderinfo *nfo, const char *len)
{
	char	*s;
	int		ct;

	(void)len;
	nfo->conv_s = 1;
	s = va_arg(pa, char *);
	if (!s)
		s = "(null)";
	ct = ft_strlen(s);
	if (nfo->prec && nfo->lenprec < ct)
		ct = nfo->lenprec;
	if (!nfo->minus_flag && nfo->fildwid)
		fill_str(nfo->lenfield - ct, nfo->zero_flag ? '0' : ' ')
	;
	write(1, s, ct);
	if (nfo->minus_flag && nfo->fildwid)
		fill_str(nfo->lenfield - ct, ' ');
	return (nfo->lenfield > ct ? nfo->lenfield : ct);
}

void	fill_str(int nb_typ, char type)
{
	char	*s;

	if (nb_typ <= 0)
		return ;
	s = ft_memalloc(nb_typ + 1);
	ft_memset(s, type, nb_typ);
	write(1, s, nb_typ);
	free(s);
}

char	*print_ox2(t_orderinfo *nfo, const char *len)
{
	char				*s;

	if (len[0] == 'x' || len[0] == 'p')
	{
		if (len[0] == 'p')
			nfo->conv_p = 1;
		nfo->conv_x = 1;
		s = "0123456789abcdef";
	}
	else if (len[0] == 'X')
	{
		s = "0123456789ABCDEF";
		nfo->conv_bigx = 1;
	}
	else if (len[0] == 'o' || len[0] == 'O')
	{
		s = "01234567";
		nfo->conv_o = 1;
	}
	else
	{
		nfo->conv_base = 1;
		s = "0123456789";
	}
	return (s);
}

int		print_ox(va_list pa, t_orderinfo *nfo, const char *len)
{
	unsigned long long	i;
	int					ct;
	char				*s;

	s = NULL;
	if (nfo->len_mod == 0 && (ft_toupper(len[0]) != len[0] || len[0] == 'X')
		&& len[0] != 'p')
		i = va_arg(pa, unsigned);
	else if (nfo->len_mod == 0)
		i = va_arg(pa, unsigned long long);
	else
		i = do_ulenmod(nfo, pa, len[0]);
	s = print_ox2(nfo, len);
	ct = ctbase_nbr(i, s);
	ct = do_pox(nfo, ct, i);
	if (!nfo->prec || nfo->lenprec || i)
		based_putnbr(i, s);
	else
		ct--;
	if (nfo->minus_flag && nfo->lenfield > ct)
		ct = dominus(nfo, ct);
	return (ct);
}

int		print_dec(va_list pa, t_orderinfo *nfo, const char *len)
{
	long long	i;
	int			ct;

	nfo->conv_d = 1;
	if ((nfo->len_mod == 0 && len[0] != 'D') || (nfo->len_mod == 'h' &&
		len[0] == 'D'))
		i = va_arg(pa, int);
	else
		i = do_lenmod(nfo, pa, len[0]);
	ct = ct_nbr(i);
	ct = do_di(nfo, ct, i);
	if (!nfo->prec || nfo->lenprec || i)
		u_putnbr(i < 0 ? -(long long)i : i);
	else
		ct--;
	if (nfo->minus_flag && nfo->lenfield > ct)
		ct = dominus(nfo, ct);
	return (ct);
}
