/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:36:09 by faventur          #+#    #+#             */
/*   Updated: 2024/04/15 00:08:43 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The get_next_line() function returns a line read from a file descriptor.
*/

#include "get_next_line.h"

static char	*ft_rest(char *reading_buf)
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
		free(reading_buf);
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
	free(reading_buf);
	return (s);
}

static char	*ft_last_line(char *reading_buf)
{
	char	*s;
	int		i;

	i = 0;
	if (!reading_buf)
		return (NULL);
	while (reading_buf[i] && reading_buf[i] != '\n')
		i++;
	if (reading_buf[0] == '\0')
		return (NULL);
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (reading_buf[i] != '\n' && reading_buf[i])
	{
		s[i] = reading_buf[i];
		i++;
	}
	if (reading_buf[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

static char	*create_tmp_or_return(char **buffer, char *reading_buf, char **tmp)
{
	if (buffer)
	{
		free(*buffer);
		return (NULL);
	}
	*tmp = reading_buf;
	if (!(*tmp))
	{
		*tmp = (char *)malloc(sizeof(char) * 1);
		if (!(*tmp))
			return (NULL);
		*tmp[0] = '\0';
	}
	return (NULL);
}

static char	*ft_reader(int fd, char *buffer, char *reading_buf, char *tmp)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (create_tmp_or_return(&buffer, NULL, NULL));
		buffer[bytes_read] = '\0';
		create_tmp_or_return(NULL, reading_buf, &tmp);
		if (!tmp)
			return (create_tmp_or_return(&buffer, NULL, NULL));
		reading_buf = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!reading_buf)
			return (create_tmp_or_return(&buffer, NULL, NULL));
		if (ft_strchr(reading_buf, '\n') != NULL)
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
	if (!buffer)
		return (NULL);
	reading_buf = ft_reader(fd, buffer, reading_buf, tmp);
	if (!reading_buf)
		return (NULL);
	ret = ft_last_line(reading_buf);
	reading_buf = ft_rest(reading_buf);
	return (ret);
}
