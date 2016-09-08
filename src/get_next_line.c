/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:11:38 by avallete          #+#    #+#             */
/*   Updated: 2016/09/08 17:49:06 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int			fd_cmp(void *data, void *fd)
{
	if (((t_file*)data)->fd == *((int*)fd))
		return (0);
	return (-1);
}

static	t_file		*new_file(int fd)
{
	t_file *new;

	new = (t_file*)malloc(sizeof(t_file));
	new->fd = fd;
	new->fpos = 0;
	new->remainbuf = NULL;
	return (new);
}

t_list				*find_or_create_node(t_list **lst, int fd)
{
	t_list *ret;

	ret = NULL;
	if (*lst && (ret = ft_lstfind(*lst, fd_cmp, &fd)))
		return (ret);
	else if (*lst == NULL)
		*lst = ft_lstnew(new_file(fd), sizeof(t_file));
	else
		ft_lstadd(lst, ft_lstnew(new_file(fd), sizeof(t_file)));
	return (*lst);
}

int					get_next_line(int const fd, char **line)
{
	static	t_list	*list = NULL;
	char			readbuf[BUFF_SIZE + 1];
	char			*endline;
	t_file			*file;

	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	file = (t_file*)((find_or_create_node(&list, fd))->content);
	*line = NULL;
	while	(((file->fpos = read(fd, readbuf, BUFF_SIZE)) > 0))
	{
		if (file->fpos < 0)
			return (-1);
		readbuf[file->fpos] = '\0';
		endline = ft_strchr(readbuf, '\n');
		if (!endline)
			*line = ft_strrealloc(*line, ft_strjoin(*line, readbuf));
		else
		{
			*endline = '\0';
			*line = ft_strrealloc(*line, ft_strjoin(*line, readbuf));
			file->remainbuf = ft_strrealloc(file->remainbuf, ft_strdup(endline + 1));
			return (1);
		}
	}
	return (0);
}
