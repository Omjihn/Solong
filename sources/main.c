/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:45 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/12 21:31:24 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_error(char **argv)
{
	int		fd;
	int		i;
	char	temp[1];
	char	*verif;

	fd = open(argv[1], O_RDONLY);
	if (read(fd, temp, 1) <= 0)
		return (ft_printf("Error while opening the file\n"));
	i = 0;
	while (argv[1][i])
		i++;
	i -= 4;
	verif = ".ber";
	while (argv[1][i] == *verif)
	{
		i++;
		verif++;
	}
	if (*verif == '\0')
		return (0);
	return (ft_printf("Error the map must be a '.ber' file :/\n"));
}

void	ft_free_all(t_vars *vars)
{
	int	i;

	mlx_destroy_image(vars->mlx, vars->img->wall);
	mlx_destroy_image(vars->mlx, vars->img->road);
	mlx_destroy_image(vars->mlx, vars->img->player);
	mlx_destroy_image(vars->mlx, vars->img->food);
	mlx_destroy_image(vars->mlx, vars->img->enemy);
	mlx_destroy_image(vars->mlx, vars->img->exit_o);
	mlx_destroy_image(vars->mlx, vars->img->exit_c);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	i = 0;
	while (vars->map[i])
		free (vars->map[i++]);
	free (vars->map);
	free (vars->player);
	free (vars->exit);
	free (vars->mlx);
	free (vars->win_res);
	free (vars->img);
	free (vars);
	exit(0);
}

static t_vars	*ft_init(int argc, char **argv)
{
	t_vars	*vars;

	if (argc >= 3)
	{
		ft_printf("Wowowow only one map please\n");
		exit(0);
	}
	else if (argc <= 1)
	{
		ft_printf("Error please enter a map :   )\n");
		exit (0);
	}
	if (ft_error(argv) > 0)
		exit(0);
	vars = (t_vars *) calloc (sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->current_c = 0;
	vars->map = ft_read_map(argv[1]);
	if (!vars->map)
		return (NULL);
	if (ft_map_check(vars) == 0)
		return (NULL);
	return (vars);
}

static int	ft_close_button(t_vars *vars)
{
	ft_free_all(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = ft_init(argc, argv);
	vars->mlx = mlx_init();
	vars->win = ft_render_map(vars);
	mlx_loop_hook(vars->mlx, &ft_every_frames, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_loop(vars->mlx);
	ft_free_all(vars);
	mlx_destroy_display(vars->mlx);
	return (0);
}
