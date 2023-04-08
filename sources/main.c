/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:06:25 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/08 19:19:12 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_error(int argc, char **argv)
{
	int	fd;
	int	i;
	char	temp[1];
	char	*verif;

	if (argc >= 3)
		return (ft_printf("Wowowow only one map please\n"));
	else if (argc <= 1)
		return (ft_printf("Error please enter a map :   )\n"));
	else
	{
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
}

void	ft_quit(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free (vars->map); //leaks...
	if (vars->mlx)
	{
		mlx_clear_window(vars->mlx, vars->win);
        	mlx_destroy_window(vars->mlx, vars->win);
	}
}

int	wich_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_quit(vars);
	if (keycode == 119 || keycode == 65362) // w and up 
		ft_player_move(*vars, vars->player.y, vars->player.x + 1);
	if (keycode == 97 || keycode == 65361) // a and left

	if (keycode == 115 || keycode == 65364) // s and down

	if (keycode == 100 || keycode == 65363) // d and right
	ft_printf("%d\n", keycode);
	return (0);
}

int	ft_sayhello(t_vars *vars)
{
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (ft_error(argc, argv) > 0)
		return (0);
	vars.map = ft_read_map(argv[1]);
	if (!vars.map)
		return (0);
	if (ft_map_check(vars) == 0)
		return (ft_quit(&vars), ft_printf("Error\nMap incorrect\n"));
	vars.mlx = mlx_init();
	vars.win = ft_render_map(vars);
	mlx_loop_hook(vars.mlx, &ft_sayhello, &vars);
	mlx_hook(vars.win, 2, 1L<<0, wich_key, &vars);
	mlx_key_hook(vars.win, wich_key, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free (vars.mlx);
	return (0);
}
