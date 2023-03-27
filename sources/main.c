/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:48:37 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/27 19:40:51 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_textures	textures;

	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_x_res(argv[1]),
			ft_y_res(argv[1]), "So long Bowser !");
	textures = ft_read_map(vars, argv[1]);
	mlx_loop(vars.mlx);
}
