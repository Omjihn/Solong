/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:05:24 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/12 16:31:35 by gbricot          ###   ########.fr       */
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
		exit(0); // need ft_quit pour tout free
	if (keycode == 119 || keycode == 65362) // w and up
		ft_player_move(vars, -1, 0);
	if (keycode == 97 || keycode == 65361) // a and left
		ft_player_move(vars, 0, -1);
	if (keycode == 115 || keycode == 65364) // s and down
		ft_player_move(vars, 1, 0);
	if (keycode == 100 || keycode == 65363) // d and right
		ft_player_move(vars, 0, 1);
	//ft_printf("%d\n", keycode);
	ft_printf("vars->max_c %d\nvars->curent_c%d\n", vars->max_c, vars->current_c);
	return (0);
}
