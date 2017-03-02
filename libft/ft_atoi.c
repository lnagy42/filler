/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:09:55 by lnagy             #+#    #+#             */
/*   Updated: 2017/03/02 14:31:33 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(char *s)
{
	int	tmp;
	int	i;
	int	sig;

	sig = 1;
	i = 0;
	tmp = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		++i;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		tmp = tmp * 10;
		tmp = tmp + s[i] - '0';
		++i;
	}
	return (tmp * sig);
}

static int		is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *s, char *base)
{
	int	nb;
	int	i;
	int	sig;

	sig = 1;
	i = 0;
	nb = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		++i;
	}
	while (s[i] && is_in_base(base, s[i]) != -1)
	{
		nb = nb * ft_strlen(base);
		nb = nb + is_in_base(base, s[i]);
		++i;
	}
	return (nb * sig);
}

char			*ft_itoa_binary(int nb)
{
	char	*tmp;
	int		size;
	int		rebornnb;

	size = 0;
	rebornnb = nb;
	while (nb > 0)
	{
		nb /= 2;
		size++;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
	{
		tmp[size] = rebornnb % 2 + '0';
		rebornnb /= 2;
	}
	return (tmp);
}
