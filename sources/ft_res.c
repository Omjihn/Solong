/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:47 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/27 18:44:55 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_x_res(char *map)
{
	int		fd;
	int		i;
	char	read_temp[1];

	fd = open(map, O_RDONLY);
	read_temp[0] = 1;
	i = -1;
	while (read_temp[0] != '\n')
	{
		read(fd, read_temp, 1);
		i++;
	}
	close (fd);
	return (i * 64);
}

int	ft_y_res(char *map)
{
	int		fd;
	int		i;
	char	read_temp[1];

	fd = open(map, O_RDONLY);
	i = 0;
	while (read(fd, read_temp, 1) != 0)
	{
		if (*read_temp == '\n')
			i++;
	}
	close(fd);
	return (i * 64);
}
