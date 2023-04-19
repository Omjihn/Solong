/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:33 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/19 16:53:43 by gbricot          ###   ########.fr       */
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
	mlx_string_put(vars->mlx, vars->win, (vars->win_res->x * 64)
				/ 2 - 70, 35, 0, "Total moves :");
	mlx_string_put(vars->mlx, vars->win, (vars->win_res->x * 64)
				/ 2 + 20 , 35, 0, moves);
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
		//ft_enemy(vars, y, x);
		//ft_counter();
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
		ft_printf("Bravo\n");
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
}

/*
void	ft_enemy(t_vars *vars, int y, int x)
{
	if (vars->map[vars->player->y + y][vars->player->x + x] == 'T')
	{
		
	}
}

void	ft_put_string(t_vars *vars)
{
*/
