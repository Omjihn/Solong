/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:09:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/31 14:15:13 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef	struct	s_textures
{
	void	*wall;
	void	*road;
	void	*player;
	void	*food;
	void	*enemy;
	void	*exit;
}			t_textures;

typedef	struct	s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	t_textures	img;
	t_coords	*win_res;
	t_coords	player;
}			t_vars;

int		ft_is_rectangle(t_vars vars);
int		ft_check_contains(t_vars vars);
int		ft_map_check(t_vars vars);
int		wich_image(t_vars vars, t_coords crd);
int		wich_image2(t_vars vars, t_coords crd);
int		wich_key(int keycode, t_vars *vars);

void    ft_get_player_coords(t_coords *player, t_vars vars);
void	ft_player_move(t_vars vars, int y, int x);
void	ft_quit(t_vars *vars);

void	*ft_render_map(t_vars vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_add_window(t_vars vars);

char	*ft_ber_to_text(char *map);

char	**ft_read_map(char *map);
char	**ft_split(const char *str, char c);

t_textures	ft_get_textures(void *mlx);

#endif
