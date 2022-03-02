/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:18:01 by faventur          #+#    #+#             */
/*   Updated: 2022/03/02 16:14:09 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	disp_stdin(void)
{
	char	buffer;

	while (read(0, &buffer, 1) != 0)
		write(1, &buffer, 1);
}

void	open_and_read(char *buffer, int argc, char *argv[])
{
	int	fd;
	int	bytes_read;
	int	i;
	int	j;

	i = 1;
	j = 0;
	(void) argv;
	while (i < argc && !operand_checker(argv[i]))
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_enoent(argv[i]);
		else
		{
			bytes_read = read(fd, &buffer[j], MAX_SIZE);
			if (bytes_read == -1)
				return ;
			close(fd);
			buffer[bytes_read + j] = '\0';
			while (buffer[j] != '\0')
				j++;
		}
		i++;
	}
}

void	print_enoent(char *pathname)
{
	ft_err_putstr("ft_cat: ");
	ft_err_putstr(pathname);
	ft_err_putstr(": ");
	ft_err_putstr(strerror(ENOENT));
	ft_err_putchar('\n');
}

void	open_and_write(char *buffer, int argc, char *argv[], int i)
{
	int	fd;
	int	bytes_written;

	(void) argc;
	(void) argv;
	fd = open(argv[i + 1], O_WRONLY | O_CREAT);
	if (fd == -1)
		return ;
	bytes_written = write(fd, buffer, ft_strlen(buffer));
	if (bytes_written == -1)
		return ;
	close(fd);
}

void	open_and_append(char *buffer, int argc, char *argv[], int i)
{
	int	fd;
	int	added_bytes;

	(void) argc;
	(void) argv;
	fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_APPEND);
	if (fd == -1)
		return ;
	added_bytes = write(fd, buffer, ft_strlen(buffer));
	if (added_bytes == -1)
		return ;
	close(fd);
}
