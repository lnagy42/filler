/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:54 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_func_for_conv(char spec, t_applyf *p)
{
	const t_applyf	rely[] = {
	{'s', &print_string}, {'S', &print_wstr}, {'p', &print_ox},
	{'d', &print_dec}, {'D', &print_dec}, {'i', &print_dec},
	{'o', &print_ox}, {'O', &print_ox}, {'u', &print_ox},
	{'U', &print_ox}, {'x', &print_ox}, {'X', &print_ox},
	{'c', &print_char}, {'C', &print_wchar}, {'%', &print_char},
	{0, NULL}};
	int				i;

	i = 0;
	while (rely[i].conv)
		if (rely[i].conv == spec)
		{
			*p = rely[i];
			return ;
		}
		else
			i++;
}

void		init_nfo(t_orderinfo *nfo)
{
	nfo->zero_flag = 0;
	nfo->blank_flag = 0;
	nfo->minus_flag = 0;
	nfo->plus_flag = 0;
	nfo->hash_flag = 0;
	nfo->lenfield = 0;
	nfo->fildwid = 0;
	nfo->lenprec = 0;
	nfo->prec = 0;
	nfo->len_mod = 0;
	nfo->conv_s = 0;
	nfo->conv_c = 0;
	nfo->conv_d = 0;
	nfo->conv_x = 0;
	nfo->conv_bigx = 0;
	nfo->conv_o = 0;
	nfo->conv_p = 0;
	nfo->conv_base = 0;
	nfo->conv_bigc = 0;
	nfo->ct_wchar = 0;
	nfo->ct_wstr = 0;
}

int			dispatcher(const char *format, va_list pa, t_orderinfo *nfo)
{
	char		conv;
	int			i;
	t_applyf	p;

	i = 0;
	if (nfo->len_mod == 'l' && (format[0] == 's' || format[0] == 'c'))
		conv = format[0] == 's' ? 'S' : 'C';
	else
		conv = format[0];
	get_func_for_conv(conv, &p);
	if (p.conv)
		return (p.f(pa, nfo, format));
	return (print_char(pa, nfo, format));
}

int			flag_dispatcher(const char *format, t_orderinfo *nfo)
{
	int		i;
	int		j;
	int		*tmpnfo;
	char	*flags;

	flags = "0 -+#";
	tmpnfo = (int *)nfo;
	j = 1;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == format[j])
		{
			tmpnfo[i] = 1;
			i = -1;
			j++;
		}
		i++;
	}
	j += field_len(nfo, format + j);
	j += get_prec(nfo, format + j);
	j += get_lenmod(nfo, format + j);
	if (nfo->minus_flag)
		nfo->zero_flag = 0;
	return (j);
}

int			ft_printf(const char *format, ...)
{
	t_orderinfo	nfo;
	va_list		pa;
	int			i;
	int			ct;

	ct = 0;
	i = 0;
	va_start(pa, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_nfo(&nfo);
			i += flag_dispatcher(format + i, &nfo);
			ct += dispatcher(format + i, pa, &nfo);
		}
		else
		{
			write(1, format + i, 1);
			++ct;
		}
		++i;
	}
	va_end(pa);
	return (ct);
}
