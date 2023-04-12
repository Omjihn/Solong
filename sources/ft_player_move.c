/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:33 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/12 16:41:13 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move(t_vars *vars, int y, int x)
{
	//ft_printf("%d - %d\n", vars->player->y, vars->player->x); //a retirer
	if (vars->map[vars->player->y + y][vars->player->x + x] != '1')
	{
		vars->moves++;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player, (vars->player->x + x) * 64,
			(vars->player->y + y) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.road, vars->player->x * 64,
			(vars->player->y) * 64);
		ft_logical_verif(vars, y, x);
		vars->player->y += y;
		vars->player->x += x;
		mlx_string_put(vars->mlx, vars->win, 100, 100, 125, "salut");
		ft_printf("Number of moves :%d\n", vars->moves); // a retirer pour le bonus
	}
}

void	ft_logical_verif(t_vars *vars, int y, int x)
{
	if (vars->map[vars->player->y + y][vars->player->x + x] == 'E'
			&& vars->current_c == vars->max_c)
	{
		ft_printf("Bravo\n");
		exit(0);
	}
	else if (vars->map[vars->player->y][vars->player->x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
                        vars->img.exit_c, vars->player->x * 64,
                        (vars->player->y) * 64);
	}
	else if (vars->map[vars->player->y + y][vars->player->x + x] == 'C')
	{
		vars->current_c++;
		vars->map[vars->player->y + y][vars->player->x + x] = '0';
		if (vars->current_c == vars->max_c)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.exit_o, vars->exit->x * 64,
				vars->exit->y * 64);
		}	
	}
}
