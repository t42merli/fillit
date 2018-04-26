/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:52:50 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:44:01 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

static int	ft_available(char *map, t_tetriminos t, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[t[i].y * size + t[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_cpy(char *map, t_tetriminos t, int size, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[t[i].y * size + t[i].x] = c;
		i++;
	}
}

static int	ft_del(char *map, t_tetriminos t, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[t[i].y * size + t[i].x] = '.';
		i++;
	}
	return (1);
}

int			ft_place(t_tetriminos *t, char *map, int i, int min_size)
{
	if (!t[i])
		return (1);
	if (ft_available(map, t[i], min_size))
	{
		ft_cpy(map, t[i], min_size, 'A' + i);
		if (ft_place(t, map, i + 1, min_size))
			return (1);
		else if (ft_del(map, t[i], min_size) && ft_move(t[i], min_size))
		{
			return (ft_place(t, map, i, min_size));
		}
		else
		{
			ft_del(map, t[i], min_size);
			return (ft_reset(t[i]));
		}
	}
	else if (ft_move(t[i], min_size))
		return (ft_place(t, map, i, min_size));
	else
		return (ft_reset(t[i]));
}
