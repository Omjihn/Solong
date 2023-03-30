/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:22:53 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/28 18:13:18 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	ft_get_images(void *mlx)
{
	t_textures	textures;
	int	img_res;

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
