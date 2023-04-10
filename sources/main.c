/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:45 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/10 21:15:52 by gbricot          ###   ########.fr       */
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

static t_vars	*ft_init(int argc, char **argv)
{
	t_vars	*vars;
	int	i = 0; //debug pour test a retirer.

	if (ft_error(argc, argv) > 0)
		return (NULL);
	vars = (t_vars *) calloc (sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->map = ft_read_map(argv[1]);
	if (!vars->map)
		return (NULL);
	while (vars->map[i]) //debug pour test a retirer
		ft_printf("%s\n", vars->map[i++]); //debug pour test a retirer
	if (ft_map_check(vars) == 0)
		return (NULL);
	ft_printf("vars->player->x :%d\nvars->player->y :%d\n", vars->player->x, vars->player->y); // a retirer
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	
	vars = ft_init(argc, argv);
	ft_printf("vars->player->x :%d\nvars->player->y :%d\n", vars->player->x, vars->player->y);
	vars->mlx = mlx_init();
	vars->win = ft_render_map(vars);
	mlx_loop_hook(vars->mlx, &ft_every_frames, vars);
	mlx_hook(vars->win, 2, (1L<<2), ft_wich_key, vars);
	mlx_key_hook(vars->win, ft_wich_key, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_display(vars->mlx);
	// ft_free_all(vars);
	return (0);
}
