/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:45 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/18 21:24:51 by gbricot          ###   ########.fr       */
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
		ft_free_all(vars);
	ft_map_check(vars);
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
	if (!vars->win)
		ft_free_all(vars);
	mlx_loop_hook(vars->mlx, &ft_every_frames, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_button, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_loop(vars->mlx);
	return (0);
}
