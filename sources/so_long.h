/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:28:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/09 17:44:22 by gbricot          ###   ########.fr       */
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
	int	y;
	int	x;
}			t_coords;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int	moves;
	t_textures	img;
	t_coords	*player;
	t_coords	*win_res;
}			t_vars;

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char **ft_read_map(char *map);
char **ft_split(char const*s, char c);

t_coords	*ft_get_win_res(t_vars *vars);
t_coords	*ft_get_player_coords(t_vars *vars);

int     ft_every_frames(t_vars *vars);
int     ft_wich_key(int keycode, t_vars *vars);
int		ft_map_check(t_vars *vars);

void    ft_player_move_up(t_vars *vars);
void    ft_player_move_right(t_vars *vars);
void    ft_player_move_down(t_vars *vars);
void    ft_player_move_left(t_vars *vars);
void	*ft_render_map(t_vars *vars);

#endif
