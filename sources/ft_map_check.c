/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 22:24:59 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangle(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (vars->map[y][x] != '1')
		return (0);
	while (vars->map[y][x] == '1' && x < vars->win_res->x)
		x++;
	while (vars->map[y][x] == '1' && y < vars->win_res->y)
		y++;
	while (vars->map[y][x] == '1' && x > 0)
		x--;
	while (vars->map[y][x] == '1' && y > 0)
		y--;
	if (x == 0 && y == 0)
		return (1);
	return (0);
}

int	ft_check_contains(t_vars *vars)
{
	int	x;
	int	y;
	int	player;
	int	exit;
	int	food;

	y = 0;
	player = 0;
	exit = 0;
	food = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
				exit++;
			if (vars->map[y][x] == 'P')
				player++;
			if (vars->map[y][x] == 'C')
				food++;
			x++;
		}
		y++;
	}
	vars->max_c = food;
	if (exit > 1 || player > 1 || food == 0)
		return (1);
	return (0);
}

t_coords	*ft_get_player_coords(t_vars *vars)
{
	t_coords	*player;
	int			y;
	int			x;

	player = (t_coords *) calloc(sizeof(t_coords), 1);
	if (!player)
		return (NULL);
	y = 0;
	while (vars->map[y][0])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

t_coords	*ft_get_win_res(t_vars *vars)
{
	t_coords	*win_res;
	int			y;
	int			x;

	x = 0;
	win_res = (t_coords *) malloc(sizeof(t_coords));
	while (vars->map[0][x])
		x++;
	y = 0;
	while (vars->map[y])
		y++;
	win_res->x = x;
	win_res->y = y;
	vars->win_res = win_res;
	return (win_res);
}

int	ft_map_check(t_vars *vars)
{
	vars->player = ft_get_player_coords(vars);
	if (!vars->player)
		return (0); // error
	vars->win_res = ft_get_win_res(vars);
	if (!vars->win_res)
		return (0); // need error
	if (ft_is_rectangle(vars) == 1)
		printf("ft_is_regtangle : Error map incorrect\n"); // need error
	if (ft_check_contains(vars) == 1)
		printf("ft_check_contains : Error map incorrect\n"); // need error
	return (1);
}
