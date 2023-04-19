/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:13:59 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/19 19:21:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free (vars->map[i]);
		i++;
	}
	free(vars->map);
}

static void	ft_free_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->wall);
	mlx_destroy_image(vars->mlx, vars->img->road);
	mlx_destroy_image(vars->mlx, vars->img->player);
	mlx_destroy_image(vars->mlx, vars->img->food);
	mlx_destroy_image(vars->mlx, vars->img->enemy);
	mlx_destroy_image(vars->mlx, vars->img->exit_o);
	mlx_destroy_image(vars->mlx, vars->img->exit_c);
	mlx_destroy_image(vars->mlx, vars->img->frame);
	free (vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

void	ft_free_all(t_vars *vars)
{
	if (vars->map)
		ft_free_map(vars);
	if (vars->img)
		ft_free_img(vars);
	if (vars->exit)
		free(vars->exit);
	if (vars->player)
		free (vars->player);
	if (vars->win_res)
		free (vars->win_res);
	if (vars->mlx)
		free (vars->mlx);
	free (vars);
	exit (42);
}
