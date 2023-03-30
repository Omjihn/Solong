/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:22:59 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/29 18:40:59 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../Printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_textures
{
	void	*wall;
	void	*road;
	void	*player;
	void	*food;
	void	*enemy;
	void	*exit;
}			t_textures;

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	t_textures	textures;
	t_coords	coords;
}			t_vars;

int		ft_x_res(char *map);
int		ft_y_res(char *map);
int		wich_image(t_textures textures, t_vars vars, char read, t_coords crd);
int		wich_image2(t_textures textures, t_vars vars, char read, t_coords crd);

char	**ft_read_map(t_vars vars, char *map);

void	ft_img_to_window(t_textures textures, t_vars vars, char *map);

t_textures	ft_get_images(void *mlx);

#endif
