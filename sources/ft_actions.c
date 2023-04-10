/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:05:24 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 19:26:24 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_every_frames(t_vars *vars)
{
	if (!vars)
		printf ("player coords y%d x%d\n", vars->player->y, vars->player->y);
	return (0);
}

int	ft_wich_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 119 || keycode == 65362) // w and up
	{
		ft_printf("up");
		ft_player_move_up(vars);
	}
	if (keycode == 97 || keycode == 65361) // a and left
	{
		ft_printf("left");
		ft_player_move_right(vars);
	}
	if (keycode == 115 || keycode == 65364) // s and down
	{
		ft_printf("down");
		ft_player_move_down(vars);
	}
	if (keycode == 100 || keycode == 65363) // d and right
	{
		ft_printf("right");
		ft_player_move_left(vars);
	}
	ft_printf("%d\n", keycode);
	return (0);
}
