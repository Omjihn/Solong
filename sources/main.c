/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:06:25 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/30 21:57:13 by gbricot          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	int	i;
	char	**str;

	if (ft_error(argc, argv) > 0)
		return (0);
	vars.map = ft_gnl_map(vars, argv[1]);
	if (!vars.map)
		return (0);
	i = 0;
	while (vars.map[i])
	{
		ft_printf("%s\n", vars.map[i]);
		i++;
	}
	return (0);
}
