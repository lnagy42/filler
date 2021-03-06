/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:30:49 by cchaumar          #+#    #+#             */
/*   Updated: 2016/10/21 18:25:07 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			if (*(s + i) == (char)c)
				return ((char *)s + i);
			else
				i++;
	}
	return ((c == 0) ? ((char *)s + i) : NULL);
}
