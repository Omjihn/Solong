/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:39:20 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/25 18:39:43 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp;
	int		tmp_res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp_res = nmemb * size;
	if (tmp_res / size != nmemb)
		return (NULL);
	ptr = malloc(tmp_res);
	if (ptr == NULL)
		return (ptr);
	tmp = ptr;
	while (*tmp)
	{
		*tmp = '\0';
		tmp++;
	}
	return (ptr);
}
