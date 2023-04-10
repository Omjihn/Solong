/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:38:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 16:50:48 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wich_image(t_vars *vars, t_coords crd)
{
	if (vars->map[crd.y][crd.x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.wall, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.exit, crd.x * 64, crd.y * 64);
		return (1);
	}
	return (0);
}

int	wich_image2(t_vars *vars, t_coords crd)
{
	if (vars->map[crd.y][crd.x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, crd.x * 64, crd.y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.food, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'T')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.enemy, crd.x * 64, crd.y * 64);
		return (1);
	}
	return (0);
}

t_textures	ft_get_textures(void *mlx)
{
	t_textures	textures;
	int		img_res;

	img_res = 64;
	textures.wall = mlx_xpm_file_to_image(mlx,
			"textures/stones-resized.xpm", &img_res, &img_res);
	textures.road = mlx_xpm_file_to_image(mlx,
			"textures/road.xpm", &img_res, &img_res);
	textures.player = mlx_xpm_file_to_image(mlx,
			"textures/player.xpm", &img_res, &img_res);
	textures.exit = mlx_xpm_file_to_image(mlx,
			"textures/portal-resized.xpm", &img_res, &img_res);
	textures.food = mlx_xpm_file_to_image(mlx,
			"textures/heart-resized.xpm", &img_res, &img_res);
	textures.enemy = mlx_xpm_file_to_image(mlx,
			"textures/enemy.xpm", &img_res, &img_res);
	return (textures);
}

void	*ft_render_map(t_vars *vars)
{
	t_coords	coords;
	void		*win;

	vars->img = ft_get_textures(vars->mlx);
	win = mlx_new_window(vars->mlx, vars->win_res->x * 64, 
			vars->win_res->y * 64, "Ungrilled toast");
	vars->win = win;
	coords.x = 0;
	coords.y = 0;
	while (vars->map[coords.y])
	{
		coords.x += wich_image(vars, coords);
		coords.x += wich_image2(vars, coords);
		if (vars->map[coords.y][coords.x] == '\0')
		{
			coords.y += 1;
			coords.x = 0;
		}
	}
	return (win);
}
