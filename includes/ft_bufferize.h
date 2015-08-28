/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 11:05:07 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 12:25:45 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFERIZE
# define FT_BUFFERIZE
# include "libft.h"
# include <stdbool.h>
# define BUFFERIZE_SIZE 2048

int     ft_bufferize(int fd, char *str, bool flush);
#endif