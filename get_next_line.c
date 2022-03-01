/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:48:12 by faventur          #+#    #+#             */
/*   Updated: 2022/03/01 17:12:10 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_SIZE 5000

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static int	line_number;
	int			i;
	int			bytes_read;
	char		*buffer;

	if (fd)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (i < line_number)
		{
			while (read(fd, &buffer, MAX_SIZE) != '\n')
			{
				
			}
		}
		bytes_read = read(fd, &buffer, MAX_SIZE);
	}
}