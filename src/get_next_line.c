/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:11:38 by avallete          #+#    #+#             */
/*   Updated: 2016/09/06 22:13:06 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	t_list			*node;
	t_file			*file;

	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	file = (t_file*)((find_or_create_node(&list, fd))->content);
	while ((file->fpos = read(fd, readbuf, BUFF_SIZE)) > 0)
	{
		if (file->fpos < 0)
			return (-1);
		readbuf[file->fpos] = '\0';
	}
	if (buf2 && *buf2 && f > 0)
		join_buf(f, &buf2, &buf);
	if (f < 0)
		return (-1);
	if (buf && buf[0] != '\0')
		return (return_line(&buf, &buf2, line));
	ft_secfree(buf2);
	ft_secfree(buf);
	*line = NULL;
	return (0);
}
