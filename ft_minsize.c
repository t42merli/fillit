/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:32:44 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:41:45 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		ft_minsize(int nb_tetriminos, t_tetriminos *t)
{
	int i;
	int size;
	int j;

	i = 0;
	j = 0;
	while (i * i < 4 * nb_tetriminos)
		i++;
	if (i < 4)
	{
		while (t[j])
		{
			size = 0;
			while (size < 4)
			{
				if (t[j][size].x > i - 1)
					return (t[j][size].x + 1);
				else if (t[j][size].y > i - 1)
					return (t[j][size].y + 1);
				size++;
			}
			j++;
		}
	}
	return (i);
}
