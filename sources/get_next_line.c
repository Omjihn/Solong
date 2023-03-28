/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:53:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/17 17:36:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init(int fd)
{
	char	*trash;

	trash = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	if (!trash)
		return (trash);
	if (read(fd, trash, BUFFER_SIZE) <= 0)
	{
		free (trash);
		return (0);
	}
	return (trash);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*trash;
	char		*res;

	i = 0;
	if (!trash)
		trash = ft_init(fd);
	while (trash)
	{
		if (trash[i] == '\n')
		{
			res = output_res(trash, i);
			if (trash)
				trash = trim_trash(trash, i);
			return (res);
		}
		else if (trash[i] == '\0')
			trash = add_to_trash(trash, fd, i);
		else
			i++;
	}
	return (0);
}
