/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:51:17 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/27 19:45:12 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wich_image(t_textures *textures, t_vars vars, char read, t_coords crd)
{
	if (read == '1')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->wall, crd.x, crd.y);
		return (64);
	}
	else if (read == '0')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->road, crd.x, crd.y);
		return (64);
	}
	else if (read == 'E')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->exit, crd.x, crd.y);
		return (64);
	}
	return (0);
}

int	wich_image2(t_textures *textures, t_vars vars, char read, t_coords crd)
{
	if (read == 'P')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->road, crd.x, crd.y);
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->player, crd.x, crd.y);
		return (64);
	}
	else if (read == 'C')
	{
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->road, crd.x, crd.y);
		mlx_put_image_to_window(vars.mlx, vars.win,
			textures->food, crd.x, crd.y);
		return (64);
	}
	return (0);
}

void	ft_img_to_window(t_textures *textures, t_vars vars, char *map)
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

int	ft_get_images(t_textures *textures, void *mlx)
{
	int	img_res;

	img_res = 64;
	textures->wall = mlx_xpm_file_to_image(mlx,
			"textures/stones-resized.xpm", &img_res, &img_res);
	textures->road = mlx_xpm_file_to_image(mlx,
			"textures/wood-resized.xpm", &img_res, &img_res);
	textures->player = mlx_xpm_file_to_image(mlx,
			"textures/bread-resized.xpm", &img_res, &img_res);
	textures->exit = mlx_xpm_file_to_image(mlx,
			"textures/portal-resized.xpm", &img_res, &img_res);
	textures->food = mlx_xpm_file_to_image(mlx,
			"textures/heart-resized.xpm", &img_res, &img_res);
	if (!textures->wall || !textures->road || !textures->player
		|| !textures->exit || !textures->food)
		return (0);
	return (1);
}

int	ft_read_map(t_vars vars, char *map)
{
	t_textures	*textures;

	textures = (t_textures *) ft_calloc(sizeof(t_textures), 1);
	if (!textures)
		return (0);
	if (ft_get_images(textures, vars.mlx) == 0)
		return (0);
	ft_img_to_window(textures, vars, map);
	return (1);
}
