/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:09:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/30 15:34:49 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Printf/ft_printf.h"

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
	t_coords	player;

}			t_vars;

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_ber_to_text(char *map);

char	**ft_gnl_map(t_vars, char *map);
char	**ft_split(const char *str, char c);

#endif
