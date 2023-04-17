/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:38:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/11 17:33:29 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wich_image(t_vars *vars, t_coords crd)
{
	if (vars->map[crd.y][crd.x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->wall, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->road, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->food, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'T')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->enemy, crd.x * 64, crd.y * 64);
		return (1);
	}
	return (0);
}

int	wich_image2(t_vars *vars, t_coords crd)
{
	t_coords	*exit;
	int			y;
	int			x;

	y = crd.y;
	x = crd.x;
	if (vars->map[crd.y][crd.x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->player, crd.x * 64, crd.y * 64);
		return (1);
	}
	else if (vars->map[crd.y][crd.x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->exit_c, crd.x * 64, crd.y * 64);
		exit = (t_coords *) malloc (sizeof(t_coords));
		exit->y = y;
		exit->x = x;
		vars->exit = exit;
		return (1);
	}
	return (0);
}

void	ft_get_textures(t_vars *vars)
{
	t_textures	*textures;
	int			img_res;

	textures = (t_textures *) malloc (sizeof(t_textures));
	img_res = 64;
	textures->wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/wall.xpm", &img_res, &img_res);
	textures->road = mlx_xpm_file_to_image(vars->mlx,
			"textures/road.xpm", &img_res, &img_res);
	textures->player = mlx_xpm_file_to_image(vars->mlx,
			"textures/player.xpm", &img_res, &img_res);
	textures->exit_c = mlx_xpm_file_to_image(vars->mlx,
			"textures/exit_close.xpm", &img_res, &img_res);
	textures->exit_o = mlx_xpm_file_to_image(vars->mlx,
			"textures/exit_open.xpm", &img_res, &img_res);
	textures->food = mlx_xpm_file_to_image(vars->mlx,
			"textures/butter.xpm", &img_res, &img_res);
	textures->enemy = mlx_xpm_file_to_image(vars->mlx,
			"textures/enemy.xpm", &img_res, &img_res);
	vars->img = textures;
}

void	*ft_render_map(t_vars *vars)
{
	t_coords	coords;
	void		*win;

	ft_get_textures(vars);
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
