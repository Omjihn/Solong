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

void	ft_img_to_window(t_textures *textures, t_vars vars, const char *map)
{
	int	fd;
	int	x;
	int	y;
	char	read_temp[1];

	fd = open(map, O_RDONLY);
	x = 0;
	y = 0;
	while (read(fd, read_temp, 1) == 1)
	{
		if (*read_temp == '1')
		{
			mlx_put_image_to_window(vars.mlx, vars.win,
					textures->wall, x, y);
			x += 64;
		}
		else if (*read_temp == '0')
		{
			mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->road, x, y);
                        x += 64;
		}
		else if (*read_temp == 'E')
                {
                        mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->exit, x, y);
                        x += 64;
                }
		else if (*read_temp == 'P')
                {
			mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->road, x, y);
                        mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->player, x, y);
                        x += 64;
                }
		else if (*read_temp == 'C')
                {
			mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->road, x, y);
                        mlx_put_image_to_window(vars.mlx, vars.win,
                                        textures->food, x, y);
                        x += 64;
                }
		else
		{
			y += 64;
			x = 0;
		}		
	}
	close (fd);
}
			

int	ft_get_images(t_textures *textures, void* mlx)
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
	return (1);
}

int	ft_read_map(t_vars vars, const char *map)
{
	t_textures	*textures;

	textures = (t_textures*) ft_calloc(sizeof(t_textures), 1);
	if (!textures)
		return (0);
	if (ft_get_images(textures, vars.mlx) == 0)
		return (0);
	ft_img_to_window(textures, vars, map);
	return (1);
}
