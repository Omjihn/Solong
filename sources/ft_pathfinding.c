/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:27:16 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/20 13:05:49 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_run_through(t_path *path, int y, int x)
{
	if (path->map[y][x] == '1')
		return ;
	if (path->map[y][x] == '0')
		path->map[y][x] = '1';
	if (path->map[y][x] == 'C')
	{
		path->c++;
		path->map[y][x] = '1';
	}
	if (path->map[y][x] == 'E')
	{
		path->exit++;
		path->map[y][x] = '1';
	}
	ft_run_through(path, y - 1, x);
	ft_run_through(path, y, x - 1);
	ft_run_through(path, y + 1, x);
	ft_run_through(path, y, x + 1);
}

void	ft_lines_lenght(t_vars *vars)
{
	int	lenght;
	int	tab;
	int	len;

	lenght = 0;
	tab = 1;
	while (vars->map[0][lenght])
		lenght++;
	while (vars->map[tab])
	{
		len = 0;
		while (vars->map[tab][len])
			len++;
		if (len != lenght)
		{
			ft_printf("Error map incorrect\n");
			ft_free_all(vars);
		}
		tab++;
	}
}

void	ft_pathfinding(t_vars *vars)
{
	vars->path->c = 0;
	vars->path->exit = 0;
	ft_run_through(vars->path, vars->player->y, vars->player->x);
	if (vars->path->c != vars->max_c || vars->path->exit != 1)
	{
		ft_printf("Error map incorrect\n");
		ft_free_all(vars);
	}
}
