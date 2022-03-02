/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/03/01 16:14:56 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# define MAX_SIZE 2900

void	disp_stdin(void);
void	open_and_read(char *buffer, int argc, char *argv[]);
int		operand_checker(char *argument);
size_t	ft_strlen(const char *str);
void	print_enoent(char *pathname);
void	ft_err_putstr(char *str);
void	ft_err_putchar(char c);
void	open_and_write(char *buffer, int argc, char *argv[], int i);
void	open_and_append(char *buffer, int argc, char *argv[], int i);

#endif