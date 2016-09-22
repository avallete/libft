/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strepur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:50:18 by avallete          #+#    #+#             */
/*   Updated: 2016/09/22 20:59:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	epur_len(const char *source)
{
	int		i;
	int		space_sequence;
	size_t	origin_len;

	i = 0;
	origin_len = ft_strlen(source);
	while (source[i])
	{
		++i;
		if (ft_isspace(source[i]))
		{
			space_sequence = 0;
			while (ft_isspace(source[i]))
			{
				++space_sequence;
				++i;
			}
			origin_len -= space_sequence;
		}
	}
	return (origin_len);
}

char			*ft_strepur(const char *source)
{
	size_t	newlen;
	int		i;
	int		e;
	char	*epuredstr;

	i = 0;
	e = 0;
	epuredstr = NULL;
	if (source && (newlen = epur_len(source)))
	{
		if ((epuredstr = ft_strnew(newlen + 1)))
		{
			while (source[i])
			{
				if (!(ft_isspace(source[i])))
					epuredstr[e++] = source[i++];
				else
				{
					epuredstr[e++] = ' ';
					while (ft_isspace(source[i]))
						++i;
				}
			}
			epuredstr[e] = '\0';
		}
	}
	return (epuredstr);
}
