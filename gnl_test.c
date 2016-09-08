/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:48:02 by avallete          #+#    #+#             */
/*   Updated: 2016/09/08 14:54:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;

	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line))
		{
			printf("Line %d: '%s'\n", i, line);
			++i;
		}
	}
}
