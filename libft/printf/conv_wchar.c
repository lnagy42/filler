/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:54 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putwchar(int c, t_orderinfo *nfo)
{
	char	*bin;
	char	*leaks;
	int		i;

	bin = get_unicode(c, nfo);
	i = 0;
	while (bin[i])
	{
		if (c < 128)
			ft_putchar(c);
		else
			ft_putchar(ft_atoi_base((leaks = ft_strndup(bin + i, 8)), "01"));
		if (c > 127)
			free(leaks);
		i += 8;
		(nfo->ct_wchar)++;
	}
	free(bin);
}

static void	fldlen_wstr(int len, t_orderinfo *nfo)
{
	while (nfo->lenfield > len)
	{
		if (nfo->zero_flag && !nfo->minus_flag)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(nfo->ct_wchar)++;
		(nfo->lenfield)--;
	}
}

int			print_wstr(va_list pa, t_orderinfo *nfo, const char *len)
{
	wchar_t	*s;
	int		i;
	int		j;

	(void)len;
	i = 0;
	s = va_arg(pa, wchar_t *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (!nfo->minus_flag)
		fldlen_wstr((nfo->prec ? wdisplen(s, nfo) : wstrlen(s, nfo)), nfo);
	j = (nfo->prec ? nfo->lenprec : wstrlen(s, nfo));
	while (s[i] && j >= wcharlen(s[i], nfo))
	{
		putwchar(s[i], nfo);
		j -= wcharlen(s[i], nfo);
		i++;
	}
	fldlen_wstr((nfo->prec ? wdisplen(s, nfo) : wstrlen(s, nfo)), nfo);
	return (nfo->ct_wchar);
}

int			print_wchar(va_list pa, t_orderinfo *nfo, const char *len)
{
	char	*bin;
	char	*leaks;
	int		i;
	int		big_c;

	nfo->conv_c = 1;
	big_c = va_arg(pa, int);
	bin = get_unicode(big_c, nfo);
	(void)len;
	i = 0;
	while (bin[i])
	{
		if (big_c < 128)
			ft_putchar(big_c);
		else
			ft_putchar(ft_atoi_base((leaks = ft_strndup(bin + i, 8)), "01"));
		if (big_c > 127)
			free(leaks);
		else
			return (1);
		i += 8;
		(nfo->ct_wchar)++;
	}
	free(bin);
	return (nfo->ct_wchar);
}

char		*get_unicode(int c, t_orderinfo *nfo)
{
	char	*bin;
	char	*code;
	int		i;
	int		j;

	nfo->conv_bigc = c;
	bin = ft_itoa_binary(c);
	if (c < 2048)
		code = c < 128 ? ft_strdup("0xxxxxxx") : ft_strdup("110xxxxx10xxxxxx");
	else if (c < 131072)
		code = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else
		code = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	i = ft_strlen(code);
	j = ft_strlen(bin) - 1;
	while (--i > 0)
		if (code[i] == 'x')
		{
			if (j >= 0)
				code[i] = bin[j--];
			else
				code[i] = '0';
		}
	free(bin);
	return (code);
}
