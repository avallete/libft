/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:11:38 by avallete          #+#    #+#             */
/*   Updated: 2016/09/18 00:43:08 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			bufferize(char **dest, char *content)
{
	char *ret;

	ret = NULL;
	ret = ft_strjoin(*dest, content);
	ft_secfree(*dest);
	*dest = ret;
}

static char			*get_line(char **buf)
{
	char *truncbuf;
	char *linepos;
	char *ret;

	truncbuf = NULL;
	ret = NULL;
	if (*buf)
	{
		linepos = ft_strchr(*buf, '\n');
		if (linepos)
		{
			*linepos = '\0';
			truncbuf = ft_strdup(linepos + 1);
		}
		ret = ft_strdup(*buf);
		ft_secfree(*buf);
		*buf = truncbuf;
	}
	return (ret);
}

static t_list		*file_exist(t_list *list, int fd)
{
	while (list)
	{
		if ((t_line*)(list->data)->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static t_list		*handle_multiple_fd(t_list **list, int fd)
{
	t_line			node;
	t_list			*ret;

	if (*list && (ret = file_exist(*list, fd)))
		return (ret);
	else
	{
		node.buf = NULL;
		node.fd = fd;
		if (!(*list))
			*list = ft_lstnew(&node, sizeof(t_line));
		else
			ft_lstadd(list, ft_lstnew(&node, sizeof(t_line)));
		return (*list);
	}
}

int					get_next_line(int const fd, char **line)
{
	int				f;
	char			tmpbuf[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*node;

	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	node = handle_multiple_fd(&list, fd);
	tmpbuf[BUFF_SIZE] = '\0';
	while ((!(ft_strchr((t_line*)(node->data)->buf, '\n'))) &&\
			((f = read(fd, tmpbuf, BUFF_SIZE)) > 0))
	{
		tmpbuf[f] = 0;
		bufferize(&((t_line*)(node->data)->buf), (char*)(tmpbuf));
	}
	if (f < 0)
		return (-1);
	*line = get_line(&((t_line*)(node->data)->buf));
	if (((t_line*)(node->data)->buf))
		return (1);
	return (0);
}
