/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:11:21 by avallete          #+#    #+#             */
/*   Updated: 2015/05/29 20:49:05 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void                ft_dlstdelone(t_dlst **lst)
{
    t_dlst *tmp;

    if (*lst)
    {
        tmp = *lst;
        if ((*lst)->back)
            (*lst)->back->next = (*lst)->next;
        if ((*lst)->next)
            (*lst)->next->back = (*lst)->back;
        free(tmp);
        tmp = NULL;
    }
}
