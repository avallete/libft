/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:36 by avallete          #+#    #+#             */
/*   Updated: 2015/01/22 14:26:40 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s)
{
	int		i;
	char	*scop;

	if (s)
	{
		i = ((ft_strlen(s)) + 1);
		if ((scop = ((char*)malloc(sizeof(char) * i))))
		{
			ft_strcpy(scop, s);
			return (scop);
		}
	}
	return (NULL);
}
