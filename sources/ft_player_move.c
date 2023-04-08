/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:57:55 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/08 21:02:59 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move(t_vars vars, int y, int x)
{
	ft_printf("%d - %d", vars.player.x / 64, vars.player.y / 64);
//	if (vars.player.x < x)
//	{
//		if (vars.map[vars.player.y][x] != '1')
//		{
//			mlx_put_image_to_window(vars.mlx, vars.win,
//			vars.img.player, x * 64, vars.player.y * 64);
//			mlx_put_image_to_window(vars.mlx, vars.win,
//			vars.img.road, x - 1 * 64, vars.player.y * 64);
//		}
//	}
}
