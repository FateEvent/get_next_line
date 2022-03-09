/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:36:09 by faventur          #+#    #+#             */
/*   Updated: 2022/03/09 16:44:18 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The get_next_line() function returns a line read from a file descriptor.
*/

#include "get_next_line.h"

#include <stdio.h>
#define BUFFER_SIZE 2

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
	free(str);
	return (s);
}

char	*reader(char *reading_buf, char *buffer, int fd, int read_bytes)
{
	char	*tmp;
	char	*ret;

	while (read_bytes)
	{
		read_bytes = read(fd, &buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		tmp = reading_buf;
		reading_buf = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(reading_buf, '\n') != NULL)
		{
			printf("ret %s\n", ret);
			ret = trim_and_stock(reading_buf);
			reading_buf = ft_strchr(reading_buf, '\n');
			return (ret);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*reading_buf;
	char		*ret;
	int			read_bytes;

	if (!fd || fd < 0)
		return (NULL);
	if (!reading_buf)
	{
		reading_buf = malloc(sizeof(char) * 1);
		reading_buf[0] = '\0';
		if (!reading_buf)
			return (NULL);
	}
	read_bytes = 1;
	ret = reader(reading_buf, buffer, fd, read_bytes);
	return (ret);
}

void check_leaks();

int	main()
{
	int		fd;
	char	*buf;
	char	*krum;
	char	*dash;

	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buf = get_next_line(fd);
//	krum = get_next_line(fd);
//	dash = get_next_line(fd);

	close(fd);
	printf("return 1: %s", buf);
//	printf("return 2: %s", krum);
//	printf("return 3: %s", dash);
	free(buf);
//	free(krum);
//	free(dash);
	check_leaks();
	return (0);
}
