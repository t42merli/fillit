/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:34:06 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/02 20:32:40 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetriminos.h"

static int		ft_smallest_x(char *s)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			x = i % 5;
			while (s[i])
			{
				if (s[i] == '#' && i % 5 < x)
					x = i % 5;
				i++;
			}
		}
		i++;
	}
	return (x);
}

static int		ft_smallest_y(char *s)
{
	int i;

	i = 0;
	while (s[i] != '#')
		i++;
	return (i / 5);
}

static void		ft_fill(t_tetriminos t, char *s)
{
	int i;
	int j;
	int y;
	int x;

	x = ft_smallest_x(s);
	y = ft_smallest_y(s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			t[j].x = i % 5 - x;
			t[j].y = i / 5 - y;
			j++;
		}
		i++;
	}
}

t_tetriminos	*ft_gettetriminos(char **tab, int size)
{
	int				i;
	int				j;
	t_tetriminos	*tetriminos;

	if (!(tetriminos = ft_alloc(size)))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		ft_fill(tetriminos[j], tab[i]);
		i++;
		j++;
	}
	return (tetriminos);
}
