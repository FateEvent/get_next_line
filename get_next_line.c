/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:48:12 by faventur          #+#    #+#             */
/*   Updated: 2022/03/02 18:22:00 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The get_next_line() function returns a line read from a file descriptor.
*/

#include "get_next_line.h"
#define MAX_SIZE 5000

size_t	ft_linelen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\n')
		counter++;
	counter++;
	return (counter);
}

char	*get_next_line(int fd)
{
	int			i;
	static int	bytes_to_read;
	int			bytes_lus;
	static char	buffer[BUFFER_SIZE + 1];
	char		*reading_buf;

	if (fd)
	{
		/*
		if (bytes_to_read == BUFFER_SIZE || !(buffer[0]))
			bytes_read = read(fd, &buffer, MAX_SIZE);
		*/
		/*
		while (bytes_read = read(fd, &buffer, BUFFER_SIZE))
			buffer[bytes_read] = '\0';
		*/
		bytes_lus = read(fd, &buffer, BEAUCOUP);
		buffer[bytes_lus] = '\0';
		bytes_to_read = ft_linelen(buffer);
		reading_buf = malloc(sizeof(char) * (bytes_to_read + 1));
		while (*buffer != '\n' || *buffer != '\0')
			reading_buf[i++] = *(buffer)++;
		if (*buffer == '\n')
			reading_buf[i++] = '\n';
		
		reading_buf = '\0';
		return (reading_buf);
	}
}
		bytes_lus = read(fd, &buffer, BEAUCOUP);
		{
				buffer[bytes_lus] = '\0';
			bytes_to_read = ft_linelen(buffer);
			reading_buf = malloc(sizeof(char) * (bytes_to_read + 1));
			while (*buffer != '\n' || *buffer != '\0')
				reading_buf[i++] = *(buffer)++;
			if (*buffer == '\n')
				reading_buf[i++] = '\n';
		}
		
		reading_buf = '\0';
		return (reading_buf);



ft_stocker()
{
	while 
}

void	ft_line_reader(char *buffer, int fd)
{
	int	bytes_read;
	int	i;
	int	j;

	i = 1;
	j = 0;
	(void) argv;
	while ()
	{
		bytes_read = read(fd, &buffer[j], MAX_SIZE - j);
		if (bytes_read == -1)
			return ;
		close(fd);
		buffer[bytes_read + j] = '\0';
		while (buffer[j] != '\0')
			j++;
	}
	i++;
}
