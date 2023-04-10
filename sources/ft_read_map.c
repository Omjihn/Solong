/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:40:26 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 22:21:36 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_add_space(char *old, int i, int buffer)
{
	char	*res;

	res = (char *) ft_calloc(i + buffer + 1, 1);
	if (!res)
	{
		free (old);
		return (0);
	}
	i = 0;
	while (old[i])
	{
		res[i] = old[i];
		i++;
	}
	free (old);
	return (res);
}

static char	*ft_ber_to_text(char *argv)
{
	int		fd;
	int		i;
	int		buffer;
	char	*res;

	buffer = 42;
	fd = open(argv, O_RDONLY);
	res = (char *) ft_calloc(buffer + 1, 1);
	if (!res)
		return (0);
	i = 0;
	while (read(fd, res + i, buffer) > 0)
	{
		i += buffer;
		res = ft_add_space(res, i, buffer);
		if (!res)
			return (0);
	}
	return (res);
}

char	**ft_read_map(char *argv)
{
	char	**res_map;
	char	*file;

	file = ft_ber_to_text(argv);
	if (!file)
		return (0);
	res_map = ft_split(file, '\n');
	free (file);
	if (!res_map)
		return (0);
	return (res_map);
}
