/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:33 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/20 14:21:10 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_moves_counter(t_vars *vars)
{
	char	*moves;

	vars->moves++;
	moves = ft_itoaa(vars->moves);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->frame, (vars->win_res->x * 64) / 2 - 92, 4);
	mlx_string_put(vars->mlx, vars->win, (vars->win_res->x * 64) / 2 - 70,
		35, 0, "Total moves :");
	mlx_string_put(vars->mlx, vars->win, (vars->win_res->x * 64) / 2 + 20,
		35, 0, moves);
	free (moves);
}

void	ft_player_move(t_vars *vars, int y, int x)
{
	if (vars->map[vars->player->y + y][vars->player->x + x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->player, (vars->player->x + x) * 64,
			(vars->player->y + y) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->road, vars->player->x * 64,
			(vars->player->y) * 64);
		ft_moves_counter(vars);
		ft_logical_verif(vars, y, x);
		vars->player->y += y;
		vars->player->x += x;
	}
}

void	ft_logical_verif(t_vars *vars, int y, int x)
{
	if (vars->map[vars->player->y + y][vars->player->x + x] == 'E'
			&& vars->current_c == vars->max_c)
	{
		ft_printf("Well done you've saved all you butter friends\n");
		ft_free_all(vars);
	}
	else if (vars->map[vars->player->y][vars->player->x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img->exit_c, vars->player->x * 64,
			(vars->player->y) * 64);
	}
	else if (vars->map[vars->player->y + y][vars->player->x + x] == 'C')
	{
		vars->current_c++;
		vars->map[vars->player->y + y][vars->player->x + x] = '0';
		if (vars->current_c == vars->max_c)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img->exit_o, vars->exit->x * 64,
				vars->exit->y * 64);
		}	
	}
	ft_logical_verif_two(vars, y, x);
}

void	ft_logical_verif_two(t_vars *vars, int y, int x)
{
	if (vars->map[vars->player->y + y][vars->player->x + x] == 'T')
	{
		ft_printf("Game over, you've been toasted\n");
		ft_free_all(vars);
	}
}
