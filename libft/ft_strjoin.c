/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:21:20 by cchaumar          #+#    #+#             */
/*   Updated: 2016/10/21 18:28:52 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*o;
	size_t	i;
	size_t	j;

	i = s1 ? ft_strlen(s1) : 0;
	j = s2 ? ft_strlen(s2) : 0;
	if ((o = (char *)malloc(i + j + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
		{
			o[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j])
		{
			o[i + j] = s2[j];
			j++;
		}
	o[i + j] = '\0';
	return (o);
}
