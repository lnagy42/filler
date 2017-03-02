/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputnbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:46 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:54 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	based_putnbr(unsigned long long n, char *base)
{
	if (n >= ft_strlen(base))
	{
		based_putnbr(n / ft_strlen(base), base);
		based_putnbr(n % ft_strlen(base), base);
	}
	else if (n < ft_strlen(base))
		ft_putchar(base[n]);
}

int		ctbase_nbr(unsigned long long n, char *base)
{
	int ct;

	ct = 0;
	while (n >= ft_strlen(base))
	{
		n /= ft_strlen(base);
		ct++;
	}
	ct++;
	return (ct);
}

void	long_putnbr(long long n)
{
	if (n == LONG_MIN)
		ft_putstr("-9223372036854775808");
	else if (n < 0)
		long_putnbr(-n);
	else if (n >= 10)
	{
		long_putnbr(n / 10);
		long_putnbr(n % 10);
	}
	else if (n < 10)
		ft_putchar(n + '0');
}

void	u_putnbr(unsigned long long n)
{
	if (n == LONG_MAX)
		ft_putstr("9223372036854775807");
	else if (n >= 10)
	{
		long_putnbr(n / 10);
		long_putnbr(n % 10);
	}
	else if (n < 10)
		ft_putchar(n + '0');
}

int		ctu_nbr(unsigned long long n)
{
	int ct;

	ct = 0;
	if (n == LONG_MAX)
		return (19);
	if (n < 10)
		return (1);
	while (n >= 10)
	{
		n /= 10;
		ct++;
	}
	ct++;
	return (ct);
}
