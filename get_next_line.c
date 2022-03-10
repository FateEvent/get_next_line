/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:36:09 by faventur          #+#    #+#             */
/*   Updated: 2022/03/10 19:43:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The get_next_line() function returns a line read from a file descriptor.
*/

#include "get_next_line.h"

#include <stdio.h>
//#define BUFFER_SIZE 2

char	*ft_rest(char *reading_buf)
{
	int		i;
	int		j;
	char	*s;

	i = ft_strlen(reading_buf);
	j = 0;
	if (!reading_buf)
		return (NULL);
	while (reading_buf[j] && reading_buf[j] != '\n')
		j++;
	if (reading_buf[j] == '\0')
	{
		free (reading_buf);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (i - j));
	if (!s)
		return (NULL);
	i = 0;
	j++;
	while (reading_buf[j])
		s[i++] = reading_buf[j++];
	s[i] = '\0';
	free (reading_buf);
	return (s);
}

char	*ft_last_line(char *reading_buf)
{
	char	*s;
	int		i;

	i = 0;
	if (!reading_buf)
		return (NULL);
	while (reading_buf[i] && reading_buf[i] != '\n')
		i++;
	if (reading_buf[0] == 0)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (reading_buf[i++] != '\0')
		s[i] = reading_buf[i];
	if (reading_buf[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*ft_reader(int fd, char *buffer, char *reading_buf, char *tmp)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = reading_buf;
		if (!tmp)
		{
			tmp = (char *)malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		reading_buf = ft_strjoin(tmp, buffer);
		free(tmp);
		if (strchr(reading_buf, '\n'))
			break ;
	}
	free(buffer);
	return (reading_buf);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*reading_buf;
	char		*ret;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	reading_buf = ft_reader(fd, buffer, reading_buf, tmp);
	if (!reading_buf)
		return (NULL);
	ret = ft_last_line(reading_buf);
	reading_buf = ft_rest(reading_buf);
	return (ret);
}
/*
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
	krum = get_next_line(fd);
	dash = get_next_line(fd);

	close(fd);
	printf("return 1: %s", buf);
	printf("return 2: %s", krum);
	printf("return 3: %s", dash);
	free(buf);
	free(krum);
	free(dash);
	check_leaks();
	return (0);
}
*/