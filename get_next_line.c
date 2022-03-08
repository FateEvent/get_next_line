/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:48:12 by faventur          #+#    #+#             */
/*   Updated: 2022/03/08 11:55:46 by faventur         ###   ########.fr       */
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

char	*trim_and_stock(char *str)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_linelen(str);
	printf("%d", len);
	s = malloc(sizeof(char) * (len + 1));
	while (str[i] != '\n')
	{
		s[i] = str[i];
		printf("%c\n", s[i]);
		i++;
	}
	free(str);
	s[i++] = '\n';
	printf("%s\n", s);
	s[i] = '\0';
	return (s);
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
				ret = trim_and_stock(reading_buf);
				printf("ret: %s\n", ret);
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
	char	*dash;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buf = get_next_line(fd);
	krum = get_next_line(fd);
	dash = get_next_line(fd);

	close(fd);
	printf("return 1: %s", buf);
	printf("return 2: %s", krum);
	printf("return 3: %s", dash);
	free(buf);
	free(krum);
	free(dash);
	return (0);
}
