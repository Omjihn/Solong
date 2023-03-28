/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:48:37 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/28 18:34:10 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_textures	textures;
	char	**map;
	int	i;

	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_x_res(argv[1]),
			ft_y_res(argv[1]), "So long Bowser !");
	textures = ft_get_images(vars.mlx);
	map = ft_read_map(vars, textures, argv[1]);
	i = 0;
//	ft_printf("%s", map[1]);
//	while (map[i])
//	{
//		ft_printf("%s", map[i]);
//		i++;
//	}
	mlx_loop(vars.mlx);
	return (0);
}
