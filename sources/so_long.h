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
#define SO_LONG_H

#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../Printf/ft_printf.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct	s_textures
{
	void	*wall;
	void	*road;
	void	*player;
	void	*food;
	void	*exit;
}			t_textures;

int		ft_read_map(t_vars vars, const char *map);
int		ft_get_images(t_textures *textures, void* mlx);
int		ft_x_res(const char *map);
int		ft_y_res(const char *map);

void	ft_img_to_window(t_textures *textures, t_vars vars, const char *map);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
