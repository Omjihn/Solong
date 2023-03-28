/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:17 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/28 18:30:35 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wich_image(t_textures textures, t_vars vars, char read, t_coords crd)
{
	if (read == '1')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures.wall, crd.x, crd.y);
		return (64);
	}
	else if (read == '0')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures.road, crd.x, crd.y);
		return (64);
	}
	else if (read == 'E')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures.exit, crd.x, crd.y);
		return (64);
	}
	return (0);
}

int	wich_image2(t_textures textures, t_vars vars, char read, t_coords crd)
{
	if (read == 'P')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures.player, crd.x, crd.y);
		return (64);
	}
	else if (read == 'C')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures.food, crd.x, crd.y);
		return (64);
	}
	else if (read == 'T')
        {
                mlx_put_image_to_window(vars.mlx, vars.win,
                        textures.enemy, crd.x, crd.y);
                return (64);
        }

	return (0);
}

void	ft_img_to_window(t_textures textures, t_vars vars, char *map)
{
	int			fd;
	t_coords	coords;
	char		read_temp[1];

	fd = open(map, O_RDONLY);
	coords.x = 0;
	coords.y = 0;
	while (read(fd, read_temp, 1) == 1)
	{
		coords.x += wich_image(textures, vars, *read_temp, coords);
		coords.x += wich_image2(textures, vars, *read_temp, coords);
		if (*read_temp == '\n')
		{
			coords.y += 64;
			coords.x = 0;
		}		
	}
	close (fd);
}

char	**ft_map_split(char *s_map, int tabs)
{
	int	fd;
	int	i;
	char	**res;

	res = (char **) malloc (tabs + 1 * sizeof(char *));
	if (!res)
		return (0);
	fd = open(s_map, O_RDONLY);
	i = 0;
	res[i] = get_next_line(fd);
	i++;
	while (i < tabs)
	{
		res[i] = get_next_line(fd);
		i++;
	}
	res[i] = 0;
	close (fd);
	return (0);
}
	

char	**ft_read_map(t_vars vars, t_textures textures, char *s_map)
{
	char	**map;
	char	temp[1];
	int	fd;
	int	tabs;

	fd = open (s_map, O_RDONLY);
	tabs = 0;
	while (read(fd, temp, 1) != 0)
	{
		if (*temp == '\n')
			tabs++;
	}
	close (fd);
	map = ft_map_split(s_map, tabs);
	ft_img_to_window(textures, vars, s_map);
	return (map);
}
