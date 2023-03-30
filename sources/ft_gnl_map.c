/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:35:23 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/30 21:49:58 by gbricot          ###   ########.fr       */
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

char	*ft_ber_to_text(char *map)
{
	int	fd;
	int	i;
	int	buffer;
	char	*res;

	buffer = 42;
	fd = open(map, O_RDONLY);
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

char	**ft_gnl_map(t_vars vars, char *map)
{
	char	**res_map;
	char	*file;

	file = ft_ber_to_text(map);
	if (!file)
		return (0);
	res_map = ft_split(file, '\n');
	free (file);
	if (!res_map)
		return (0);
	return (res_map);
}
