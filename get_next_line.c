/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:48:12 by faventur          #+#    #+#             */
/*   Updated: 2022/03/08 17:35:25 by faventur         ###   ########.fr       */
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

	i = 0;
	s = malloc(sizeof(char) * (ft_linelen(str) + 1));
	while (str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

// partir sur une struct ou un tableau pour ne garder qu'une variable statique pour les bonus
char	*get_next_line(int fd)
{
	int			read_bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*reading_buf;
	char		*ret;

	reading_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reading_buf || !fd || fd < 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes)
	{
		printf("%d", read_bytes);
		read_bytes = read(fd, &buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
		{
			free(reading_buf);
			reading_buf = ft_strjoin(reading_buf, buffer);
			ret = trim_and_stock(reading_buf);
			free(reading_buf);
			return (ret);
		}
		else
		{
			free(reading_buf);
			reading_buf = ft_strjoin(reading_buf, buffer);
		}
	}
	return (NULL);
}

int	main()
{
	int		fd;
	char	*buf;
	char	*krum;
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
