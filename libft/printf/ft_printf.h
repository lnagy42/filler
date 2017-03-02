/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 01:53:06 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 18:00:07 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft.h"

typedef struct		s_orderinfo
{
	int		zero_flag;
	int		blank_flag;
	int		minus_flag;
	int		plus_flag;
	int		hash_flag;
	int		lenfield;
	int		fildwid;
	int		lenprec;
	int		prec;
	int		len_mod;
	int		conv_s;
	int		conv_c;
	int		conv_d;
	int		conv_x;
	int		conv_bigx;
	int		conv_o;
	int		conv_p;
	int		conv_base;
	int		conv_bigc;
	int		ct_wchar;
	int		ct_wstr;
}					t_orderinfo;

typedef struct		s_applyf
{
	char	conv;
	int		(*f)(va_list pa, t_orderinfo *nfo, const char *len);
}					t_applyf;
# define B		__attribute__ ((format (printf, 1, 2)))
# define A		int	ft_printf(const char *format, ...) B;

A;
# undef A
# undef B

int					ft_atoi_base(const char *s, char *base);
char				*ft_itoa_binary(int nb);
void				long_putnbr(long long n);
void				u_putnbr(unsigned long long n);
void				based_putnbr(unsigned long long n, char *base);
int					ctbase_nbr(unsigned long long n, char *base);
int					ctu_nbr(unsigned long long n);
int					ct_nbr(long long n);
int					do_fldlen(t_orderinfo *nfo, int ct, int neg);
int					do_fldp(t_orderinfo *nfo, int ct);
int					do_di(t_orderinfo *nfo, int ct, long long i);
int					do_pox(t_orderinfo *nfo, int ct, int i);
char				*fullspace(void);
char				*fullzero(void);
void				fill_str(int nb_typ, char type);
int					dozero(t_orderinfo *nfo, int ct, int neg);
int					doplus(t_orderinfo *nfo, int i);
int					dominus(t_orderinfo *nfo, int ct);
int					dosharp(t_orderinfo *nfo, int ct);
int					print_wstr(va_list pa, t_orderinfo *nfo, const char *len);
int					print_string(va_list pa, t_orderinfo *nfo, const char *len);
int					print_dec(va_list pa, t_orderinfo *nfo, const char *len);
int					print_udec(va_list pa, t_orderinfo *nfo, const char *len);
int					print_ox(va_list pa, t_orderinfo *nfo, const char *len);
int					print_char(va_list pa, t_orderinfo *nfo, const char *len);
int					print_p(va_list pa, t_orderinfo *nfo, const char *len);
int					print_wchar(va_list pa, t_orderinfo *nfo, const char *len);
char				*get_unicode(int c, t_orderinfo *nfo);
int					wdisplen(wchar_t *s, t_orderinfo *nfo);
int					wstrlen(wchar_t *s, t_orderinfo *nfo);
int					wcharlen(wchar_t c, t_orderinfo *nfo);
int					dispatcher(const char *format, va_list pa,
	t_orderinfo *nfo);
int					flag_dispatcher(const char *format, t_orderinfo *nfo);
long long			do_lenmod(t_orderinfo *nfo, va_list pa, char conv);
unsigned long long	do_ulenmod(t_orderinfo *nfo, va_list pa, char conv);
int					field_len(t_orderinfo *nfo, const char *len);
int					get_prec(t_orderinfo *nfo, const char *len);
int					get_lenmod(t_orderinfo *nfo, const char *len);
void				init_nfo(t_orderinfo *nfo);

#endif
