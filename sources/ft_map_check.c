/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/20 14:06:12 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_rectangle(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[y][x] == '1' && x < vars->win_res->x - 1)
		x++;
	while (vars->map[y][x] == '1' && y < vars->win_res->y - 1)
		y++;
	while (vars->map[y][x] == '1' && x > 0)
		x--;
	while (vars->map[y][x] == '1' && y > 0)
		y--;
	if (x != 0 || y != 0)
	{
		ft_printf("Error map incorrect\n");
		ft_free_all(vars);
	}
}

void	ft_check_contains(t_vars *vars, int player, int exit, int food)
{
	int	x;
	int	y;

	y = 0;
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
	{
		ft_printf("Error map incorrect\n");
		ft_free_all(vars);
	}
}

static t_coords	*ft_get_player_coords(t_vars *vars)
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
	free (player);
	return (NULL);
}

static t_coords	*ft_get_win_res(t_vars *vars)
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

void	ft_map_check(t_vars *vars)
{
	vars->player = ft_get_player_coords(vars);
	if (!vars->player)
		ft_free_all(vars);
	vars->win_res = ft_get_win_res(vars);
	if (!vars->win_res)
		ft_free_all(vars);
	ft_is_rectangle(vars);
	ft_lines_lenght(vars);
	ft_check_contains(vars, 0, 0, 0);
	ft_pathfinding(vars);
}
