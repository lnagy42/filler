/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 18:01:58 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					get_lenmod(t_orderinfo *nfo, const char *len)
{
	int	i;

	i = 0;
	if (len[i] == 'h' || len[i] == 'l' || len[i] == 'j' || len[i] == 'z')
	{
		nfo->len_mod = len[i];
		if (len[++i] == 'h' || len[i] == 'l')
		{
			nfo->len_mod = ft_toupper(len[i]);
			i++;
		}
	}
	return (i);
}

int					get_prec(t_orderinfo *nfo, const char *len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (len[i] == '.')
	{
		nfo->prec = 1;
		if (len[++i] == '-')
		{
			tmp = 0;
			i++;
		}
		else
			tmp = ft_atoi((char *)len + 1);
		while (len[i] && ft_isdigit(len[i]))
			i++;
	}
	nfo->lenprec = tmp;
	return (i);
}

long long			do_lenmod(t_orderinfo *nfo, va_list pa, char conv)
{
	long long	lenmod;

	lenmod = 0;
	if (nfo->len_mod == 'l')
		((lenmod = va_arg(pa, long)));
	else if (nfo->len_mod == 'L')
		((lenmod = va_arg(pa, long long)));
	else if (nfo->len_mod == 'j')
		((lenmod = va_arg(pa, intmax_t)));
	else if (nfo->len_mod == 'z')
		((lenmod = va_arg(pa, ssize_t)));
	else if (nfo->len_mod == 'h' && ft_toupper(conv) != conv)
		((lenmod = (short)va_arg(pa, int)));
	else if (nfo->len_mod == 'h')
		((lenmod = va_arg(pa, int)));
	else if (nfo->len_mod == 'H' && ft_toupper(conv) != conv)
		((lenmod = (char)va_arg(pa, int)));
	else if (nfo->len_mod == 'H')
		((lenmod = va_arg(pa, int)));
	else
		((lenmod = va_arg(pa, long)));
	return (lenmod);
}

unsigned long long	do_ulenmod(t_orderinfo *nfo, va_list pa, char conv)
{
	unsigned long long	lenmod;

	lenmod = 0;
	if (nfo->len_mod == 'l')
		((lenmod = va_arg(pa, unsigned long)));
	else if (nfo->len_mod == 'L')
		((lenmod = va_arg(pa, unsigned long long)));
	else if (nfo->len_mod == 'j')
		((lenmod = va_arg(pa, uintmax_t)));
	else if (nfo->len_mod == 'z')
		((lenmod = va_arg(pa, size_t)));
	else if (nfo->len_mod == 'h' && ft_toupper(conv) != conv)
		((lenmod = (unsigned short)va_arg(pa, unsigned int)));
	else if (nfo->len_mod == 'h')
		((lenmod = va_arg(pa, unsigned int)));
	else if (nfo->len_mod == 'H' && (ft_toupper(conv) != conv || conv == 'X'))
		((lenmod = (unsigned char)va_arg(pa, unsigned int)));
	else if (nfo->len_mod == 'H')
		((lenmod = va_arg(pa, unsigned int)));
	return (lenmod);
}

int					ct_nbr(long long n)
{
	int ct;

	ct = 0;
	if (n == LONG_MIN)
		return (20);
	else if (n < 0)
	{
		ct++;
		n = -n;
	}
	else if (n < 10)
		return (1);
	while (n >= 10)
	{
		n /= 10;
		ct++;
	}
	ct++;
	return (ct);
}
