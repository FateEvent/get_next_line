/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:48:12 by faventur          #+#    #+#             */
/*   Updated: 2022/03/07 20:13:05 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The get_next_line() function returns a line read from a file descriptor.
*/

#include "get_next_line.h"
#define BUFFER_SIZE 5

#include <stdio.h>

size_t	ft_linelen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\n')
		counter++;
	counter++;
	return (counter);
}

// partir sur une struct ou un tableau pour ne garder qu'une variable statique pour les bonus
char	*get_next_line(int fd)
{
	int			bytes_to_read;
	int			read_bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*reading_buf;
	char		*ret;

	reading_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd)
	{
		while (read_bytes = read(fd, &buffer, BUFFER_SIZE))
		{
			buffer[read_bytes] = '\0';
			printf("buffer: %s\n", buffer);
			if (ft_strchr(reading_buf, '\n') != NULL)
			{
				ret = reading_buf;
				bytes_to_read = ft_linelen(buffer);
				reading_buf = malloc(sizeof(char) * (bytes_to_read + 1));
				while (*buffer != '\n')
					*(reading_buf)++ = (*buffer)++;
				*(reading_buf)++ = 'x';
//				*(reading_buf)++ = '\n';
				*(reading_buf)++ = '\0';
				return (ret);
			}
			else
			{
				reading_buf = ft_strjoin(reading_buf, buffer);
				printf("read: %s\n", reading_buf);
			}
		}
		
			/*
			if (bytes_to_read == BUFFER_SIZE || !(buffer[0]))
				bytes_read = read(fd, &buffer, MAX_SIZE);
			*/
	}
	return (NULL);
}

int	main()
{
	int		bytes_read;
	int		fd;
	char	*buf;
	char 	*krum;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buf = get_next_line(fd);
//	krum = get_next_line(fd);

	close(fd);
	printf("return 1: %s", buf);
//	printf("return 2: %s", krum);
	free(buf);
	return (0);
}
