/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:31:31 by avallete          #+#    #+#             */
/*   Updated: 2016/09/06 22:13:09 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft.h>
# define BUFF_SIZE 4096

typedef struct		s_file
{
	int				fd;
	int				fpos;
	char			*remainbuf;
}					t_file;

int					get_next_line(int const fd, char **line);
#endif
