/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:40 by faventur          #+#    #+#             */
/*   Updated: 2022/03/01 16:14:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	operand_checker(char *argument)
{
	if (ft_strlen(argument) == 1 && argument[0] == '>')
		return (1);
	else if (ft_strlen(argument) == 2 && argument[0] == '>'
		&& argument[0] == '>')
		return (2);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

void	ft_err_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_err_putchar(str[i]);
		i++;
	}
}

void	ft_err_putchar(char c)
{
	write(2, &c, 1);
}
