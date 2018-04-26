/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:24:16 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:33:34 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include "libft/libft.h"

static void	ft_movex(t_tetriminos t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		t[i].x = t[i].x + 1;
		i++;
	}
}

static void	ft_movey(t_tetriminos t)
{
	int i;

	ft_resetx(t);
	i = 0;
	while (i < 4)
	{
		t[i].y = t[i].y + 1;
		i++;
	}
}

int			ft_move(t_tetriminos t, int min_size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		if (t[i].x + 1 >= min_size)
		{
			j++;
			i = 0;
			while (i < 4)
			{
				if (t[i].y + 1 >= min_size)
					return (0);
				i++;
			}
		}
		i++;
	}
	if (j > 0)
		ft_movey(t);
	else
		ft_movex(t);
	return (1);
}
