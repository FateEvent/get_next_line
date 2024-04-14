/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:02:49 by faventur          #+#    #+#             */
/*   Updated: 2024/04/15 00:19:52 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"

void	test1(void)
{
	int		fd;
	char	*line;

	fd = open("tests/simple.txt", O_RDONLY);
	if (fd > -1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(int ac, char *av[])
{
	char	*line;
	int		fd;

	if (ac != 2)
		return (1);
	line = (void *)-1;
	fd = open(av[1], O_RDONLY);
	if (fd > -1)
	{
		while (line)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
		}
	}
	close(fd);
	test1();
}
