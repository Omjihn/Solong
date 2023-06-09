/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:05:24 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/20 13:11:56 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wich_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_free_all(vars);
	if (keycode == 119 || keycode == 65362)
		ft_player_move(vars, -1, 0);
	if (keycode == 97 || keycode == 65361)
		ft_player_move(vars, 0, -1);
	if (keycode == 115 || keycode == 65364)
		ft_player_move(vars, 1, 0);
	if (keycode == 100 || keycode == 65363)
		ft_player_move(vars, 0, 1);
	return (42);
}
