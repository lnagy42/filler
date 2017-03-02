/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 17:58:19 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		field_len(t_orderinfo *nfo, const char *len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (len[i] && ft_isdigit(len[i]))
	{
		nfo->fildwid = 1;
		tmp *= 10;
		tmp += len[i] - '0';
		i++;
	}
	nfo->lenfield = tmp;
	return (i);
}

int		wcharlen(wchar_t c, t_orderinfo *nfo)
{
	char	*bin;
	int		i;
	int		j;

	bin = get_unicode(c, nfo);
	i = 0;
	j = 0;
	while (bin[i])
	{
		i += 8;
		j++;
	}
	free(bin);
	return (j);
}

int		wstrlen(wchar_t *s, t_orderinfo *nfo)
{
	char	*bin;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		bin = get_unicode(s[i], nfo);
		while (bin[j])
		{
			j += 8;
			k++;
		}
		i++;
		free(bin);
	}
	return (k);
}

int		wdisplen(wchar_t *s, t_orderinfo *nfo)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = nfo->lenprec;
	k = 0;
	while (s[i] && j >= (len = wcharlen(s[i], nfo)))
	{
		j -= len;
		k += len;
		i++;
	}
	if (j && s[i] && nfo->prec)
		nfo->lenprec -= j;
	return (k);
}

int		dosharp(t_orderinfo *nfo, int ct)
{
	if ((nfo->conv_x && nfo->hash_flag) || nfo->conv_p)
	{
		write(1, "0x", 2);
		ct += 2;
	}
	else if (nfo->conv_bigx && nfo->hash_flag)
	{
		write(1, "0X", 2);
		ct += 2;
	}
	else if (nfo->conv_o && nfo->hash_flag)
	{
		write(1, "0", 1);
		ct++;
	}
	return (ct);
}
