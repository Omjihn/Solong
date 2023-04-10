/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:33 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 21:36:10 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move_up(t_vars *vars)
{
	ft_printf("%d - %d\n", vars->player->y, vars->player->x);
	if (vars->map[vars->player->y - 1][vars->player->x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, vars->player->x * 64,
			(vars->player->y - 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, vars->player->x * 64,
			(vars->player->y) * 64);
		vars->player->y--;
		ft_printf("Number of moves :%d\n", ++vars->moves);
	}
}

void	ft_player_move_right(t_vars *vars)
{
	ft_printf("%d - %d\n", vars->player->y, vars->player->x);
	if (vars->map[vars->player->y][vars->player->x - 1] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, (vars->player->x - 1) * 64,
			(vars->player->y) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, vars->player->x * 64,
			(vars->player->y) * 64);
		vars->player->x--;
		ft_printf("Number of moves :%d\n", ++vars->moves);
	}
}

void	ft_player_move_down(t_vars *vars)
{
	ft_printf("%d - %d\n", vars->player->y, vars->player->x);
	if (vars->map[vars->player->y + 1][vars->player->x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, vars->player->x * 64,
			(vars->player->y + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, vars->player->x * 64,
			(vars->player->y) * 64);
		vars->player->y++;
		ft_printf("Number of moves :%d\n", ++vars->moves);
	}
}

void	ft_player_move_left(t_vars *vars)
{
	ft_printf("%d - %d\n", vars->player->y, vars->player->x);
	if (vars->map[vars->player->y][vars->player->x + 1] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, (vars->player->x + 1) * 64,
			(vars->player->y) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, vars->player->x * 64,
			(vars->player->y) * 64);
		vars->player->x++;
		ft_printf("Number of moves :%d\n", ++vars->moves);
	}
}
