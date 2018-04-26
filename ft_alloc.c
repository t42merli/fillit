/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:26:17 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:26:46 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

t_tetriminos	*ft_alloc(int size)
{
	t_tetriminos	*tetriminos;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!(tetriminos = (t_tetriminos*)malloc(sizeof(t_tetriminos) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(tetriminos[i] = (t_tetriminos)malloc(sizeof(t_point) * 4)))
			return (NULL);
		while (j < 4)
		{
			tetriminos[i][j].x = -1;
			tetriminos[i][j].y = -1;
			j++;
		}
		j = 0;
		i++;
	}
	tetriminos[i] = NULL;
	return (tetriminos);
}
