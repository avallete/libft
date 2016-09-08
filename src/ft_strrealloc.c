/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:02:46 by avallete          #+#    #+#             */
/*   Updated: 2016/09/08 14:04:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrealloc(char *old_str, char *new_str)
{
	ft_secfree(old_str);
	return (new_str);
}
