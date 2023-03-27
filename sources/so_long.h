/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:22:59 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/25 12:25:12 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../Printf/ft_printf.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_textures
{
	void	*wall;
	void	*road;
	void	*player;
	void	*food;
	void	*exit;
}			t_textures;

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

int		ft_read_map(t_vars vars, char *map);
int		ft_get_images(t_textures *textures, void *mlx);
int		ft_x_res(char *map);
int		ft_y_res(char *map);
int		wich_image(t_textures *textures, t_vars vars, char read, t_coords crd);
int		wich_image2(t_textures *textures, t_vars vars, char read, t_coords crd);

void	ft_img_to_window(t_textures *textures, t_vars vars, char *map);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
