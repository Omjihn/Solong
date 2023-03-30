/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:48:37 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/29 19:05:51 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	ft_free_all(t_vars vars)
{
	int	i;

	i = 0;
	while (vars.map[i])
	{
		free(vars.map[i]);
		i++;
	}
	free (vars.map);
	mlx_destroy_image(vars.mlx, vars.textures.road);
	mlx_destroy_window(vars.mlx, vars.win);
*/

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_x_res(argv[1]),
			ft_y_res(argv[1]), "So long Bowser !");
	vars.textures = ft_get_images(vars.mlx);
//	vars.map = ft_read_map(vars, argv[1]);
//	mlx_destroy_image(vars.mlx, vars.textures.road);
//	mlx_hook (vars.win, 2, 1L<<5, fr_free_all, &vars);
	mlx_loop(vars.mlx);
}
