/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:05:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/08 18:26:44 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangle(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	if(vars.map[y][x] != '1')
		return (0);
	while (vars.map[y][x] == '1' && x < vars.win_res->x - 1)
	{
		x++;
		ft_printf("actual x: %d - win_rex x :%d", x, vars.win_res->x);
	}
	while (vars.map[y][x] == '1' && y < vars.win_res->y - 1)
		y++;
	while (vars.map[y][x] == '1' && x > 0)
		x--;
	while (vars.map[y][x] == '1' && y > 0)
                y--;
	if (x == 0 && y == 0)
		return (1);
	return (0);
}

int	ft_check_contains(t_vars vars)
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
	while (vars.map[y])
	{
		x = 0;
		while (vars.map[y][x] == '1'|| vars.map[y][x] == '0' ||
				vars.map[y][x] == 'E' || vars.map[y][x] == 'C'
				|| vars.map[y][x] == 'P' || vars.map[y][x] == 'T')
		{
			if (vars.map[y][x] == 'E')
				exit++;
			if (vars.map[y][x] == 'P')
				player++;
			if (vars.map[y][x] == 'C')
				food++;
			x++;
		}
		y++;
	}
	if (exit > 1 || player > 1 || food == 0)
		return (0);
	return (1);
}

void	ft_get_player_coords(t_coords *player, t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars.map[y])
	{
		x = 0;
		while (vars.map[y][x])
		{
			if (vars.map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
			}
			x++;
		}
		y++;
	}
}

int	ft_map_check(t_vars vars)
{
	t_coords	*player;

	if (ft_is_rectangle(vars) == 0) //Marche pas (seg fault)
		return (0);
	if (ft_check_contains(vars) == 0)
		return (0);
	player = (t_coords *) calloc (sizeof(t_coords*), 1);
	ft_get_player_coords(player, vars);
	return (1);
}
